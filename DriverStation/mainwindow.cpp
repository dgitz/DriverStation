#include "mainwindow.h"
#include "ui_mainwindow.h"
//#include <opencv2/opencv.hpp>
#include <opencv2/imgproc.hpp>
//#include <opencv2/imgcodecs.hpp>

//using namespace cv;
MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    rx_image_counter = 0;
    ROS_Server_IPAddress = "10.0.0.111";
    DSRouter_IPAddress = "10.0.0.3";
    joystick_available = false;
    Rover_IPAddress = "10.0.0.109";
    armdisarm_command = ROVERCOMMAND_DISARM;
    armdisarm_state = ARMEDSTATUS_DISARMED_CANNOTARM;

    QList<QHostAddress> list = QNetworkInterface::allAddresses();

    for(int i = 0; i <list.count();i++)
    {
        if(!list[i].isLoopback())
        {
            if(list[i].protocol() == QAbstractSocket::IPv4Protocol)
            {
                //qDebug() << list[i].toString();
                DeviceName = "UI_" + list[i].toString();
                break;
            }
        }
    }
    if(load_DeviceFile() == false)
    {
        kill_application(true);
    }
    if(load_MisConfigFile() == false)
    {
        kill_application(true);
    }



    /*chart->legend()->hide();
    chart->addSeries(series);
    chart->createDefaultAxes();
    chart->setTitle("Simple line chart example");

    QChartView *chartView = new QChartView(chart);
    chartView->setRenderHint(QPainter::Antialiasing);

    QMainWindow window;
    window.setCentralWidget(chartView);
    window.resize(400, 300);
    */
    //ResourceChart->legend()->hide();
    //ResourceChart->setTitle("Resourcesd(ResourceChart);
    //ResourceChartView->setRenderHint(QPainter::Antialiasing);
    ui->setupUi(this);


    //QMainWindow window;
    // window.setCentralWidget(ResourceChartView);
    //window.resize(400,300);
    //window.show();
    ui->groupCalibrate->hide();
    ui->tEStopState->setStyleSheet("color: black;"
                                   "background-color: orange;"
                                   "font: bold italic 36px;");
    ui->tEStopState->setText("LOST COMM!");
    messageviewer_filter = "";
    current_axis_id = -1;
    calibrating = false;

    myUDPTransmitter.set_RC_server(QString::fromStdString(Rover_IPAddress));

    myUDPReceiver.Start();
    myTCPReceiver.Start();

    QObject::connect(&camera,SIGNAL(newFrameReady(QImage,bool)),this,SLOT(newCameraImage(QImage,bool)));
    //QObject::connect(&camera,SIGNAL(newGSTFrameReady(guint8*,bool)),this,SLOT(newGSTCameraImage(guint8*,bool)));
    QObject::connect(&camera,SIGNAL(camera_status(uint8_t)),this,SLOT(newCameraStatus(uint8_t)));

    connect(ui->bClose,SIGNAL(clicked(bool)),SLOT(kill_application(bool)));
    connect(&myUDPReceiver,SIGNAL(new_diagnosticmessage(Diagnostic)),this,SLOT(update_messageviewer(Diagnostic)));
    connect(&myUDPReceiver,SIGNAL(new_armedstatusmessage(int)),this,SLOT(update_armeddisarmed_text(int)));
    connect(&myUDPReceiver,SIGNAL(new_estop(EStop)),this,SLOT(update_estop(EStop)));

    connect(&myUDPReceiver,SIGNAL(new_diagnosticmessage(Diagnostic)),this,SLOT(update_devicelist(Diagnostic)));
    connect(&myUDPReceiver,SIGNAL(new_devicemessage(Device)),this,SLOT(update_devicelist(Device)));
    timer_10ms = new QTimer(this);
    timer_50ms = new QTimer(this);
    timer_100ms = new QTimer(this);
    timer_1000ms = new QTimer(this);
    timer_5000ms = new QTimer(this);
   // connect(timer_10ms,SIGNAL(timeout()),this,SLOT(update_devicelist()));
    connect(timer_10ms,SIGNAL(timeout()),this,SLOT(update_commstatus()));




    connect(ui->tabWidget,SIGNAL(currentChanged(int)),this,SLOT(maintabChanged()));
    connect(ui->CalibrationSubTab,SIGNAL(currentChanged(int)),this,SLOT(calibrationtabChanged()));
   // connect(timer_100ms,SIGNAL(timeout()),this,SLOT(update_devicelistviewer()));
    connect(timer_100ms,SIGNAL(timeout()),this,SLOT(send_Heartbeat_message()));

    connect(ui->bXAxisCal,SIGNAL(clicked(bool)),SLOT(calibrate_XAxis(bool)));
    connect(ui->bYAxisCal,SIGNAL(clicked(bool)),SLOT(calibrate_YAxis(bool)));
    connect(ui->bZAxisCal,SIGNAL(clicked(bool)),SLOT(calibrate_ZAxis(bool)));
    connect(ui->bCalibrateCancel,SIGNAL(clicked(bool)),SLOT(cancel_calibration(bool)));
    connect(ui->bCalibrateSave,SIGNAL(clicked(bool)),SLOT(save_calibration(bool)));
    connect(ui->bArmDisarm,SIGNAL(clicked(bool)),SLOT(bArmDisarm_pressed()));
    connect(ui->bControlGroupRead,SIGNAL(clicked(bool)),SLOT(read_ControlGroupFile()));
    connect(ui->cbControlGroup,SIGNAL(currentIndexChanged(QString)),SLOT(controlGroupChanged(QString)));
    connect(ui->cbCameraStreamChooser,SIGNAL(currentIndexChanged(int)),SLOT(cameraStreamChanged(int)));
    connect(ui->bTuningPBigger,SIGNAL(clicked(bool)),SLOT(bTuningPBigger_pressed()));
    connect(ui->bTuningPSmaller,SIGNAL(clicked(bool)),SLOT(bTuningPSmaller_pressed()));
    connect(ui->bTuningIBigger,SIGNAL(clicked(bool)),SLOT(bTuningIBigger_pressed()));
    connect(ui->bTuningISmaller,SIGNAL(clicked(bool)),SLOT(bTuningISmaller_pressed()));
    connect(ui->bTuningDBigger,SIGNAL(clicked(bool)),SLOT(bTuningDBigger_pressed()));
    connect(ui->bTuningDSmaller,SIGNAL(clicked(bool)),SLOT(bTuningDSmaller_pressed()));

    connect(ui->bTuningPReset,SIGNAL(clicked(bool)),SLOT(bTuningPReset_pressed()));
    connect(ui->bTuningIReset,SIGNAL(clicked(bool)),SLOT(bTuningIReset_pressed()));
    connect(ui->bTuningDReset,SIGNAL(clicked(bool)),SLOT(bTuningDReset_pressed()));


    timer_10ms->start(10);
    timer_50ms->start(50);
    timer_100ms->start(100);
    timer_1000ms->start(1000);
    timer_5000ms->start(5000);
    for(int i = 0; i < 4; i++) { buttons.push_back(0); }


    joy_axis = NULL;
    joy_button = NULL;
    joy_fd = open("/dev/input/js0", O_RDONLY /*| O_NONBLOCK*/);

    if(joy_fd < 0)
    {
        QMessageBox::information(this,
                                 tr("Driver Station"),
                                 tr("Joystick Not Found."));
        qDebug() << "Couldn't open joystick.";
        //kill_application(true);
    }
    else
    {
        qDebug() << "f: " << joy_fd;
        int num_axes;
        int num_buttons;
        char name[80];
        num_axes = 0;
        num_buttons = 0;
        joy_axis = NULL;
        joy_button = NULL;
        ioctl(joy_fd,JSIOCGAXES,&num_axes);

        ioctl(joy_fd,JSIOCGBUTTONS,&num_buttons);
        if((num_axes == 0) || (num_buttons == 0))
        {
            qDebug() << "Couldn't read joystick.";
            joystick_available = false;
            //kill_application(true);
        }
        else
        {
            joystick_available = true;
            ioctl(joy_fd,JSIOCGNAME(80),&name);
            joy_axis = (double *)calloc(num_axes,sizeof(double));
            joy_button = (char *)calloc(num_buttons,sizeof(char));
            current_joystickname = name;
            fcntl(joy_fd,F_SETFL,O_NONBLOCK);
            qDebug() << "Name: " << name << " Axis's: " << num_axes << " Buttons: " << num_buttons;
            joystickcalibrationfile_path = "/home/robot/config/JoystickCalibration.xml";
            QFileInfo check_file(joystickcalibrationfile_path);
            if(check_file.exists() && check_file.isFile())
            {
                qDebug() << "Found joystick calibration file";
            }
            else
            {
                qDebug() << "Couldn't find joystick calibration file, creating new one.";
                create_emptyjoystickcalibrationfile();
            }
            Joystick joy;
            bool found = lookup_joystick(name,joy);
            if(found == true)
            {
                qDebug() << "Found Joystick: " << QString::fromStdString(name) << " in Cal File";
                joystick = joy;
            }
            else
            {
                qDebug() << "Didn't find Joystick: " << QString::fromStdString(name) << " in Cal File";
                bool create = create_defaultjoystick(name,num_axes);
            }
            connect(timer_50ms,SIGNAL(timeout()),this,SLOT(read_joystick()));
        }


    }
    if(joystick_available == true)
    {
        for(int i = 0; i < joystick.axes.size(); i++)
        {
            switch(joystick.axes.at(i).id)
            {
            case JOY_X_AXIS:
                ui->XAxis->setRange(joystick.axes.at(i).min,joystick.axes.at(i).max);
                break;
            case JOY_Y_AXIS:
                ui->YAxis->setRange(joystick.axes.at(i).min,joystick.axes.at(i).max);
                break;
            case JOY_Z_AXIS:
                ui->ZAxis->setRange(joystick.axes.at(i).min,joystick.axes.at(i).max);
                break;
            }
        }
    }
    {
        QPixmap pixmap("/home/robot/Dropbox/ICARUS/RoverV2/SOFTWARE/gui/icons/Router_Unactive.png");
        ui->iRouterActive->setPixmap(pixmap);
        ui->iRouterActive->setMask(pixmap.mask());
        ui->iRouterActive->show();
        DSRouter_Active = 0;
    }
    {
        QPixmap pixmap("/home/robot/Dropbox/ICARUS/RoverV2/SOFTWARE/gui/icons/ROSServer_Unactive.png");
        ui->iROSServerActive->setPixmap(pixmap);
        ui->iROSServerActive->setMask(pixmap.mask());
        ui->iROSServerActive->show();
        ROSServer_Active = 0;
    }
    {
        QPixmap pixmap("/home/robot/Dropbox/ICARUS/RoverV2/SOFTWARE/gui/icons/Rover_Unactive.png");
        ui->iRoverActive->setPixmap(pixmap);
        ui->iRoverActive->setMask(pixmap.mask());
        ui->iRoverActive->show();
        Rover_Active = 0;
    }
    {
        QPixmap pixmap("/home/robot/Dropbox/ICARUS/RoverV2/SOFTWARE/gui/icons/SSI_0.png");
        ui->iRouterSignal->setPixmap(pixmap);
        ui->iRouterSignal->setMask(pixmap.mask());
        ui->iRouterSignal->show();
        ui->iROSSignal->setPixmap(pixmap);
        ui->iROSSignal->setMask(pixmap.mask());
        ui->iROSSignal->show();
        ui->iRoverSignal->setPixmap(pixmap);
        ui->iRoverSignal->setMask(pixmap.mask());
        ui->iRoverSignal->show();
    }

    ui->tabWidget->setCurrentIndex(OPERATION_TAB);
    connect(timer_100ms,SIGNAL(timeout()),this,SLOT(update_cameraoverlay()));
    connect(timer_5000ms,SIGNAL(timeout()),this,SLOT(check_network()));
    for(std::size_t i = 0; i < camerastreams.size(); i++)
    {
        QString tempstr = QString::fromStdString(camerastreams.at(i).DeviceName) + "@" + QString::fromStdString(camerastreams.at(i).hostname) + ":" + QString::number(camerastreams.at(i).port);
        ui->cbCameraStreamChooser->addItem(tempstr);
    }
    ui->cbCameraStreamChooser->setCurrentText(0);
    camera_status = CameraStatus::UNDEFINED;
    last_joy_sidebutton = 0;
    elap_timer.start();
}
void MainWindow::cameraStreamChanged(int v)
{
    qDebug() << "Starting stream.";
    //camera.set_stream();
    camera.startCapture(camerastreams.at(v).ip,camerastreams.at(v).port);
}
void MainWindow::newGSTCameraImage(guint8 *map,bool v)
{
    cv::Mat temp_mat = cv::Mat(cv::Size(640, 480+480/2), CV_8UC1, (char*)map);
    cv::Mat result(480,640,3);
    cv::cvtColor(temp_mat,result,CV_YUV2RGB_I420,3);
    QImage rgb(result.size().width,result.size().height,QImage::Format_RGB888);
    memcpy(rgb.scanLine(0), (unsigned char*)result.data, rgb.width() * rgb.height() * result.channels());
    camera_image = rgb;
}
void MainWindow::newCameraImage(QImage img, bool v)
{

    if(camera_status == CameraStatus::AVAILABLE)
    {
        rx_image_counter++;
    }
    else
    {
        rx_image_counter = 0;
        elap_timer.restart();
    }
    camera_image = img;

}
void MainWindow::update_cameraoverlay()
{

    if(camera_status == CameraStatus::AVAILABLE)
    {

        double framerate = rx_image_counter/(elap_timer.elapsed()/1000.0);
        QPainter p(&camera_image);
        p.setPen(QPen(Qt::green));
        p.setFont(QFont("Times",12,QFont::Bold));
        QString tempstr = "FPS: " + QString::number(framerate,'f',2);
        p.drawText(540,400,80,15,Qt::AlignCenter,tempstr);

        ui->iCameraView->setPixmap(QPixmap::fromImage(camera_image));
    }

}
void MainWindow::newCameraStatus(uint8_t v)
{
    camera_status = v;
}

