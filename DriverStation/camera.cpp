#include "camera.h"
#include "helper.h"
#include <QDebug>
#include <QColor>

Camera::Camera(QObject *parent) : QObject(parent)
{
    status = CameraStatus::UNDEFINED;
}

Camera::~Camera()
{
    emit stopCaptureImages();
    delete worker;
}

void Camera::startCapture(std::string ipaddress,uint32_t port)
{

    worker = new CameraStreamer();
   worker->set_stream(ipaddress,port);

    worker->moveToThread(&workerThread);
   QObject::connect(&workerThread, &QThread::finished, worker, &QObject::deleteLater);
    QObject::connect(this, SIGNAL(captureImages()), worker, SLOT(captureImages()));
    QObject::connect(this, SIGNAL(stopCaptureImages()), worker, SLOT(stop()));
    QObject::connect(this, SIGNAL(reset()), worker, SLOT(reset()));
    QObject::connect(worker, SIGNAL(newImage(QImage)), this, SLOT(setNewImage(QImage)));
    QObject::connect(worker,SIGNAL(newGSTImage(guint8*)),this,SLOT(setNewGSTImage(guint8*)));
    workerThread.start();

    connect(&m_timer, SIGNAL(timeout()),this, SLOT(timeOut()));
    emit captureImages();
     m_timer.setInterval(1000);  // 1Hz to check if we are getting frames from the camera...
    m_timer.start();
    m_time.start();
    QImage img("/home/robot/Dropbox/ICARUS/DriverStation/MEDIA/camera_graphics/LostCameraFeed.png");
    emit newFrameReady(img,true);

}

void Camera::timeOut()
{

    if(m_time.elapsed() > 1000)
    {
        QImage img("/home/robot/Dropbox/ICARUS/DriverStation/MEDIA/camera_graphics/LostCameraFeed.png");
        status = CameraStatus::TIMEOUT;
        emit newFrameReady(img,true);
        emit reset();
    }
    else
    {
        status = CameraStatus::AVAILABLE;
    }
    emit camera_status(status);
}
void Camera::setNewGSTImage(guint8 *map)
{
    m_time.restart();
    emit newGSTFrameReady(map,false);
    /*

    */
}
void Camera::setNewImage(QImage img)
{
    m_time.restart();
    emit newFrameReady(img, false);
}
