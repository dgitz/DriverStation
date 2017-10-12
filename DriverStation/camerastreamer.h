#ifndef CAMERASTREAMER_H
#define CAMERASTREAMER_H
#include "cameraworker.h"
#include <gst/app/gstappsink.h>
#include <glib.h>
#include <QGst/Init>
#include <QGst/Pipeline>
#include <QGst/ElementFactory>
#include <QGst/Ui/GraphicsVideoSurface>
#include <QGst/Ui/GraphicsVideoWidget>



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

    GstElement *pipeline, *source, *depay,*decoder,*sink,*rtpdepay,*videoconvert;
    //GstBus *bus;
    //GstMessage *msg;
    //GstStateChangeReturn ret;
    //guint bus_watch_id;
    //GstCaps *caps;
    GstAppSinkCallbacks callbacks;

    //QGst::PipelinePtr pipeline;
    //QGst::ElementPtr source,depay,rtpdepay,decoder,videoconvert,sink;
    static GstFlowReturn newBufferCallback(GstAppSink *app_sink, void *obj);
    static QImage generate_rgbimage(QImage img,int width,int height);

    bool initStreamer();
    void emitNewImage(QImage img);
    void emitNewGSTImage(guint8 *map);

};
#endif