void MainWindow::controlGroupChanged(QString v)
{
    for(std::size_t i = 0; i < controlgroups.size(); i++)
    {
        if(controlgroups.at(i).name == v)
        {
            current_cg = controlgroups.at(i);
        }
    }
}

void MainWindow::update_estop(EStop estop)
{
   // qDebug() << "Got: " << QString::fromStdString(estop.source) << estop.state;
    if(estop.state == ESTOP_ACTIVATED)
    {
        ui->tEStopState->setText("EMERGENCY STOPPED!");
        ui->tEStopState->setStyleSheet("color: white;"
                                       "background-color: red;"
                                       "font: bold italic 36px;");
    }
    else if(estop.state == ESTOP_DISACTIVATED)
    {
        ui->tEStopState->setText("ESTOP OK");
        ui->tEStopState->setStyleSheet("color: black;"
                                       "background-color: white;"
                                       "font: bold italic 36px;");
    }
    else
    {
        ui->tEStopState->setText("ESTOP\n NOT VALID");
        ui->tEStopState->setStyleSheet("color: white;"
                                       "background-color: red;"
                                       "font: bold italic 36px;");
    }
}

void MainWindow::check_ROSServer_finished(int code, QProcess::ExitStatus status)
{
    if(code == 0) // ping successful
    {
        ROSServer_Active = 1;
        QPixmap pixmap("/home/robot/Dropbox/ICARUS/RoverV2/SOFTWARE/gui/icons/ROSServer_Active.png");
        ui->iROSServerActive->setPixmap(pixmap);
        QString ssi_path = "/home/robot/Dropbox/ICARUS/RoverV2/SOFTWARE/gui/icons/SSI_" + QString::number(convert_pingms_tossi(ROSServer_pingtimer.elapsed())) + ".png";
        QPixmap pixmap2(ssi_path);
        ui->iROSSignal->setPixmap(pixmap2);

    }
    else // ping unsuccessful
    {
        ROSServer_Active = 0;
        QPixmap pixmap("/home/robot/Dropbox/ICARUS/RoverV2/SOFTWARE/gui/icons/ROSServer_Unactive.png");
        ui->iROSServerActive->setPixmap(pixmap);
        QString ssi_path = "/home/robot/Dropbox/ICARUS/RoverV2/SOFTWARE/gui/icons/SSI_0.png";
        QPixmap pixmap2(ssi_path);
        ui->iROSSignal->setPixmap(pixmap2);
    }
}
void MainWindow::check_DSRouter_finished(int code, QProcess::ExitStatus status)
{
    if(code == 0) // ping successful
    {
        DSRouter_Active = 1;
        QPixmap pixmap("/home/robot/Dropbox/ICARUS/RoverV2/SOFTWARE/gui/icons/Router_Active.png");
        ui->iRouterActive->setPixmap(pixmap);
        QString ssi_path = "/home/robot/Dropbox/ICARUS/RoverV2/SOFTWARE/gui/icons/SSI_" + QString::number(convert_pingms_tossi(DSRouter_timer.elapsed())) + ".png";
        QPixmap pixmap2(ssi_path);
        ui->iRouterSignal->setPixmap(pixmap2);
    }
    else // ping unsuccessful
    {
        DSRouter_Active = 0;
        QPixmap pixmap("/home/robot/Dropbox/ICARUS/RoverV2/SOFTWARE/gui/icons/Router_Unactive.png");
        ui->iRouterActive->setPixmap(pixmap);
        QString ssi_path = "/home/robot/Dropbox/ICARUS/RoverV2/SOFTWARE/gui/icons/SSI_0.png";
        QPixmap pixmap2(ssi_path);
        ui->iRouterSignal->setPixmap(pixmap2);
    }
}
void MainWindow::check_Rover_finished(int code, QProcess::ExitStatus status)
{
    if(code == 0) // ping successful
    {
        Rover_Active = 1;
        QPixmap pixmap("/home/robot/Dropbox/ICARUS/RoverV2/SOFTWARE/gui/icons/Rover_Active.png");
        ui->iRoverActive->setPixmap(pixmap);
        QString ssi_path = "/home/robot/Dropbox/ICARUS/RoverV2/SOFTWARE/gui/icons/SSI_" + QString::number(convert_pingms_tossi(Rover_pingtimer.elapsed())) + ".png";
        QPixmap pixmap2(ssi_path);
        ui->iRoverSignal->setPixmap(pixmap2);
    }
    else // ping unsuccessful
    {
        Rover_Active = 0;
        QPixmap pixmap("/home/robot/Dropbox/ICARUS/RoverV2/SOFTWARE/gui/icons/Rover_Unactive.png");
        ui->iRoverActive->setPixmap(pixmap);
        QString ssi_path = "/home/robot/Dropbox/ICARUS/RoverV2/SOFTWARE/gui/icons/SSI_0.png";
        QPixmap pixmap2(ssi_path);
        ui->iRoverSignal->setPixmap(pixmap2);
    }
}
void MainWindow::check_network()
{
    {
        QProcess * const process = new QProcess();
        connect(process,SIGNAL(finished(int, QProcess::ExitStatus)),this,SLOT(check_ROSServer_finished(int,QProcess::ExitStatus)));
        QString exec="ping";
        QStringList params;
        params << "-c" << "1" << QString::fromStdString(ROS_Server_IPAddress);
        ROSServer_pingtimer.start();
        process->start("ping",QStringList() << params);
    }

    {
        QProcess * const process = new QProcess();
        connect(process,SIGNAL(finished(int, QProcess::ExitStatus)),this,SLOT(check_DSRouter_finished(int,QProcess::ExitStatus)));
        QString exec="ping";
        QStringList params;
        params << "-c" << "1" << QString::fromStdString(DSRouter_IPAddress);
        DSRouter_timer.start();
        process->start("ping",QStringList() << params);
    }

    {
        QProcess * const process = new QProcess();
        connect(process,SIGNAL(finished(int, QProcess::ExitStatus)),this,SLOT(check_Rover_finished(int,QProcess::ExitStatus)));
        QString exec="ping";
        QStringList params;
        params << "-c" << "1" << QString::fromStdString(Rover_IPAddress);
        Rover_pingtimer.start();
        process->start("ping",QStringList() << params);
    }
}
void MainWindow::calibrationtabChanged()
{
    if(ui->CalibrationSubTab->currentIndex() == CALIBRATIONTAB_JOYSTICK)
    {
        disconnect(timer_50ms,SIGNAL(timeout()),this,SLOT(update_TuningPanel()));
        connect(timer_50ms,SIGNAL(timeout()),this,SLOT(update_CalibrationPanel()));
        connect(timer_50ms,SIGNAL(timeout()),this,SLOT(update_CalibrationGroup()));
    }
    else if(ui->CalibrationSubTab->currentIndex() == CALIBRATIONTAB_TUNING)
    {
        disconnect(timer_50ms,SIGNAL(timeout()),this,SLOT(update_CalibrationPanel()));
        disconnect(timer_50ms,SIGNAL(timeout()),this,SLOT(update_CalibrationGroup()));
        read_ControlGroupFile();
        ui->cbControlGroup->setCurrentText(0);
        connect(timer_50ms,SIGNAL(timeout()),this,SLOT(update_TuningPanel()));
    }
}

