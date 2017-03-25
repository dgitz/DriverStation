#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    std::string default_ROSCORE = "10.0.0.111";
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
    messageviewer_filter = "";
    myUDPTransmitter.set_RC_server(QString::fromStdString(default_ROSCORE));

    myUDPReceiver.Start();
    myTCPReceiver.Start();
    connect(ui->bClose,SIGNAL(clicked(bool)),SLOT(kill_application(bool)));
    connect(&myUDPReceiver,SIGNAL(new_diagnosticmessage(Diagnostic)),this,SLOT(update_messageviewer(Diagnostic)));
    connect(&myUDPReceiver,SIGNAL(new_armedstatusmessage(int)),this,SLOT(update_armeddisarmed_text(int)));

    connect(&myUDPReceiver,SIGNAL(new_diagnosticmessage(Diagnostic)),this,SLOT(update_devicelist(Diagnostic)));
    connect(&myUDPReceiver,SIGNAL(new_devicemessage(Device)),this,SLOT(update_devicelist(Device)));
    timer_10ms = new QTimer(this);
    connect(timer_10ms,SIGNAL(timeout()),this,SLOT(update_devicelist()));
    connect(timer_10ms,SIGNAL(timeout()),this,SLOT(update_commstatus()));

    connect(timer_10ms,SIGNAL(timeout()),this,SLOT(check_set_allcontrols_todefault()));

    connect(&myTCPReceiver,SIGNAL(new_image(QPixmap)),this,SLOT(update_imageview(QPixmap)));
    timer_10ms->start(10);

    QTimer *timer_100ms = new QTimer(this);
    connect(timer_100ms,SIGNAL(timeout()),this,SLOT(update_devicelistviewer()));
    connect(timer_100ms,SIGNAL(timeout()),this,SLOT(send_Heartbeat_message()));
    connect(ui->bXAxisCal,SIGNAL(clicked(bool)),SLOT(calibrate_XAxis(bool)));
    connect(ui->bYAxisCal,SIGNAL(clicked(bool)),SLOT(calibrate_YAxis(bool)));
    connect(ui->bZAxisCal,SIGNAL(clicked(bool)),SLOT(calibrate_ZAxis(bool)));
    connect(ui->bCalibrateCancel,SIGNAL(clicked(bool)),SLOT(cancel_calibration(bool)));
    connect(ui->bCalibrateSave,SIGNAL(clicked(bool)),SLOT(save_calibration(bool)));
    timer_100ms->start(100);
    for(int i = 0; i < 4; i++) { buttons.push_back(0); }


    joy_axis = NULL;
    joy_button = NULL;
    joy_fd = open("/dev/input/js0", O_RDONLY /*| O_NONBLOCK*/);
    if(joy_fd < 0)
    {
        qDebug() << "Couldn't open joystick. Exiting.";
        kill_application(true);
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
            qDebug() << "Couldn't read joystick. Exiting.";
            kill_application(true);
        }
        ioctl(joy_fd,JSIOCGNAME(80),&name);
        joy_axis = (double *)calloc(num_axes,sizeof(double));
        joy_button = (char *)calloc(num_buttons,sizeof(char));
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
            qDebug() << "Couldn't find joystick calibration file";
            create_emptyjoystickcalibrationfile();
        }
        connect(timer_10ms,SIGNAL(timeout()),this,SLOT(read_joystick()));

    }

    {
        JoystickControl joy;
        joy.Axis_id = JOY_X_AXIS;
        joy.name = "XAxis";
        joy.deadband = 0.0;
        joy.invert = false;
        joy.value = 0;
        joy.max = 32768;
        joy.min = -32768;
        joystickcontrols.push_back(joy);
    }
    {
        JoystickControl joy;
        joy.Axis_id = JOY_Y_AXIS;
        joy.name = "YAxis";
        joy.deadband = 10.0;
        joy.invert = true;
        joy.value = 0;
        joy.max = 1000;
        joy.min = -1000;
        joystickcontrols.push_back(joy);
    }
    {
        JoystickControl joy;
        joy.Axis_id = JOY_Z_AXIS;
        joy.name = "ZAxis";
        joy.deadband = 0.0;
        joy.invert = false;
        joy.value = 0;
        joy.max = 32768;
        joy.min = -32768;
        joystickcontrols.push_back(joy);
    }

    connect(timer_10ms,SIGNAL(timeout()),this,SLOT(update_CalibrationPanel()));




}
void MainWindow::save_calibration(const bool)
{
    ui->groupCalibrate->hide();
    ui->bXAxisCal->setEnabled(true);
    ui->bYAxisCal->setEnabled(true);
    ui->bZAxisCal->setEnabled(true);\
}
void MainWindow::cancel_calibration(const bool)
{
    ui->groupCalibrate->hide();
    ui->bXAxisCal->setEnabled(true);
    ui->bYAxisCal->setEnabled(true);
    ui->bZAxisCal->setEnabled(true);\
}

