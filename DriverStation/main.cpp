#include "mainwindow.h"
#include <QApplication>
#include <QtCharts/QChartView>
#include <QDesktopWidget>


/*
class Player : public QCoreApplication
{
public:
    Player(int argc, char **argv);
    ~Player();

private:
    void onBusMessage(const QGst::MessagePtr & message);

private:
    QGst::PipelinePtr pipeline1;
};

Player::Player(int argc, char **argv)
    : VideoWidget(argc, argv)
{
    QGst::init(&argc, &argv);
Need to implement this string as a string
 gst-launch -v udpsrc port=8888 caps='application/x-rtp, media=(string)video, clock-rate=(int)90000, encoding-name=(string)H264' ! rtph264depay ! ffdec_h264 ! xvimagesink sync=false



    const char *caps = "application/x-rtp, encoding-name=JPEG,payload=26";


    QString pipe1Descr = QString("udpsrc port=5001 ! %1 ! rtpjpegdepay ! "
                                 "jpegdec ! "
                                 "autovideosink").arg(caps);
    pipeline1 = QGst::Parse::launch(pipe1Descr).dynamicCast<QGst::Pipeline>();
    QGlib::connect(pipeline1->bus(), "message::error", this, &Player::onBusMessage);
    pipeline1->bus()->addSignalWatch();

    pipeline1->setState(QGst::StatePlaying);
}

Player::~Player()
{
    pipeline1->setState(QGst::StateNull);
}

void Player::onBusMessage(const QGst::MessagePtr & message)
{
    switch (message->type()) {
    case QGst::MessageEos:
        quit();
        break;
    case QGst::MessageError:
        qCritical() << message.staticCast<QGst::ErrorMessage>()->error();
        break;
    default:
        break;
    }
}
*/

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);

    MainWindow w;
   // w.showMaximized();
   // w.showNormal();
    w.setGeometry(
        QStyle::alignedRect(
            Qt::LeftToRight,
            Qt::AlignCenter,
            w.size(),
            qApp->desktop()->availableGeometry()
        )
    );
    w.show();

    /*
    QGst::init(&argc, &argv);
    //Need to implement this string as a string
    //gst-launch -v udpsrc port=8888 caps='application/x-rtp, media=(string)video, clock-rate=(int)90000, encoding-name=(string)H264' ! rtph264depay ! ffdec_h264 ! xvimagesink sync=false

    QGst::PipelinePtr pipeline1;

    const char *caps = "application/x-rtp, encoding-name=JPEG,payload=26";


    QString pipe1Descr = QString("udpsrc port=5001 ! %1 ! rtpjpegdepay ! "
                                 "jpegdec ! "
                                 "appsink").arg(caps);
    pipeline1 = QGst::Parse::launch(pipe1Descr).dynamicCast<QGst::Pipeline>();
    //QGlib::connect(pipeline1->bus(), "message::error", this, &Player::onBusMessage);
    //pipeline1->bus()->addSignalWatch();

    pipeline1->setState(QGst::StatePlaying);
    */
    return a.exec();
}
