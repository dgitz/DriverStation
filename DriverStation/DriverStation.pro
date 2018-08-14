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
QT +=

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = DriverStation
TEMPLATE = app



CONFIG+=link_pkgconfig
#PKGCONFIG+=Qt5GStreamer-1.0

#INCLUDEPATH += $$QWTPATH/include/Qt5GStreamer
LIBS += -L$$QWTPATH/lib  -lgstreamer-1.0 -lgstapp-1.0 -lglib-2.0 -lgobject-2.0 #-lQt5GStreamer-1.0
INCLUDEPATH += /usr/local/include/opencv2
LIBS += -L/usr/local/lib \
-lopencv_core \
-lopencv_imgproc \
-lopencv_highgui \
-lopencv_ml \
-lopencv_video \
-lopencv_features2d \
-lopencv_calib3d \
-lopencv_objdetect \
-lopencv_contrib \
-lopencv_legacy \
-lopencv_flann \
-lopencv_imgcodecs

INCLUDEPATH += /usr/include/glib-2.0/ \
               /usr/lib/x86_64-linux-gnu/glib-2.0/include/ \
               /usr/include/gstreamer-1.0/ \
               /usr/include/glib-2.0 \
                /home/robot/other_packages/qt-gstreamer-1.2.0/install/include/ \
                /usr/include/c++/4.8/bits/

SOURCES += main.cpp\
        mainwindow.cpp \
    udpreceiver.cpp \
    udptransmitter.cpp \
    tcptransmitter.cpp \
    tcpreceiver.cpp \
    udpmessage.cpp \
    cameraworker.cpp \
    camerastreamer.cpp \
    camera.cpp

HEADERS  += mainwindow.h \
    udptransmitter.h \
    udpreceiver.h \
    tcpreceiver.h \
    tcptransmitter.h \
    udpmessage.h \
    cameraworker.h \
    camerastreamer.h \
    camera.h \
    helper.h

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
    ../../../Dropbox/ICARUS/RoverV2/SOFTWARE/gui/icons/SSI_5.png \
    ../../../Dropbox/ICARUS/RoverV2/SOFTWARE/gui/icons/LostCameraFeed.png