void MainWindow::update_imageview(QPixmap pic)
{
    ui->label->setPixmap(pic);
    ui->label->show();

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
    calibrate_Axis(JOY_X_AXIS);
}
void MainWindow::calibrate_YAxis(bool v)
{
    calibrate_Axis(JOY_Y_AXIS);
}
void MainWindow::calibrate_ZAxis(bool v)
{
    calibrate_Axis(JOY_Z_AXIS);
}
void MainWindow::calibrate_Axis(int v)
{
    ui->bXAxisCal->setEnabled(false);
    ui->bYAxisCal->setEnabled(false);
    ui->bZAxisCal->setEnabled(false);\
    JoystickControl joy = lookup_joystickcontrol(v);

    ui->lCalibrateOption->setText("Calibrating: " + joy.name);

    ui->dCalibrateDeadband->setValue(joy.deadband);
    ui->lCalibrateDeadband->setText("Deadband: " + QString::number(joy.deadband) + "%");

    ui->dCalibrateMax->setValue(joy.max);
    ui->lCalibrateMax->setText("Max: " + QString::number(joy.max));

    ui->dCalibrateMin->setValue(joy.min);
    ui->lCalibrateMin->setText("Min: " + QString::number(joy.min));

    ui->chbInvert->setChecked(joy.invert);

    ui->groupCalibrate->show();
    connect(timer_10ms,SIGNAL(timeout()),this,SLOT(update_CalibrationGroup()));


}

void MainWindow::update_CalibrationGroup()
{
    ui->lCalibrateDeadband->setText("Deadband: " + QString::number(ui->dCalibrateDeadband->value()) + "%");
    ui->lCalibrateMax->setText("Max: " + QString::number(ui->dCalibrateMax->value()));
    ui->lCalibrateMin->setText("Min: " + QString::number(ui->dCalibrateMin->value()));
}

void MainWindow::update_commstatus()
{
    qint64 time_sincelastcomm = myUDPReceiver.get_lastcomm();
    if(time_sincelastcomm > 500)// mS
    {
        armdisarm_state = ARMEDSTATUS_DISARMED_CANNOTARM;
        armdisarm_command = ROVERCOMMAND_DISARM;
    }

}
JoystickControl MainWindow::lookup_joystickcontrol(int v)
{
    for(int i = 0; i < joystickcontrols.size(); i++)
    {
        if(v == joystickcontrols.at(i).Axis_id)
        {
            return joystickcontrols.at(i);
        }
    }
    JoystickControl joy;
    joy.Axis_id = -1;
    return joy;
}

void MainWindow::bRTH_pressed()
{
}
void MainWindow::bArmDisarm_pressed()
{
    if(armdisarm_command == ROVERCOMMAND_DISARM) { armdisarm_command = ROVERCOMMAND_ARM; }
    else { armdisarm_command = ROVERCOMMAND_DISARM; }
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
    myUDPTransmitter.send_ArmCommand_0xAB27(armdisarm_command);
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
         case ARMEDSTATUS_DISARMED_CANNOTARM: tempstr = "DISARMING\nCANNOT ARM"; break;
         case ARMEDSTATUS_DISARMING: tempstr = "DISARMING"; break;
         case ARMEDSTATUS_UNDEFINED: tempstr = "UNDEFINED";
     }
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
    //qDebug() << "Axis: 0 " << joy_axis[0];

}
void MainWindow::update_CalibrationPanel()
{
    if(ui->chbXAxisInvert->isChecked() == true)
    {
        ui->XAxis->setValue((double)(-joy_axis[JOY_X_AXIS]));
        ui->lXAxisValue->setText("X:" + QString::number(-joy_axis[JOY_X_AXIS]));
    }
    else
    {
        ui->XAxis->setValue((double)(joy_axis[JOY_X_AXIS]));
        ui->lXAxisValue->setText("X:" + QString::number(joy_axis[JOY_X_AXIS]));
    }
    if(ui->chbYAxisInvert->isChecked() == true)
    {
        ui->YAxis->setValue((double)(-joy_axis[JOY_Y_AXIS]));
        ui->lYAxisValue->setText("Y:" + QString::number(-joy_axis[JOY_Y_AXIS]));
    }
    else
    {
         ui->YAxis->setValue((double)(joy_axis[JOY_Y_AXIS]));
         ui->lYAxisValue->setText("Y:" + QString::number(joy_axis[JOY_Y_AXIS]));
    }
    if(ui->chbZAxisInvert->isChecked() == true)
    {
        ui->ZAxis->setValue((double)(-joy_axis[JOY_Z_AXIS]));
        ui->lZAxisValue->setText("Z:" + QString::number(-joy_axis[JOY_Z_AXIS]));
    }
    else
    {
        ui->ZAxis->setValue((double)(joy_axis[JOY_Z_AXIS]));
        ui->lZAxisValue->setText("Z:" + QString::number(joy_axis[JOY_Z_AXIS]));
    }
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
    if(add_new_device == true)
    {
        DeviceList.push_back(device);
    }
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
    outfile << "</JoystickCalibrationFile>\r\n";
    outfile.close();

}
