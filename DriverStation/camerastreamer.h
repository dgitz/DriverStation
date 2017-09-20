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
private:

    GstElement *pipeline, *source, *app, *depay,*decoder, *sink;
    GstBus *bus;
    GstMessage *msg;
    GstStateChangeReturn ret;
    guint bus_watch_id;
    GstCaps *caps;


    gint width, height;
    gboolean res;


    GstAppSinkCallbacks callbacks;

    static GstFlowReturn newBufferCallback(GstAppSink *app_sink, void *obj);

    bool initStreamer();
    void emitNewImage(QImage img);
};
#endif
