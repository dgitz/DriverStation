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
    udpreceiver.cpp \
    udptransmitter.cpp \
    udpmessage.cpp \
    tcptransmitter.cpp \
    tcpreceiver.cpp

HEADERS  += mainwindow.h \
    helper.h \
    udptransmitter.h \
    udpmessage.h \
    udpreceiver.h \
    tcpreceiver.h \
    tcptransmitter.h

FORMS    += mainwindow.ui

CONFIG += mobility
MOBILITY = 

DISTFILES += \
    DriverStation.pro.user

