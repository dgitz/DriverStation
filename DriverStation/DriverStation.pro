#-------------------------------------------------
#
# Project created by QtCreator 2017-03-05T07:08:04
#
#-------------------------------------------------

QT       += core gui
QT += gui
QT += network
QT += charts

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = DriverStation
TEMPLATE = app


SOURCES += main.cpp\
        mainwindow.cpp \
    receiver.cpp \
    transmitter.cpp \
    udpmessage.cpp

HEADERS  += mainwindow.h \
    helper.h \
    receiver.h \
    transmitter.h \
    udpmessage.h

FORMS    += mainwindow.ui

CONFIG += mobility
MOBILITY = 

DISTFILES += \
    DriverStation.pro.user