void MainWindow::maintabChanged()
{
    if(ui->tabWidget->currentIndex()==CALIBRATION_TAB)
    {

        disconnect(timer_50ms,SIGNAL(timeout()),this,SLOT(update_OperationPanel()));
        disconnect(timer_100ms,SIGNAL(timeout()),this,SLOT(update_cameraoverlay()));
        connect(timer_10ms,SIGNAL(timeout()),this,SLOT(check_set_allcontrols_todefault()));
        if(ui->CalibrationSubTab->currentIndex() == CALIBRATIONTAB_JOYSTICK)
        {
            disconnect(timer_50ms,SIGNAL(timeout()),this,SLOT(update_TuningPanel()));
            connect(timer_50ms,SIGNAL(timeout()),this,SLOT(update_CalibrationPanel()));
            connect(timer_50ms,SIGNAL(timeout()),this,SLOT(update_CalibrationGroup()));
        }
        else if(ui->CalibrationSubTab->currentIndex() == CALIBRATIONTAB_TUNING)
        {
            disconnect(timer_50ms,SIGNAL(timeout()),this,SLOT(update_CalibrationPanel()));
            disconnect(timer_50ms,SIGNAL(timeout()),this,SLOT(update_CalibrationGroup()));
            read_ControlGroupFile();
            ui->cbControlGroup->setCurrentText(0);
            connect(timer_50ms,SIGNAL(timeout()),this,SLOT(update_TuningPanel()));
        }
    }
    else if(ui->tabWidget->currentIndex() == OPERATION_TAB)
    {
        disconnect(timer_10ms,SIGNAL(timeout()),this,SLOT(check_set_allcontrols_todefault()));
        disconnect(timer_50ms,SIGNAL(timeout()),this,SLOT(update_TuningPanel()));
        disconnect(timer_50ms,SIGNAL(timeout()),this,SLOT(update_CalibrationPanel()));
        disconnect(timer_50ms,SIGNAL(timeout()),this,SLOT(update_CalibrationGroup()));
        connect(timer_50ms,SIGNAL(timeout()),this,SLOT(update_OperationPanel()));
        connect(timer_100ms,SIGNAL(timeout()),this,SLOT(update_cameraoverlay()));

    }
}

