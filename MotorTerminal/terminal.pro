QT       += core gui serialport charts

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets serialport

CONFIG += c++11
TARGET = terminal
TEMPLATE = app

SOURCES += \
    chartview.cpp \
    main.cpp \
    mainwindow.cpp \
    motorwork.cpp \
    protocol.cpp \
    serialworker.cpp \
    settingsdialog.cpp \
    console.cpp

HEADERS += \
    chartview.h \
    mainwindow.h \
    motorwork.h \
    protocol.h \
    serialworker.h \
    settingsdialog.h \
    console.h

FORMS += \
    chartview.ui \
    mainwindow.ui \
    settingsdialog.ui

RESOURCES += \
    icone.qrc

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target
