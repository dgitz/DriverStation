#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QString>
#include <QDateTime>
#include <QNetworkInterface>
#include <QTimer>
#include <QProcess>
#include <QTreeWidget>
#include <QtCharts>
#include <QLineSeries>
#include <udpreceiver.h>
#include <udptransmitter.h>
#include <tcpreceiver.h>
#include "gamepadmonitor.h"
#include <QTouchEvent>
#include <QHostInfo>
#include <QCloseEvent>
#include <QGamepad>

#include <fcntl.h>
#include <unistd.h>
#include <stdio.h>
#include <sys/ioctl.h>
#include <linux/joystick.h>

#define JOY_X_AXIS 0
#define JOY_Y_AXIS 1
#define JOY_Z_AXIS 2
#define JOY_POV_HORZ 3
#define JOY_POV_VERT 4
#define JOY_BUTTON_TRIGGER 0
#define JOY_BUTTON_MIDDLE 1
#define JOY_BUTTON_SIDE 3

using namespace QtCharts;
namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();
    std::string get_level_string(int);


public slots:
    void update_messageviewer(const Diagnostic &diag);
    void update_armeddisarmed_text(const int);
    void kill_application(const bool);
    void stop_system(const bool);
    void launch_system(const bool);
    void clear_messageviewer(const QString);
    void changefilter_messageviewer();
    void clearfilter_messageviewer();
    void update_devicelist(const Diagnostic &diag);
    void update_devicelist(const Device &device);
    void read_joystick();
    void check_set_allcontrols_todefault();
    void update_devicelist();
    void update_devicelistviewer();
    void change_RC_Server(bool set);
    void update_commstatus();
    void send_RC_message(int);
    void send_ArmControl_message(int);
    void send_Arm_Command_message(int);
    void send_Heartbeat_message();
    void bArmDisarm_pressed();
    void b1_pressed();
    void b2_pressed();
    void b3_pressed();
    void b4_pressed();
    void update_CalibrationPanel();

    void bRTH_pressed();

    void update_imageview(QPixmap);


signals:
    void new_diagnosticmessage(Diagnostic);
    void new_devicemessage(Device);

private:
    Ui::MainWindow *ui;
    UDPReceiver myUDPReceiver;
    UDPTransmitter myUDPTransmitter;
    TCPReceiver myTCPReceiver;


   // QChart *ResourceChart;
    //QChartView *ResourceChartView;

    std::vector<Device> DeviceList;
    std::vector<int> buttons;
    QString messageviewer_filter;
    QString DeviceName;
    int armdisarm_command;
    int armdisarm_state;

    //GamepadMonitor monitor;


    int joy_fd;
    double *joy_axis;
    char *joy_button;

};

#endif // MAINWINDOW_H