void MainWindow::save_calibration(const bool)
{
    if(joystick_available == true)
    {
        calibrating = false;
        ui->groupCalibrate->hide();
        for(int i = 0; i < joystick.axes.size(); i++)
        {
            std::string axis_option = ui->lCalibrateOption->text().toStdString();
            std::size_t found_axis = axis_option.find(joystick.axes.at(i).name.toStdString());
            if(found_axis != std::string::npos)
            {
                save_axis(joystick, joystick.axes.at(i));
            }
        }
        ui->bXAxisCal->setEnabled(true);
        ui->bYAxisCal->setEnabled(true);
        ui->bZAxisCal->setEnabled(true);\
    }

}


void MainWindow::cancel_calibration(const bool)
{
    if(joystick_available == true)
    {
        calibrating = false;
        joystick = old_joystick;
        for(int i = 0; i < joystick.axes.size(); i++)
        {
            switch(joystick.axes.at(i).id)
            {
            case JOY_X_AXIS:
                ui->XAxis->setRange(joystick.axes.at(i).min,joystick.axes.at(i).max);
                break;
            case JOY_Y_AXIS:
                ui->YAxis->setRange(joystick.axes.at(i).min,joystick.axes.at(i).max);
                break;
            case JOY_Z_AXIS:
                ui->ZAxis->setRange(joystick.axes.at(i).min,joystick.axes.at(i).max);
                break;
            }
        }
        ui->groupCalibrate->hide();
        ui->bXAxisCal->setEnabled(true);
        ui->bYAxisCal->setEnabled(true);
        ui->bZAxisCal->setEnabled(true);\
    }
}

void MainWindow::check_set_allcontrols_todefault()
{
    if((armdisarm_command == ROVERCOMMAND_ARM) && (armdisarm_state == ARMEDSTATUS_ARMED)) //Nothing to do here
    {
    }
    else
    {
    }
}
void MainWindow::calibrate_XAxis(bool v)
{
    if(joystick_available == true)
    {
        calibrate_Axis(JOY_X_AXIS);
    }
}
void MainWindow::calibrate_YAxis(bool v)
{
    if(joystick_available == true)
    {
        calibrate_Axis(JOY_Y_AXIS);
    }
}
void MainWindow::calibrate_ZAxis(bool v)
{
    if(joystick_available == true)
    {
        calibrate_Axis(JOY_Z_AXIS);
    }
}
void MainWindow::calibrate_Axis(int v)
{
    if(joystick_available == true)
    {
        calibrating = true;
        old_joystick = joystick;
        ui->bXAxisCal->setEnabled(false);
        ui->bYAxisCal->setEnabled(false);
        ui->bZAxisCal->setEnabled(false);\
        Axis axis = lookup_joystickaxis(joystick,v);
        qDebug() << "id: " << QString::number(v);
        current_axis_id = v;
        ui->lCalibrateOption->setText("Calibrating: " + axis.name);

        ui->dCalibrateDeadband->setValue(axis.deadband);
        ui->lCalibrateDeadband->setText("Deadband: " + QString::number(axis.deadband) + "%");

        ui->dCalibrateMax->setValue(axis.max);
        ui->lCalibrateMax->setText("Max: " + QString::number(axis.max));

        ui->dCalibrateMin->setValue(axis.min);
        ui->lCalibrateMin->setText("Min: " + QString::number(axis.min));

        ui->dCalibrateNeutral->setValue(axis.neutral);
        ui->lCalibrateNeutral->setText("Neutral: " + QString::number(axis.neutral));
        ui->chbCalibrateInvert->setChecked(axis.invert);
        ui->groupCalibrate->show();
    }


}
void MainWindow::bTuningPReset_pressed()
{
    current_cg.gain.P = current_cg.gain.P_default;
    current_cg.gain.P_min = current_cg.gain.P-1.0;
    current_cg.gain.P_max = current_cg.gain.P+1.0;
    ui->dTuningP->setValue(0);
}
void MainWindow::bTuningIReset_pressed()
{
    current_cg.gain.I = current_cg.gain.I_default;
    current_cg.gain.I_min = current_cg.gain.I-1.0;
    current_cg.gain.I_max = current_cg.gain.I+1.0;
    ui->dTuningI->setValue(0);
}
void MainWindow::bTuningDReset_pressed()
{
    current_cg.gain.D = current_cg.gain.D_default;
    current_cg.gain.D_min = current_cg.gain.D-1.0;
    current_cg.gain.D_max = current_cg.gain.D+1.0;
    ui->dTuningD->setValue(0);
}

void MainWindow::bTuningPBigger_pressed()
{
    double range = current_cg.gain.P_max-current_cg.gain.P_min;
    current_cg.gain.P_max = current_cg.gain.P + range*4.0;
    current_cg.gain.P_min = current_cg.gain.P - range*4.0;
    ui->dTuningP->setValue(0);
}
void MainWindow::bTuningPSmaller_pressed()
{
    double range = current_cg.gain.P_max-current_cg.gain.P_min;
    current_cg.gain.P_max = current_cg.gain.P + range/4.0;
    current_cg.gain.P_min = current_cg.gain.P - range/4.0;
    ui->dTuningP->setValue(0);
}
void MainWindow::bTuningIBigger_pressed()
{
    double range = current_cg.gain.I_max-current_cg.gain.I_min;
    current_cg.gain.I_max = current_cg.gain.I + range*4.0;
    current_cg.gain.I_min = current_cg.gain.I - range*4.0;
    ui->dTuningI->setValue(0);
}
void MainWindow::bTuningISmaller_pressed()
{
    double range = current_cg.gain.I_max-current_cg.gain.I_min;
    current_cg.gain.I_max = current_cg.gain.I + range/4.0;
    current_cg.gain.I_min = current_cg.gain.I - range/4.0;
    ui->dTuningI->setValue(0);
}
void MainWindow::bTuningDBigger_pressed()
{
    double range = current_cg.gain.D_max-current_cg.gain.D_min;
    current_cg.gain.D_max = current_cg.gain.D + range*4.0;
    current_cg.gain.D_min = current_cg.gain.D - range*4.0;
    ui->dTuningD->setValue(0);
}
void MainWindow::bTuningDSmaller_pressed()
{
    double range = current_cg.gain.D_max-current_cg.gain.D_min;
    current_cg.gain.D_max = current_cg.gain.D + range/4.0;
    current_cg.gain.D_min = current_cg.gain.D - range/4.0;
    ui->dTuningD->setValue(0);
}



void MainWindow::update_CalibrationGroup()
{
    if(joystick_available == true)
    {
        if(calibrating == true)
        {
            ui->lCalibrateDeadband->setText("Deadband: " + QString::number(ui->dCalibrateDeadband->value()) + "%");
            ui->lCalibrateMax->setText("Max: " + QString::number(ui->dCalibrateMax->value()));
            ui->lCalibrateMin->setText("Min: " + QString::number(ui->dCalibrateMin->value()));
            ui->lCalibrateNeutral->setText("Neutral: " + QString::number(ui->dCalibrateNeutral->value()));
            switch(current_axis_id)
            {
            case JOY_X_AXIS:
                update_axis(JOY_X_AXIS,ui->dCalibrateNeutral->value(),ui->dCalibrateMax->value(),ui->dCalibrateMin->value(),ui->dCalibrateDeadband->value(),ui->chbCalibrateInvert->isChecked());
                ui->XAxis->setRange(ui->dCalibrateMin->value(),ui->dCalibrateMax->value());
                break;
            case JOY_Y_AXIS:
                update_axis(JOY_Y_AXIS,ui->dCalibrateNeutral->value(),ui->dCalibrateMax->value(),ui->dCalibrateMin->value(),ui->dCalibrateDeadband->value(),ui->chbCalibrateInvert->isChecked());
                ui->YAxis->setRange(ui->dCalibrateMin->value(),ui->dCalibrateMax->value());
                break;
            case JOY_Z_AXIS:
                update_axis(JOY_Z_AXIS,ui->dCalibrateNeutral->value(),ui->dCalibrateMax->value(),ui->dCalibrateMin->value(),ui->dCalibrateDeadband->value(),ui->chbCalibrateInvert->isChecked());
                ui->ZAxis->setRange(ui->dCalibrateMin->value(),ui->dCalibrateMax->value());
                break;
            }
        }
    }



}

