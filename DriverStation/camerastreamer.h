#ifndef CAMERASTREAMER_H
#define CAMERASTREAMER_H
#include "cameraworker.h"
#include <gst/app/gstappsink.h>
#include <glib.h>


class CameraStreamer : public CameraWorker
{
    Q_OBJECT
public:
    explicit CameraStreamer(QObject *parent = 0);

public slots:
    virtual void captureImages();
    virtual void stop();
    virtual void reset();
public:
private:

    GstElement *pipeline, *source, *app, *depay,*rtpdepay,*decoder, *videoconvert_1, *identity,*videoconvert_2,*sink;
    GstBus *bus;
    GstMessage *msg;
    GstStateChangeReturn ret;
    guint bus_watch_id;
    GstCaps *caps;
    GstAppSinkCallbacks callbacks;

    static GstFlowReturn newBufferCallback(GstAppSink *app_sink, void *obj);
    static QImage generate_rgbimage(QImage img,int width,int height);

    bool initStreamer();
    void emitNewImage(QImage img);
};
#endif
