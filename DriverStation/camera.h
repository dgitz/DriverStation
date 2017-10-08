#ifndef CAMERA_H
#define CAMERA_H

#include <QObject>
#include <QImage>
#include <QThread>
#include <QTime>
#include <QTimer>
#include "camerastreamer.h"
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
    void startCapture(std::string ipaddress,uint32_t port);
private:
    QThread workerThread;
    CameraWorker *worker;
    QTimer m_timer;
    QTime m_time;
private slots:
    void timeOut();
    void setNewImage(QImage img);

};


#endif