void MainWindow::update_commstatus()
{
    qint64 time_sincelastcomm = myUDPReceiver.get_lastcomm();
    qint64 time_sincelastcomm_EStop = myUDPReceiver.get_lastcomm_EStop();
    if(time_sincelastcomm > 5000)// mS
    {
        armdisarm_state = ARMEDSTATUS_DISARMED_CANNOTARM;
        armdisarm_command = ROVERCOMMAND_DISARM;
        ui->bArmDisarm->setText("DISARMED\nCANNOT ARM");
        ui->tEStopState->setStyleSheet("color: black;"
                                       "background-color: orange;"
                                       "font: bold italic 36px;");
        ui->tEStopState->setText("LOST COMM!");
    }

    else if((time_sincelastcomm < 3000) && (time_sincelastcomm_EStop > 5000))
    {
        armdisarm_state = ARMEDSTATUS_DISARMED_CANNOTARM;
        armdisarm_command = ROVERCOMMAND_DISARM;
        ui->bArmDisarm->setText("DISARMED\nCANNOT ARM");
        ui->tEStopState->setStyleSheet("color: black;"
                                       "background-color: orange;"
                                       "font: bold italic 36px;");
        ui->tEStopState->setText("ESTOP\nNOT AVAILABLE!");
    }

}
bool MainWindow::lookup_joystick(QString name,Joystick& joy)
{
    if(joystick_available == true)
    {
        std::ifstream infile(joystickcalibrationfile_path.toStdString());
        std::string line;
        while(std::getline(infile,line))
        {
            std::size_t found_joy = line.find("<Joystick>");
            if(found_joy != std::string::npos)
            {
                std::getline(infile,line);
                std::size_t found_name = line.find(name.toStdString());
                if(found_name != std::string::npos)
                {
                    joy.name = name;
                    std::getline(infile,line);
                    int num_axes = std::stoi(get_value_fromtag(line,"AxisCount"));
                    int axis_count_found = 0;

                    while(axis_count_found < num_axes)
                    {
                        std::getline(infile,line);
                        std::size_t found_newaxis = line.find("<Axis>");
                        if(found_newaxis != std::string::npos)
                        {
                            axis_count_found++;

                        }
                        if(axis_count_found > 0)
                        {
                            Axis axis;
                            std::getline(infile,line);
                            axis.id = std::stoi(get_value_fromtag(line,"ID"));
                            std::getline(infile,line);
                            axis.name = QString::fromStdString(get_value_fromtag(line,"Name"));
                            std::getline(infile,line);
                            axis.max = std::stoi(get_value_fromtag(line,"MaxValue"));
                            std::getline(infile,line);
                            axis.min = std::stoi(get_value_fromtag(line,"MinValue"));
                            std::getline(infile,line);
                            axis.neutral = std::stoi(get_value_fromtag(line,"NeutralValue"));
                            std::getline(infile,line);
                            axis.deadband = std::stod(get_value_fromtag(line,"Deadband"));
                            std::getline(infile,line);
                            axis.invert = std::stoi(get_value_fromtag(line,"Invert"));
                            joy.axes.push_back(axis);
                            std::getline(infile,line);
                        }
                    }
                    qDebug() << "Found all axis's";
                    return true;
                }
            }
        }
    }
    return false;
}

Axis MainWindow::lookup_joystickaxis(Joystick joy, int v)
{
    for(int i = 0; i < joy.axes.size(); i++)
    {
        if(v == joy.axes.at(i).id)
        {

            return joy.axes.at(i);
        }
    }
    Axis axis;
    axis.id = -1;
    return axis;
}
std::string MainWindow::get_value_fromtag(std::string line, std::string param)
{
    std::string tempstr = "";
    std::string start_tag = "<" + param + ">";
    std::string stop_tag = "</" + param + ">";
    tempstr = line.substr(line.find(start_tag)+start_tag.length(),line.find(stop_tag)-(line.find(start_tag)+start_tag.length()));
    return tempstr;
}

void MainWindow::bRTH_pressed()
{
}
void MainWindow::bArmDisarm_pressed()
{
    if(armdisarm_state == ARMEDSTATUS_ARMED)
    {
        armdisarm_command = ROVERCOMMAND_DISARM;
    }
    else if(armdisarm_state == ARMEDSTATUS_DISARMED)
    {
        armdisarm_command = ROVERCOMMAND_ARM;
    }
    send_Arm_Command_message(armdisarm_command);
}

void MainWindow::b1_pressed()
{
    if(buttons.at(0) == 0) { buttons.at(0) = 1; }
    else { buttons.at(0) = 0; }
    send_RC_message(0);
}
void MainWindow::b2_pressed()
{
    if(buttons.at(1) == 0) { buttons.at(1) = 1; }
    else { buttons.at(1) = 0; }
    send_RC_message(0);
}
void MainWindow::b3_pressed()
{
    if(buttons.at(2) == 0) { buttons.at(2) = 1; }
    else { buttons.at(2) = 0; }
    send_RC_message(0);
}
void MainWindow::b4_pressed()
{
    if(buttons.at(3) == 0) { buttons.at(3) = 1; }
    else { buttons.at(3) = 0; }
    send_RC_message(0);
}

void MainWindow::change_RC_Server(bool set)
{
}
void MainWindow::send_ArmControl_message(int a)
{

}
void MainWindow::send_Heartbeat_message()
{
    //qDebug() << "Name: " << DeviceName;
    QDateTime currentdatetime = QDateTime::currentDateTime();
    quint64 unixtime = currentdatetime.toMSecsSinceEpoch();
    quint64 unixtime2 = unixtime + 100; //Should be 100 mS into the future
    myUDPTransmitter.send_Heartbeat_0xAB31(DeviceName.toStdString(),unixtime,unixtime2);
}

void MainWindow::send_RC_message(int a)
{
}
void MainWindow::send_Arm_Command_message(int a)
{
    myUDPTransmitter.send_Command_0xAB02(armdisarm_command,ROVERCOMMAND_NONE,ROVERCOMMAND_NONE,ROVERCOMMAND_NONE,"","");
}

MainWindow::~MainWindow()
{
    delete ui;
}
void MainWindow::stop_system(bool value)
{
}
void MainWindow::launch_system(bool value)
{
}
void MainWindow::kill_application(bool value)
{
    qDebug() << "I died.";
    myTCPReceiver.Stop();
    qApp->exit();
}
void MainWindow::changefilter_messageviewer()
{
    //qDebug() << "changing filter to: " << item;

    // qDebug() << " new: " << newitem.text(0);
}

