#-------------------------------------------------
#
# Project created by QtCreator 2012-07-02T08:59:53
#
#-------------------------------------------------

QT       += core gui svg network


TARGET = ThermostatDemo
TEMPLATE = app

SOURCES += main.cpp \
    weatherwidget.cpp \
    thermostatwidget.cpp \
    optionswidget.cpp \
    webdata.cpp \
    awayscreen.cpp \
    mainwindow.cpp \
    schedulescreen.cpp \
    schedulepoint.cpp \
    openingscreen.cpp \
    keyboard/keyboard.cpp \
    proxysetupdialog.cpp \
    settingscreen.cpp

HEADERS  += \
    weatherwidget.h \
    thermostatwidget.h \
    optionswidget.h \
    webdata.h \
    awayscreen.h \
    mainwindow.h \
    schedulescreen.h \
    schedulepoint.h \
    openingscreen.h \
    keyboard/keyboard.h \
    proxysetupdialog.h \
    settingscreen.h \
    STARTHERE.h

RESOURCES += \
    thermostatdemo.qrc

FORMS += \
    keyboard/keyboard.ui


target.path += /home/root
INSTALLS += target
