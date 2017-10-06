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

void Camera::startCapture()
{
    #ifdef USE_CAM_GST
        worker = new CameraStreamer();
    #endif
    worker->moveToThread(&workerThread);
    QObject::connect(&workerThread, &QThread::finished, worker, &QObject::deleteLater);
    QObject::connect(this, SIGNAL(captureImages()), worker, SLOT(captureImages()));
    QObject::connect(this, SIGNAL(stopCaptureImages()), worker, SLOT(stop()));
    QObject::connect(this, SIGNAL(reset()), worker, SLOT(reset()));
    QObject::connect(worker, SIGNAL(newImage(QImage)), this, SLOT(setNewImage(QImage)));
    workerThread.start();

    connect(&m_timer, SIGNAL(timeout()),this, SLOT(timeOut()));

 #ifdef USE_TEST_IMAGE
    m_timer.setInterval(1.0/24.0*1000); //24 Hz
#else
    emit captureImages();
    m_timer.setInterval(1000);  // 1Hz to check if we are getting frames from the camera...
#endif
    m_timer.start();
    m_time.start();
}

void Camera::timeOut()
{
#ifdef USE_TEST_IMAGE
    QImage img(1280,800, QImage::Format_RGB888);
    img.fill(QColor("white"));
//    QImage img("/home/pf/Downloads/soil.jpg","jpg");

    emit newFrameReady(img, false);
#else

    if(m_time.elapsed() > 1000)
    {
        QImage img("/home/robot/Dropbox/ICARUS/RoverV2/SOFTWARE/gui/icons/LostCameraFeed.png");
        emit newFrameReady(img,true);
       // emit reset();
    }

#endif
}

void Camera::setNewImage(QImage img)
{
    m_time.restart();
    emit newFrameReady(img/*.mirrored(true,false)*/, false);
}