void MainWindow::clear_messageviewer(QString value)
{
}
void MainWindow::clearfilter_messageviewer()
{
}
void MainWindow::update_armeddisarmed_text(int value)
{
    armdisarm_state = value;
    QString tempstr;
    switch (value)
    {
    case ARMEDSTATUS_ARMED: tempstr = "ARMED"; break;
    case ARMEDSTATUS_ARMING: tempstr = "ARMING"; break;
    case ARMEDSTATUS_DISARMED: tempstr = "DISARMED"; break;
    case ARMEDSTATUS_DISARMED_CANNOTARM: tempstr = "DISARMED\nCANNOT ARM"; break;
    case ARMEDSTATUS_DISARMING: tempstr = "DISARMING"; break;
    case ARMEDSTATUS_UNDEFINED: tempstr = "UNDEFINED"; break;
    default: tempstr = "UNDEFINED"; break;
    }
    ui->bArmDisarm->setText(tempstr);
}
void MainWindow::read_joystick()
{

    struct js_event js;
    read(joy_fd,&js,sizeof(struct js_event));
    switch (js.type & ~JS_EVENT_INIT)
    {
    case JS_EVENT_AXIS:
        joy_axis[js.number] = js.value;
        break;
    case JS_EVENT_BUTTON:
        joy_button[js.number] = js.value;
        break;
    }
    //Read ArmDisarm Button
    if((last_joy_sidebutton == 0) && (joy_button[JOY_BUTTON_SIDE] == 1))
    {
        last_joy_sidebutton = 1;
        if((armdisarm_state == ARMEDSTATUS_ARMED) ||
                (armdisarm_state == ARMEDSTATUS_ARMING) ||
                (armdisarm_state == ARMEDSTATUS_DISARMED) ||
                (armdisarm_state == ARMEDSTATUS_DISARMING))
        {
            if(armdisarm_command == ROVERCOMMAND_DISARM) { armdisarm_command = ROVERCOMMAND_ARM; }
            else { armdisarm_command = ROVERCOMMAND_DISARM; }
            send_Arm_Command_message(armdisarm_command);
        }
    }
    else if((last_joy_sidebutton == 1) && (joy_button[JOY_BUTTON_SIDE] == 0))
    {
        last_joy_sidebutton = 0;
    }


}
qint32 MainWindow::compute_joystickoutput(int axisid, qint32 invalue)
{
    qint32 out = 0;
    for(int i = 0; i < joystick.axes.size(); i++)
    {
        if(joystick.axes.at(i).id == axisid)
        {
            if(joystick.axes.at(i).invert == true)
            {
                invalue = -1*invalue;
            }
            if(invalue > 25000)
            {
                int stop = 1;
            }
            out = (qint32)(scale_value((double)invalue,(double)joystick.axes.at(i).neutral,-32768.0,32768.0,
                                      (double)joystick.axes.at(i).min,(double)joystick.axes.at(i).max,(double)(joystick.axes.at(i).deadband*32768.0/100.0)));
            return out;

        }
    }
}
double MainWindow::scale_value(double x,double neutral,double x1,double x2,double y1,double y2, double deadband)
{
    double out = 0.0;
    if(x < (-1.0*deadband))
    {
        double m = (y1-neutral)/(x1-(-1.0*deadband));
        out = m*(x-x1)+y1;
    }
    else if(x > deadband)
    {
        double m = (y2-neutral)/(x2-(deadband));
        out = m*(x-x2)+y2;

    }
    else
    {
        out = neutral;
    }
    return out;
}
void MainWindow::update_axis(int axisid,qint32 neutral,qint32 max,qint32 min,int deadband, bool invert)
{
    for(int i = 0; i < joystick.axes.size();i++)
    {
        if(joystick.axes.at(i).id == axisid)
        {
            joystick.axes.at(i).max = max;
            joystick.axes.at(i).min = min;
            joystick.axes.at(i).neutral = neutral;
            joystick.axes.at(i).deadband = (double)deadband;
            joystick.axes.at(i).invert = invert;
        }
    }
}
void MainWindow::update_OperationPanel()
{
    if(joystick_available == 1)
    {
        qint32 x_out = compute_joystickoutput(JOY_X_AXIS,joy_axis[JOY_X_AXIS]);
        ui->XAxis->setValue(x_out);
        ui->lXAxisValue->setText("X:" + QString::number(x_out));

        qint32 y_out = compute_joystickoutput(JOY_Y_AXIS,joy_axis[JOY_Y_AXIS]);
        ui->YAxis->setValue(y_out);
        ui->lYAxisValue->setText("Y:" + QString::number(y_out));

        qint32 z_out = compute_joystickoutput(JOY_Z_AXIS,joy_axis[JOY_Z_AXIS]);
        ui->ZAxis->setValue(z_out);
        ui->lZAxisValue->setText("Z:" + QString::number(z_out));

        QDateTime currentdatetime = QDateTime::currentDateTime();
        quint64 unixtime = currentdatetime.toMSecsSinceEpoch();
        myUDPTransmitter.send_RemoteControl_0xAB10(unixtime,
                                                   x_out,
                                                   y_out,
                                                   z_out,
                                                   0,
                                                   0,
                                                   0,
                                                   0,
                                                   0,
                                                   joy_button[JOY_BUTTON_TRIGGER],
                                                   joy_button[JOY_BUTTON_MIDDLE],
                                                   joy_button[JOY_BUTTON_SIDE],
                                                   0,
                                                   0,
                                                   0,
                                                   0,
                                                   0);
    }
}

void MainWindow::update_CalibrationPanel()
{
    if(joystick_available == true)
    {
        qint32 x_out = compute_joystickoutput(JOY_X_AXIS,joy_axis[JOY_X_AXIS]);
        ui->XAxis->setValue(x_out);
        ui->lXAxisValue->setText("X:" + QString::number(x_out));

        qint32 y_out = compute_joystickoutput(JOY_Y_AXIS,joy_axis[JOY_Y_AXIS]);
        ui->YAxis->setValue(y_out);
        ui->lYAxisValue->setText("Y:" + QString::number(y_out));

        qint32 z_out = compute_joystickoutput(JOY_Z_AXIS,joy_axis[JOY_Z_AXIS]);
        ui->ZAxis->setValue(z_out);
        ui->lZAxisValue->setText("Z:" + QString::number(z_out));

        ui->bJoyButton1->setDown(joy_button[JOY_BUTTON_TRIGGER]);
        ui->bJoyButton2->setDown(joy_button[JOY_BUTTON_MIDDLE]);
        ui->bJoyButton3->setDown(joy_button[JOY_BUTTON_SIDE]);
        if(joy_axis[JOY_POV_HORZ] < 0)
        {
            ui->bJoyPOVLeft->setDown(true);
            ui->bJoyPOVRight->setDown(false);
        }
        else if(joy_axis[JOY_POV_HORZ] > 0)
        {
            ui->bJoyPOVLeft->setDown(false);
            ui->bJoyPOVRight->setDown(true);
        }
        else
        {
            ui->bJoyPOVLeft->setDown(false);
            ui->bJoyPOVRight->setDown(false);
        }
        if(joy_axis[JOY_POV_VERT] > 0)
        {
            ui->bJoyPOVDown->setDown(true);
            ui->bJoyPOVUp->setDown(false);
        }
        else if(joy_axis[JOY_POV_VERT] < 0)
        {
            ui->bJoyPOVDown->setDown(false);
            ui->bJoyPOVUp->setDown(true);
        }
        else
        {
            ui->bJoyPOVDown->setDown(false);
            ui->bJoyPOVUp->setDown(false);
        }
        QDateTime currentdatetime = QDateTime::currentDateTime();
        quint64 unixtime = currentdatetime.toMSecsSinceEpoch();
        myUDPTransmitter.send_RemoteControl_0xAB10(unixtime,
                                                   x_out,
                                                   y_out,
                                                   z_out,
                                                   0,
                                                   0,
                                                   0,
                                                   0,
                                                   0,
                                                   joy_button[JOY_BUTTON_TRIGGER],
                                                   joy_button[JOY_BUTTON_MIDDLE],
                                                   joy_button[JOY_BUTTON_SIDE],
                                                   0,
                                                   0,
                                                   0,
                                                   0,
                                                   0);
    }
}
void MainWindow::update_TuningPanel()
{
    double Pscaled = scale_value((double)ui->dTuningP->value(),(current_cg.gain.P_max+current_cg.gain.P_min)/2.0,-1000.0,1000.0,current_cg.gain.P_min,current_cg.gain.P_max,0.0);
    double Iscaled = scale_value((double)ui->dTuningI->value(),(current_cg.gain.I_max+current_cg.gain.I_min)/2.0,-1000.0,1000.0,current_cg.gain.I_min,current_cg.gain.I_max,0.0);
    double Dscaled = scale_value((double)ui->dTuningD->value(),(current_cg.gain.D_max+current_cg.gain.D_min)/2.0,-1000.0,1000.0,current_cg.gain.D_min,current_cg.gain.D_max,0.0);

    current_cg.gain.P = Pscaled;
    current_cg.gain.I = Iscaled;
    current_cg.gain.D = Dscaled;

    ui->lTuningPValue->setText(QString().setNum(current_cg.gain.P,'k',4));
    ui->lTuningIValue->setText(QString().setNum(current_cg.gain.I,'k',4));
    ui->lTuningDValue->setText(QString().setNum(current_cg.gain.D,'k',4));
    ui->lTuningMaxValue->setText(QString::number(ui->hsTuningMaxValue->value()));
    ui->lTuningMinValue->setText(QString::number(ui->hsTuningMinValue->value()));
    ui->lTuningDefaultValue->setText(QString::number(ui->hsTuningDefaultValue->value()));
    myUDPTransmitter.send_TuneControlGroup_0xAB39(current_cg.name.toStdString(),current_cg.gain.type.toStdString(),current_cg.gain.P,current_cg.gain.I,current_cg.gain.D,
                                           ui->hsTuningMaxValue->value(),ui->hsTuningMinValue->value(),ui->hsTuningDefaultValue->value());
    update_OperationPanel();
}

