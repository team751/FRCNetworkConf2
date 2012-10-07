
#include <QApplication>
#include "networkstatusicon.h"

int main(int argc, char *argv) {
    QApplication app(argc, &argv, QApplication::GuiClient);
    app.setQuitOnLastWindowClosed(false);

    QCoreApplication::setOrganizationName("Team751");
    QCoreApplication::setOrganizationDomain("org.team751");
    QCoreApplication::setApplicationName("NetConf");

    NetworkStatusIcon *nsi = new NetworkStatusIcon(&app);
    nsi->show();

    return app.exec();
}
