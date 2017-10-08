#include "camerastreamer.h"
#include <vector>
#include <stdio.h>
#include <opencv2/opencv.hpp>
#include <opencv2/imgproc.hpp>
#include <opencv2/imgcodecs.hpp>
using namespace cv;
using namespace std;
CameraStreamer::CameraStreamer(QObject *parent)
{
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

        //gst_element_set_state (pipeline, GST_STATE_NULL);
        //gst_object_unref (pipeline);
        if(initStreamer() == false)
        {

        }
}
bool CameraStreamer::initStreamer()
{
    gst_init (NULL, NULL);
    pipeline = gst_pipeline_new("Camera");
    source                  = gst_element_factory_make ("tcpclientsrc",           "cam-source");
    depay                   = gst_element_factory_make("gdpdepay",      "depay");
    rtpdepay                = gst_element_factory_make("rtph264depay","rtp-depay");
    decoder                 = gst_element_factory_make ("avdec_h264",          "videodecoder");
    videoconvert_1            = gst_element_factory_make("videoconvert","video-convert1");
    sink                    = gst_element_factory_make ("appsink",          "video-output");
    if (!pipeline || !source  || !depay || !rtpdepay || !decoder || !videoconvert_1  || !sink ) {
      qDebug() << "One element could not be created. Exiting.\n";
      return false;
    }
    callbacks.eos = NULL;
    callbacks.new_sample = newBufferCallback;
    callbacks.new_preroll = NULL;
    gst_app_sink_set_callbacks((GstAppSink *) sink, &callbacks, this, NULL);
    g_object_set (G_OBJECT(source), "port", port, NULL);
    g_object_set (G_OBJECT(source),"host",ipaddress.c_str(),NULL);
    gst_bin_add_many (GST_BIN (pipeline),
                      source, depay,rtpdepay,decoder, videoconvert_1,sink, NULL);
    if (!gst_element_link_many (source, depay,rtpdepay,decoder, videoconvert_1,sink, NULL))
        g_warning ("Main pipeline link Fail...");
    ret = gst_element_set_state (pipeline, GST_STATE_PLAYING);
    if (ret == GST_STATE_CHANGE_FAILURE)
    {
        //g_printerr ("Unable to set the pipeline to the playing state.");
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
        return GST_FLOW_ERROR;
    }
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
    gst_buffer_map (buffer, &map, GST_MAP_READ);
    cv::Mat temp_mat = cv::Mat(cv::Size(width, height+height/2), CV_8UC1, (char*)map.data);
    cv::Mat result(height,width,3);
    cv::cvtColor(temp_mat,result,CV_YUV2RGB_I420,3);
    QImage *rgb;
    rgb = new QImage(result.size().width, result.size().height, QImage::Format_RGB888);
    memcpy(rgb->scanLine(0), (unsigned char*)result.data, rgb->width() * rgb->height() * result.channels());
    ((CameraStreamer*)obj)->emitNewImage(*rgb);
    gst_buffer_unmap (buffer, &map);
    gst_sample_unref (sample);
    return GST_FLOW_OK;
}
