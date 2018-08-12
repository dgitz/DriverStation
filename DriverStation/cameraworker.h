#ifndef CAMERAWORKER_H
#define CAMERAWORKER_H

#include <QObject>
#include <QImage>
#include <QDebug>
#include <gst/app/gstappsink.h>
#include <glib.h>
class CameraWorker: public QObject
{
    Q_OBJECT
public:
        explicit CameraWorker(QObject * parent = 0);
        void set_stream(std::string ipaddress_,uint32_t port_)
        {
            ipaddress = ipaddress_;
            port = port_;
        }

signals:
        void newImage(QImage img);
        void newGSTImage(guint8 *map);
public slots:
        virtual void captureImages() = 0;
        virtual void stop() = 0;
        virtual void reset() = 0;
protected:
            std::string ipaddress;
            uint32_t port;
};
#endif
