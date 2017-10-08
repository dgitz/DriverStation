#include "camera.h"
#include <QDebug>
#include <QColor>

Camera::Camera(QObject *parent) : QObject(parent)
{
}

Camera::~Camera()
{
    emit stopCaptureImages();
    delete worker;
}

void Camera::startCapture(std::string ipaddress,uint32_t port)
{
    #ifdef USE_CAM_GST
        worker = new CameraStreamer();
        worker->set_stream(ipaddress,port);

    #endif
    worker->moveToThread(&workerThread);
    QObject::connect(&workerThread, &QThread::finished, worker, &QObject::deleteLater);
    QObject::connect(this, SIGNAL(captureImages()), worker, SLOT(captureImages()));
    QObject::connect(this, SIGNAL(stopCaptureImages()), worker, SLOT(stop()));
    QObject::connect(this, SIGNAL(reset()), worker, SLOT(reset()));
    QObject::connect(worker, SIGNAL(newImage(QImage)), this, SLOT(setNewImage(QImage)));
    workerThread.start();

    connect(&m_timer, SIGNAL(timeout()),this, SLOT(timeOut()));
    emit captureImages();
    m_timer.setInterval(1000);  // 1Hz to check if we are getting frames from the camera...
    m_timer.start();
    m_time.start();
}

void Camera::timeOut()
{

    if(m_time.elapsed() > 1000)
    {
        QImage img("/home/robot/Dropbox/ICARUS/RoverV2/SOFTWARE/gui/icons/LostCameraFeed.png");
        emit newFrameReady(img,true);
        emit reset();
    }
}

void Camera::setNewImage(QImage img)
{
    m_time.restart();
    emit newFrameReady(img, false);
}
