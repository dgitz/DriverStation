#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QString>
#include <QDateTime>
#include <QNetworkInterface>
#include <QTimer>
#include <QProcess>
#include <QTreeWidget>
#include <QDial>
#include <QtCharts>
#include <QLineSeries>
#include <udpreceiver.h>
#include <udptransmitter.h>
#include <tcpreceiver.h>
#include <QTouchEvent>
#include <QHostInfo>
#include <QCloseEvent>
#include <QFileInfo>
#include <QXmlStreamReader>
#include <QElapsedTimer>
#include <fcntl.h>
#include <unistd.h>
#include <stdio.h>
#include <sys/ioctl.h>
#include <cstdint>
#include <fstream>
#include <iostream>
#include "camera.h"
#include <linux/joystick.h>
#include <QtGamepad>

#include <gst/app/gstappsink.h>
#include <glib.h>



#define JOY_X_AXIS 0
#define JOY_Y_AXIS 1
#define JOY_Z_AXIS 2
#define JOY_POV_HORZ 3
#define JOY_POV_VERT 4
#define JOY_BUTTON_TRIGGER 0
#define JOY_BUTTON_MIDDLE 1
#define JOY_BUTTON_SIDE 3
#define CALIBRATION_TAB 0
#define OPERATION_TAB 1
#define DIAGNOSTIC_TAB 2
#define CALIBRATIONTAB_JOYSTICK 0
#define CALIBRATIONTAB_TUNING 1

//using namespace QtCharts;
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
    struct UDPMessageInfo
    {
        std::string id;
        std::string name;
        uint64_t rx_count;
        uint64_t tx_count;
    };


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
    void maintabChanged();
    void calibrationtabChanged();
    void b1_pressed();
    void b2_pressed();
    void b3_pressed();
    void b4_pressed();
    void update_CalibrationPanel();
    void update_OperationPanel();
    void update_CalibrationGroup();
    void update_TuningPanel();
    void update_DiagnosticTab();
    void calibrate_Axis(const int);
    void calibrate_XAxis(const bool);
    void calibrate_YAxis(const bool);
    void calibrate_ZAxis(const bool);
    void save_calibration(const bool);
    void cancel_calibration(const bool);
    void check_network();
    void read_ControlGroupFile();
    void check_ROSServer_finished(int code, QProcess::ExitStatus status);
    void check_DSRouter_finished(int code, QProcess::ExitStatus status);
    void check_Rover_finished(int code, QProcess::ExitStatus status);
    void bRTH_pressed();
    void controlGroupChanged(QString v);
    void cameraStreamChanged(int v);
    void bTuningPBigger_pressed();
    void bTuningPSmaller_pressed();
    void bTuningIBigger_pressed();
    void bTuningISmaller_pressed();
    void bTuningDBigger_pressed();
    void bTuningDSmaller_pressed();
    void bTuningPReset_pressed();
    void bTuningIReset_pressed();
    void bTuningDReset_pressed();

    void newCameraImage(QImage,bool);
    void newGSTCameraImage(guint8* map,bool);
    void newCameraStatus(uint8_t);
    void update_cameraoverlay();


signals:
    void new_diagnosticmessage(Diagnostic);
    void new_devicemessage(Device);

private:
    void keyPressEvent(QKeyEvent * event);
    void init_udpmessageinfo();
    std::vector<UDPMessageInfo> udp_messages;
    bool new_udpmsgreceived(std::string id);
    bool new_udpmsgsent(std::string id);
    QElapsedTimer elap_timer;
    Ui::MainWindow *ui;
    UDPReceiver myUDPReceiver;
    UDPTransmitter myUDPTransmitter;
    TCPReceiver myTCPReceiver;
    bool load_DeviceFile();
    bool load_MisConfigFile();
    Axis lookup_joystickaxis(Joystick joy, int v);
    QString joystickcalibrationfile_path;
    bool create_emptyjoystickcalibrationfile();
    bool lookup_joystick(QString name,Joystick& joy);
    bool create_defaultjoystick(QString name,int numaxes);
    std::string get_value_fromtag(std::string, std::string param);
    bool save_axis(Joystick joy, Axis axis);
    qint32 compute_joystickoutput(int axisid, qint32 invalue);
    double scale_value(double x,double neutral,double x1,double x2,double y1,double y2, double deadband);
    void update_axis(int axisid,qint32 neutral,qint32 max,qint32 min,int deadband, bool invert);


    int convert_pingms_tossi(int v);
    std::string ROS_Server_IPAddress;
    int ROSServer_Active;
    std::string DSRouter_IPAddress;
    int DSRouter_Active;
    std::string Rover_IPAddress;
    int Rover_Active;
    int joystick_available;
        Camera camera;



   // QChart *ResourceChart;
    //QChartView *ResourceChartView;

    std::vector<Device> DeviceList;
    std::vector<CameraStream> camerastreams;
    std::vector<int> buttons;
    QString messageviewer_filter;
    QString DeviceName;
    int armdisarm_command;
    int armdisarm_state;
    int current_axis_id;
    Joystick joystick;
    Joystick old_joystick;
    bool calibrating;
    QString current_joystickname;
    int last_joy_sidebutton;

    int joy_fd;
    double *joy_axis;

    char *joy_button;
    QTimer *timer_10ms;
    QTimer *timer_50ms;
    QTimer *timer_100ms;
    QTimer *timer_1000ms;
    QTimer *timer_5000ms;

    QTime ROSServer_pingtimer;
    QTime Rover_pingtimer;
    QTime DSRouter_timer;

    std::vector<ControlGroup> controlgroups;
    ControlGroup current_cg;
    std::vector<Port> ports;

    quint64 rx_image_counter;
    uint8_t camera_status;
    QImage camera_image;

    //QLabel iRouterActive;

};

#endif // MAINWINDOW_H