void MainWindow::update_devicelist()
{
    for(int i = 0; i < DeviceList.size();i++)
    {
        for(int j = 0; j < DeviceList.at(i).Nodes.size();j++)
        {
            DeviceList.at(i).Nodes.at(j).time_delta_ms += 10;
        }
    }
}

void MainWindow::update_devicelist(const Device &device)
{
    bool add_new_device = true;
    for(int i = 0; i < DeviceList.size();i++)
    {
        Device dev = DeviceList.at(i);
        if(dev.DeviceName == device.DeviceName)
        {
            add_new_device = false;
            break;
        }

    }
    /*
    if(add_new_device == true)
    {
        DeviceList.push_back(device);
    }
    */
}

void MainWindow::update_devicelist(const Diagnostic &diag)
{
    for(int i = 0; i < DeviceList.size();i++)
    {
        Device dev = DeviceList.at(i);
        std::size_t found = diag.NodeName.find(dev.DeviceName);

        if(found != std::string::npos)
        {
            bool add_new_node = true;
            for(int j = 0; j < dev.Nodes.size();j++)
            {
                if(dev.Nodes.at(j).NodeName == diag.NodeName)
                {
                    DeviceList.at(i).Nodes.at(j).time_delta_ms = 0;
                    DeviceList.at(i).Nodes.at(j).Level = diag.Level;
                    add_new_node = false;
                    break;
                }
            }
            if(add_new_node == true)
            {
                Node newnode;
                newnode.NodeName = diag.NodeName;
                newnode.time_delta_ms = 0;
                DeviceList.at(i).Nodes.push_back(newnode);
            }
        }
    }
}
void MainWindow::update_devicelistviewer()
{



}
void MainWindow::update_messageviewer(const Diagnostic &diag)
{
    if(diag.Level > INFO)
    {
        QString tempstr = QTime::currentTime().toString() + " " + QString::fromStdString(diag.Description);
        ui->tInfo->append(tempstr);
    }
}

