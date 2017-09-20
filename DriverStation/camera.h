#ifndef CAMERA_H
#define CAMERA_H

#include <QObject>
#include <QImage>
#include <QThread>
#include <QTime>
#include <QTimer>


#include "camerastreamer.h"

//#define USE_OPENCV

#ifdef USE_OPENCV
 #include <opencv2/opencv.hpp>
#endif



/*
 * Uncomment below if you want the camera send always a white image no matter
 * if it is connected or not.
 */
//#define USE_TEST_IMAGE

// uncomment bellow definetion if you want to talk with B-Cam using Gstreamer
#define USE_CAM_GST


class Camera : public QObject
{
    Q_OBJECT
public:
    explicit Camera(QObject *parent = 0);
    ~Camera();


signals:
    void newFrameReady(QImage img, bool error = false);
    void captureImages();
    void stopCaptureImages();
    void reset();

public slots:
    void startCapture();

private:

    QThread workerThread;
    CameraWorker *worker;


    QTimer m_timer;
    QTime m_time;

private slots:
    void timeOut();
    void setNewImage(QImage img);

};


#endif // CAMERA_H
