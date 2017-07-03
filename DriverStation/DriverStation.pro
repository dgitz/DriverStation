#-------------------------------------------------
#
# Project created by QtCreator 2017-03-05T07:08:04
#
#-------------------------------------------------

QT       += core gui
QT += gui
QT += network
QT += charts
QT += gamepad

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = DriverStation
TEMPLATE = app


SOURCES += main.cpp\
        mainwindow.cpp \
    udpreceiver.cpp \
    udptransmitter.cpp \
    tcptransmitter.cpp \
    tcpreceiver.cpp \
    udpmessage.cpp

HEADERS  += mainwindow.h \
    helper.h \
    udptransmitter.h \
    udpreceiver.h \
    tcpreceiver.h \
    tcptransmitter.h \
    udpmessage.h

FORMS    += mainwindow.ui

CONFIG += mobility
MOBILITY =

DISTFILES += \
    DriverStation.pro.user \
    ../../../Dropbox/ICARUS/RoverV2/SOFTWARE/gui/icons/ROSSERVER_Active.png \
    ../../../Dropbox/ICARUS/RoverV2/SOFTWARE/gui/icons/ROSSERVER_Unactive.png \
    ../../../Dropbox/ICARUS/RoverV2/SOFTWARE/gui/icons/Router_Active.png \
    ../../../Dropbox/ICARUS/RoverV2/SOFTWARE/gui/icons/Router_Unactive.png \
    ../../../Dropbox/ICARUS/RoverV2/SOFTWARE/gui/icons/Rover_Active.png \
    ../../../Dropbox/ICARUS/RoverV2/SOFTWARE/gui/icons/Rover_Unactive.png \
    ../../../Dropbox/ICARUS/RoverV2/SOFTWARE/gui/icons/SSI_0.png \
    ../../../Dropbox/ICARUS/RoverV2/SOFTWARE/gui/icons/SSI_1.png \
    ../../../Dropbox/ICARUS/RoverV2/SOFTWARE/gui/icons/SSI_2.png \
    ../../../Dropbox/ICARUS/RoverV2/SOFTWARE/gui/icons/SSI_3.png \
    ../../../Dropbox/ICARUS/RoverV2/SOFTWARE/gui/icons/SSI_4.png \
    ../../../Dropbox/ICARUS/RoverV2/SOFTWARE/gui/icons/SSI_5.png