std::string MainWindow::get_level_string(int value)
{
    switch (value)
    {
    case DEBUG: return "DEBUG"; break;
    case INFO: return "INFO"; break;
    case NOTICE: return "NOTICE"; break;
    case WARN: return "WARN"; break;
    case ERROR: return "ERROR"; break;
    case FATAL: return "FATAL"; break;
    default: return ""; break;
    }
}
bool MainWindow::create_emptyjoystickcalibrationfile()
{
    std::ofstream outfile;
    outfile.open(joystickcalibrationfile_path.toStdString());
    outfile << "<?xml version=\"1.0\" ?>\r\n";
    outfile << "<JoystickCalibrationFile>\r\n";
    outfile << "\t<JoystickList>\r\n";
    outfile << "\t</JoystickList>\r\n";
    outfile << "</JoystickCalibrationFile>\r\n";
    outfile.close();

}
bool MainWindow::save_axis(Joystick joy, Axis axis)
{
    std::vector<std::string> old_file;

    std::ifstream infile(joystickcalibrationfile_path.toStdString());
    std::string line;
    qint32 line_number = 0;
    bool in_joystick = false;
    qint32 line_to_startupdate = 0;
    qint32 line_to_stopupdate = 0;
    while(std::getline(infile,line))
    {
        old_file.push_back(line);
        std::size_t found_joystick = line.find(joy.name.toStdString());
        if(found_joystick != std::string::npos)
        {
            in_joystick = true;
        }
        if(in_joystick == true)
        {
            std::size_t axis_line = line.find(axis.name.toStdString());
            if(axis_line != std::string::npos)
            {
                line_to_startupdate = line_number-1;
                line_to_stopupdate = line_number+5;
                in_joystick = false;

            }
        }
        line_number++;
    }
    std::vector<std::string> new_file;
    for(int i = 0; i < old_file.size(); i++)
    {
        if((i >= line_to_startupdate) && (i < line_to_stopupdate))
        {
            new_file.push_back("\t\t\t\t<ID>" + std::to_string(axis.id) + "</ID>");
            new_file.push_back("\t\t\t\t<Name>" + axis.name.toStdString() + "</Name>");
            new_file.push_back("\t\t\t\t<MaxValue>" + std::to_string(ui->dCalibrateMax->value()) + "</MaxValue>");
            new_file.push_back("\t\t\t\t<MinValue>" + std::to_string(ui->dCalibrateMin->value()) + "</MinValue>");
            new_file.push_back("\t\t\t\t<NeutralValue>" + std::to_string(ui->dCalibrateNeutral->value()) + "</NeutralValue>");
            new_file.push_back("\t\t\t\t<Deadband>" + std::to_string(ui->dCalibrateDeadband->value()) + "</Deadband>");
            new_file.push_back("\t\t\t\t<Invert>" + std::to_string(ui->chbCalibrateInvert->isChecked()) + "</Invert>");
            i = line_to_stopupdate;
        }
        else
        {
            new_file.push_back(old_file.at(i));
        }
    }
    std::ofstream outfile;
    outfile.open(joystickcalibrationfile_path.toStdString());
    for(int i = 0; i < new_file.size(); i++)
    {
        outfile << new_file.at(i) << "\n";
    }
    outfile.close();
}
bool MainWindow::create_defaultjoystick(QString name,int numaxes)
{
    std::vector<std::string> old_file;
    std::ifstream infile(joystickcalibrationfile_path.toStdString());
    std::string line;
    qint32 line_to_insert = 0;
    while(std::getline(infile,line))
    {
        old_file.push_back(line);
        std::size_t new_joystickline = line.find("</JoystickList>");

        if(new_joystickline == std::string::npos)
        {
            line_to_insert++;
        }
    }
    line_to_insert -= 1;
    std::vector<std::string> newlist;
    newlist.push_back("\t\t<Joystick>\r\n");
    newlist.push_back("\t\t\t<Name>" + name.toStdString() + "</Name>\r\n");
    newlist.push_back("\t\t\t<AxisCount>" + std::to_string(numaxes) + "</AxisCount>\r\n");
    for(int i = 0; i < numaxes; i++)
    {
        newlist.push_back("\t\t\t<Axis>\r\n");
        newlist.push_back("\t\t\t\t<ID>" + std::to_string(i) + "</ID>\r\n");
        newlist.push_back("\t\t\t\t<Name></Name>\r\n");
        newlist.push_back("\t\t\t\t<MaxValue>32768</MaxValue>\r\n");
        newlist.push_back("\t\t\t\t<MinValue>-32768</MinValue>\r\n");
        newlist.push_back("\t\t\t\t<NeutralValue>0</NeutralValue>\r\n");
        newlist.push_back("\t\t\t\t<Deadband>0.0</Deadband>\r\n");
        newlist.push_back("\t\t\t\t<Invert>0</Invert>\r\n");
        newlist.push_back("\t\t\t</Axis>\r\n");
    }
    newlist.push_back("\t\t</Joystick>\r\n");
    std::vector<std::string> new_file;

    for(int i = 0; i < old_file.size(); i++)
    {
        if(i == line_to_insert)
        {
            for(int j = 0; j < newlist.size(); j++)
            {
                new_file.push_back(newlist.at(j));
            }
        }
        new_file.push_back(old_file.at(i));
    }
    std::ofstream outfile;
    outfile.open(joystickcalibrationfile_path.toStdString());
    for(int i = 0; i < new_file.size(); i++)
    {
        outfile << new_file.at(i);
    }
    outfile.close();

}
int MainWindow::convert_pingms_tossi(int v)
{
    if(v < 15)
    {
        return 5;
    }
    else if((v >= 15) && ( v < 100))
    {
        return 4;
    }
    else if((v >= 100) && ( v < 250))
    {
        return 3;
    }
    else if((v >= 250) && ( v < 350))
    {
        return 2;
    }
    else if((v >= 350) && ( v < 500))
    {
        return 1;
    }
    else
    {
        return 0;
    }
}
void MainWindow::read_ControlGroupFile()
{
    QFile file("/home/robot/config/ControlGroup.xml");
    if(!file.open(QFile::ReadOnly | QFile::Text)){
            qDebug() << "Cannot read file" << file.errorString();
            return;
    }
    QXmlStreamReader reader(&file);
    if (reader.readNextStartElement())
    {
            if (reader.name() == "ControlGroupFile")
            {
                while(reader.readNextStartElement())
                {
                    if(reader.name() == "ControlGroupList")
                    {
                        while(reader.readNextStartElement())
                        {
                            if(reader.name() == "ControlGroup")
                            {
                                ControlGroup cg;

                                while(reader.readNextStartElement())
                                {
                                    qDebug() << "name: " << reader.name();
                                    if(reader.name() == "Name")
                                    {

                                        cg.name = reader.readElementText();
                                    }
                                    else if(reader.name() == "Command")
                                    {
                                        reader.skipCurrentElement();
                                    }
                                    else if(reader.name() == "Sensor")
                                    {
                                        reader.skipCurrentElement();
                                    }
                                    else if(reader.name() == "Output")
                                    {
                                        reader.skipCurrentElement();
                                    }
                                    else if(reader.name() == "Gain")
                                    {
                                        while(reader.readNextStartElement())
                                        {
                                            if(reader.name() == "Type")
                                            {
                                                cg.gain.type = reader.readElementText();
                                            }
                                            else if(reader.name() == "Proportional")
                                            {
                                                cg.gain.P = reader.readElementText().toDouble();
                                                cg.gain.P_default = cg.gain.P;
                                                cg.gain.P_min = cg.gain.P-1.0;
                                                cg.gain.P_max = cg.gain.P+1.0;
                                            }
                                            else if(reader.name() == "Integral")
                                            {
                                                cg.gain.I = reader.readElementText().toDouble();
                                                cg.gain.I_default = cg.gain.I;
                                                cg.gain.I_min = cg.gain.I-1.0;
                                                cg.gain.I_max = cg.gain.I+1.0;
                                            }
                                            else if(reader.name() == "Derivative")
                                            {
                                                cg.gain.D = reader.readElementText().toDouble();
                                                cg.gain.D_default = cg.gain.D;
                                                cg.gain.D_min = cg.gain.D-1.0;
                                                cg.gain.D_max = cg.gain.D+1.0;
                                            }
                                        }
                                    }
                                }

                                controlgroups.push_back(cg);
                            }
                            else
                            {
                                reader.skipCurrentElement();
                            }
                        }
                    }
                    else
                    {
                        reader.skipCurrentElement();
                    }
                }
            }
            else
                reader.raiseError(QObject::tr("Incorrect file"));
    }
    for(std::size_t i = 0; i < controlgroups.size(); i++)
    {
        ui->cbControlGroup->addItem(controlgroups.at(i).name);
    }
    ui->hsTuningMaxValue->setValue(1500);
    ui->hsTuningMinValue->setValue(1500);
    ui->hsTuningDefaultValue->setValue(1500);

    return;
}
bool MainWindow::load_DeviceFile()
{
    QFile file("/home/robot/config/DeviceFile.xml");
    if(!file.open(QFile::ReadOnly | QFile::Text)){
            qDebug() << "Cannot read DeviceFile.xml" << file.errorString();
            return false;
    }
    QXmlStreamReader reader(&file);
    if (reader.readNextStartElement())
    {
        if (reader.name() == "DeviceListFile")
        {
            while(reader.readNextStartElement())
            {
                if(reader.name() == "DeviceList")
                {
                    while(reader.readNextStartElement())
                    {
                        if(reader.name() == "Device")
                        {
                            Device dev;

                            while(reader.readNextStartElement())
                            {
                                if(reader.name() == "ParentDevice")
                                {

                                    dev.ParentDevice = reader.readElementText().toStdString();
                                }
                                else if(reader.name() == "DeviceName")
                                {
                                    dev.DeviceName = reader.readElementText().toStdString();
                                }
                                else if(reader.name() == "DeviceType")
                                {
                                    dev.DeviceType = reader.readElementText().toStdString();
                                }
                                else if(reader.name() == "PrimaryIP")
                                {
                                    dev.PrimaryIP = reader.readElementText().toStdString();
                                }
                                else if(reader.name() == "Capability")
                                {
                                    dev.Capability = reader.readElementText().toStdString();
                                }
                                else
                                {
                                    reader.skipCurrentElement();
                                }


                            }
                            DeviceList.push_back(dev);
                            if(dev.Capability == "CameraStream")
                            {
                                CameraStream cam;
                                cam.ip = "";
                                cam.DeviceName = dev.DeviceName;
                                cam.hostname = dev.ParentDevice;
                                camerastreams.push_back(cam);
                            }
                        }

                    }
                }
                else
                {
                    reader.skipCurrentElement();
                }
            }
        }
        else
        {
            reader.skipCurrentElement();
        }
    }

    for(std::size_t i = 0; i < camerastreams.size(); i++)
    {
        if(camerastreams.at(i).ip == "")
        {
            for(std::size_t j = 0; j < DeviceList.size();j++)
            {
                if(camerastreams.at(i).hostname == DeviceList.at(j).DeviceName)
                {
                    camerastreams.at(i).ip = DeviceList.at(j).PrimaryIP;
                    camerastreams.at(i).port = 0;
                    break;
                }
            }
        }
    }


    return true;
}
bool MainWindow::load_MisConfigFile()
{
    QFile file("/home/robot/config/MiscConfig.xml");
    if(!file.open(QFile::ReadOnly | QFile::Text)){
            qDebug() << "Cannot read MiscConfig.xml" << file.errorString();
            return false;
    }
    QXmlStreamReader reader(&file);
    if (reader.readNextStartElement())
    {
        if (reader.name() == "MiscConfigFile")
        {
            while(reader.readNextStartElement())
            {
                if(reader.name() == "PortList")
                {
                    while(reader.readNextStartElement())
                    {
                        if(reader.name() == "Port")
                        {
                            Port port;

                            while(reader.readNextStartElement())
                            {
                                if(reader.name() == "Capability")
                                {

                                    port.Capability = reader.readElementText().toStdString();
                                }
                                else if(reader.name() == "Name")
                                {
                                    port.name = reader.readElementText().toStdString();
                                }
                                else if(reader.name() == "Number")
                                {
                                    QString portnumber = reader.readElementText();

                                    port.number = portnumber.toUInt();
                                }
                                else
                                {
                                    reader.skipCurrentElement();
                                }
                            }

                            ports.push_back(port);
                        }
                    }
                }
            }
        }
    }
    for(std::size_t i = 0; i < ports.size(); i++)
    {
        if(ports.at(i).name == "CameraPort")
        {
            for(std::size_t j = 0; j < camerastreams.size();j++)
            {
                camerastreams.at(j).port = ports.at(i).number;
            }
        }
    }
    return true;
}
