#ifndef NETWORKSTATUSICON_H
#define NETWORKSTATUSICON_H

#include <QSystemTrayIcon>
#include <QApplication>
#include <QIcon>
#include <QMenu>
#include <QAction>
#include <QProcess>
#include <QSettings>

//Forward-declare classes
class PreferencesDialog;

class NetworkStatusIcon : public QSystemTrayIcon
{
    Q_OBJECT

private slots:

    void configRobotics();

    void configDefault();

    void savePrefs();

protected:

    PreferencesDialog *prefs;

    static const QString interfaceName;

    QIcon primaryIcon;

public:
    explicit NetworkStatusIcon(QApplication *app = 0, QObject *parent = 0);
    
signals:
    
public slots:
    
};

#endif // NETWORKSTATUSICON_H
