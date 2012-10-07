#include "networkstatusicon.h"
#include "preferencesdialog.h"

const QString NetworkStatusIcon::interfaceName = "Ethernet";

NetworkStatusIcon::NetworkStatusIcon(QApplication *app, QObject *parent) :
    QSystemTrayIcon(parent),
    primaryIcon(":icon/barn2-black")
{
    prefs = new PreferencesDialog();
    prefs->setTeamNumber(QSettings().value("team_number", 0).toInt());

    connect(app, SIGNAL(aboutToQuit()), this, SLOT(savePrefs()));

    setIcon(primaryIcon);

    QAction *quitAction = new QAction("Quit", this);
    QAction *configRoboticsAction = new QAction("Robotics", this);
    QAction *configDefaultAction = new QAction("Default", this);
    QAction *preferencesAction = new QAction("Preferences...", this);

    QMenu *menu = new QMenu();
    menu->insertAction(0, quitAction);
    menu->insertAction(quitAction, preferencesAction);
    QAction *sep = menu->insertSeparator(preferencesAction);
    menu->insertAction(sep, configDefaultAction);
    menu->insertAction(configDefaultAction, configRoboticsAction);


    connect(quitAction, SIGNAL(triggered()), app, SLOT(quit()));
    connect(preferencesAction, SIGNAL(triggered()), prefs, SLOT(show()));
    connect(preferencesAction, SIGNAL(triggered()), prefs, SLOT(raise()));//Connect it to show() and raise() to bring it to the top
    connect(configRoboticsAction, SIGNAL(triggered()), this, SLOT(configRobotics()));
    connect(configDefaultAction, SIGNAL(triggered()), this, SLOT(configDefault()));

    setContextMenu(menu);
}

void NetworkStatusIcon::configRobotics() {
    int teamNumber = prefs->getTeamNumber();

    //xx.yy part of IP address, like "7.51"
    QString teamAddressPart = QString::number(teamNumber / 100) + '.' + QString::number(teamNumber % 100);

    QString localAddress = "10." + teamAddressPart + ".6";
    QString defaultGateway = "10." + teamAddressPart + ".1";

#ifdef Q_OS_MACX
    //Mac OS: use /usr/sbin/networksetup -setmanual Ethernet 10.xx.yy.6 255.255.255.0 10.xx.yy.1
    QStringList args;
    args << "-setmanual" << interfaceName << localAddress << "255.255.255.0" << defaultGateway;

    QProcess *process = new QProcess(this);
    process->start("/usr/sbin/networksetup", args);

    //Hook up the mechanism to remove the process from memory when it's complete
    connect(process, SIGNAL(finished(int)), process, SLOT(deleteLater()));
#endif

#ifdef Q_OS_WIN
    //Windows: use ipconfig?
#endif
}

void NetworkStatusIcon::configDefault() {

#ifdef Q_OS_MACX
    QStringList args;
    args << "-setdhcp" << interfaceName;

    QProcess *process = new QProcess(this);
    process->start("/usr/sbin/networksetup", args);

    //Hook up the mechanism to remove the process from memory when it's complete
    connect(process, SIGNAL(finished(int)), process, SLOT(deleteLater()));
#endif

#ifdef Q_OS_WIN
    //Windows: use ipconfig?
#endif
}

void NetworkStatusIcon::savePrefs() {
    QSettings settings;
    settings.setValue("team_number", prefs->getTeamNumber());
}
