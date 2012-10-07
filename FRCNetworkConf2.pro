QT += core gui

SOURCES += \
    main.cpp \
    networkstatusicon.cpp \
    preferencesdialog.cpp

HEADERS += \
    networkstatusicon.h \
    preferencesdialog.h

OTHER_FILES += \
    Info.plist \
    barn2-black.png

RESOURCES += \
    icon.qrc

FORMS += \
    preferencesdialog.ui

QMAKE_INFO_PLIST = Info.plist
