#include "camerastreamer.h"

CameraStreamer::CameraStreamer(QObject *parent)
{
    m_cropImage = false;
    m_cropWidth = 640;
    m_cropHeight = 480;
}

void CameraStreamer::captureImages()
{
    if(!initStreamer())
        qDebug() << "Error initializating Gstreamer";
}

void CameraStreamer::stop()
{
    gst_element_set_state (pipeline, GST_STATE_NULL);
    gst_object_unref (pipeline);
}

void CameraStreamer::reset()
{
        qDebug() << "reseting...";


        gst_element_set_state (pipeline, GST_STATE_NULL);
        gst_object_unref (pipeline);


        if(initStreamer())
            qDebug() << "Gstreamer reseted";
        else
            qDebug() << "Error reseting gstreamer";
}
bool CameraStreamer::initStreamer()
{
    gst_init (NULL, NULL);
    //gst-launch-1.0 -e -v udpsrc port=5001 ! application/x-rtp, encoding-name=JPEG,payload=26 ! rtpjpegdepay ! jpegdec ! autovideosink
    pipeline = gst_pipeline_new("Camera");
    source                  = gst_element_factory_make ("udpsrc",           "rtpsrc");
    depay                   = gst_element_factory_make("rtpjpegdepay",      "depay");
    decoder                 = gst_element_factory_make ("jpegdec",          "videodecoder");
    sink                    = gst_element_factory_make ("appsink",          "video-output");
    if (!pipeline || !source  || !depay || !decoder || !sink ) {
      qDebug() << "One element could not be created. Exiting.\n";
      return false;
    }
    callbacks.eos = NULL;
    callbacks.new_sample = newBufferCallback;
    callbacks.new_preroll = NULL;

    gst_app_sink_set_callbacks((GstAppSink *) sink, &callbacks, this, NULL);
    g_object_set (G_OBJECT(source), "port", 5001, NULL);
    GstCaps *app_caps,*app_encoding;
    app_caps = gst_caps_new_simple("application/x-rtp","payload",G_TYPE_INT,26,"encoding-name",G_TYPE_STRING,"JPEG","interlaced",G_TYPE_STRING,"progressive","format",G_TYPE_STRING,"RGB",NULL);
    g_object_set(G_OBJECT(source),"caps",app_caps,NULL);
    gst_bin_add_many (GST_BIN (pipeline),
                      source, depay,decoder, sink, NULL);
    if (!gst_element_link_many (source, depay,decoder, sink, NULL))
        g_warning ("Main pipeline link Fail...");

    ret = gst_element_set_state (pipeline, GST_STATE_PLAYING);
    if (ret == GST_STATE_CHANGE_FAILURE)
    {
        g_printerr ("Unable to set the pipeline to the playing state.");
        gst_object_unref (pipeline);
        return false;
    }

    return true;
}
void CameraStreamer::emitNewImage(QImage img)
{
    if(img.isNull() == false)
    {
        emit newImage(img);
    }
}


GstFlowReturn CameraStreamer::newBufferCallback(GstAppSink *app_sink, void *obj)
{
    if(app_sink == NULL)
    {
        qDebug() << "app_sink is NULL";
        return GST_FLOW_ERROR;
    }

    GstSample* sample = gst_app_sink_pull_sample(app_sink);

    if(!sample)
    {
        qDebug() << "Error retreiving buffer...";
        // Finished playing.
        return GST_FLOW_ERROR;
    }

    // Get the frame format.
    GstCaps* caps = gst_sample_get_caps (sample);

    if (!caps) {
        qDebug() << "could not get snapshot format\n";
        exit (-1);
    }
    gint width, height;
    GstStructure* s = gst_caps_get_structure (caps, 0);
    int res = gst_structure_get_int (s, "width", &width)
        | gst_structure_get_int (s, "height", &height);
    if (!res) {
        qDebug() << "could not get snapshot dimension\n";
        exit (-1);
    }
    GstMapInfo map;

    GstBuffer *buffer = gst_sample_get_buffer (sample);
    qDebug() << "size: " << gst_buffer_get_size(buffer);
    gst_buffer_map (buffer, &map, GST_MAP_READ);
//

    QImage img(map.data,width,height, QImage::Format_Indexed8);
    qDebug() << "size: " << width << height;
    img = img.copy();

    if(((CameraStreamer*)obj)->m_cropImage)
    {
        int widthToCrop = ((CameraStreamer*)obj)->m_cropWidth, heightToCrop = ((CameraStreamer*)obj)->m_cropHeight;
        QRect areaToCrop(img.size().width()/2 - widthToCrop/2, img.size().height()/2 - heightToCrop/2, widthToCrop, heightToCrop);
        img = img.copy(areaToCrop);
    }

    //img.save("/home/robot/a.jpg");
    ((CameraStreamer*)obj)->emitNewImage(img);

    gst_buffer_unmap (buffer, &map);
    gst_sample_unref (sample);
    return GST_FLOW_OK;

}
