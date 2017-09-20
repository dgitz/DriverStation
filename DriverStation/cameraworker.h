#ifndef CAMERAWORKER_H
#define CAMERAWORKER_H

#include <QObject>
#include <QImage>
#include <QDebug>
class CameraWorker: public QObject
{
    Q_OBJECT
public:
        explicit CameraWorker(QObject * parent = 0);
signals:
        void newImage(QImage img);
public slots:
        virtual void captureImages() = 0;
        virtual void stop() = 0;
        virtual void reset() = 0;
protected:
            bool m_cropImage;
            int m_cropWidth;
            int m_cropHeight;
};
#endif CAMERAWORKER
