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
#include <QMessageBox>
#include <QtCharts/QChartView>
#include <QtCharts/QLineSeries>
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
#include <algorithm>

#include <gst/app/gstappsink.h>
#include <glib.h>
//#define OPENCV_ENABLED
#ifdef OPENCV_ENABLED
#include <opencv2/opencv.hpp>
//#include <opencv2/imgproc/imgproc.hpp>
//#include <opencv2/imgcodecs.hpp>
//using namespace cv;
#endif



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

//#define MOCK_CONTROLGROUPDATA
#define TUNINGVIEW_TIMELENGTH_SEC 120.0

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
    std::string get_diagnostictype_string(int);
    struct UDPMessageInfo
    {
        std::string id;
        std::string name;
        uint64_t rx_count;
        uint64_t tx_count;
    };
    struct Icon
    {
        std::string name;
        int current_level_shown;
        std::vector<std::string> icon_image_paths;
    };


public slots:
    void reset_tuningview(const bool);
    void update_tuningview(const ControlGroupValue &cgvalue);
    void update_messageviewer(const Diagnostic &diag);
    void update_systemstate(const SystemState &state);
    void update_armeddisarmed_text(const int);
    void update_diagnosticicons(const std::vector<int>&);
    void update_resource(const Resource &resource);
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

    void b1_pressed();
    void b2_pressed();
    void b3_pressed();
    void b4_pressed();
    void update_CalibrationPanel();
    void update_OperationPanel();
    void update_CalibrationGroup();
    void update_TuningPanel();
    void update_DiagnosticTab();
    void update_mockdata();

    void check_network();
    void read_ControlGroupFile();
    void check_ROSServer_finished(int code, QProcess::ExitStatus status);
    void check_DSRouter_finished(int code, QProcess::ExitStatus status);
    void check_Rover_finished(int code, QProcess::ExitStatus status);
    void bRTH_pressed();

    //SIMULATION CONTROL
    void bSimulationReset(const bool);
    void bSimulationPauseResume(const bool);
    //CAMERA
    void cameraStreamChanged(int v);
    void newCameraImage(QImage,bool);
    void newGSTCameraImage(guint8* map,bool);
    void newCameraStatus(uint8_t);
    void update_cameraoverlay();

    //DIAGNOSTIC WINDOW
    void bDiagnosticFilter_pressed();
    void bDiagnosticIcon_ElectricalButton_pressed();
    void bDiagnosticIcon_SoftwareButton_pressed();
    void bDiagnosticIcon_CommunicationsButton_pressed();
    void bDiagnosticIcon_SensorsButton_pressed();
    void bDiagnosticIcon_ActuatorsButton_pressed();
    void bDiagnosticIcon_DataStorageButton_pressed();
    void bDiagnosticIcon_RemoteControlButton_pressed();
    void bDiagnosticIcon_TargetAcquisitionButton_pressed();
    void bDiagnosticIcon_PoseButton_pressed();
    void bDiagnosticIcon_TimingButton_pressed();
    void bDiagnosticIcon_SystemResourceButton_pressed();

    //TUNING & CALIBRATION VIEW
    void bTransmitTuning(const bool);
    void calibrationtabChanged();
    void calibrate_Axis(const int);
    void calibrate_XAxis(const bool);
    void calibrate_YAxis(const bool);
    void calibrate_ZAxis(const bool);
    void save_calibration(const bool);
    void cancel_calibration(const bool);
    void controlGroupChanged(QString v);
    void bTuningCaptureStart(const bool);
    void bTuningPBigger_pressed();
    void bTuningPSmaller_pressed();
    void bTuningIBigger_pressed();
    void bTuningISmaller_pressed();
    void bTuningDBigger_pressed();
    void bTuningDSmaller_pressed();
    void bTuningPReset_pressed();
    void bTuningIReset_pressed();
    void bTuningDReset_pressed();
    void cbSelectSensorSignal(const bool);
    void cbSelectErrorSignal(const bool);
    void cbSelectCommandSignal(const bool);
    void cbSelectOutputSignal(const bool);
    void cbSelectErrorPercSignal(const bool);
    void cbSelectIntegralErrorSignal(const bool);
    void cbSelectDerivativeErrorSignal(const bool);
    void cbSelectPOutputSignal(const bool);
    void cbSelectIOutputSignal(const bool);
    void cbSelectDOutputSignal(const bool);



signals:
    void new_diagnosticmessage(Diagnostic);
    void new_devicemessage(Device);

public:

    void update_diagnosticicons();
private:
    void keyPressEvent(QKeyEvent * event);
    void init_udpmessageinfo();
    void init_icons();
    int map_diagnosticlevel_toiconindex(int v);
    void update_diagnosticfilter(int v);

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
    int simulation_running;
    std::vector<ControlGroup> controlgroups;
    ControlGroup current_cg;
    std::vector<Port> ports;

    quint64 rx_image_counter;
    uint8_t camera_status;
    QImage camera_image;
    std::vector<Icon> icons;
    std::vector<int> icon_levels;
    int diagnostictype_filter;

    // TUNING CHART STUFF
#ifdef MOCK_CONTROLGROUPDATA
    ControlGroupValue mock_controlgroup_data;
#endif
    bool transmit_tuning;
    bool capture_tuningdata;
    bool lock_tuningview;
    bool controlgroup_view_received;
    double controlgroup_view_starttime;
    QtCharts::QChart *tuning_chart;
    double tuning_chart_yaxis_min;
    double tuning_chart_yaxis_max;
    bool signal_error_enabled;
    bool signal_input_enabled;
    bool signal_command_enabled;
    bool signal_errorperc_enabled;
    bool signal_output_enabled;
    bool signal_integralerror_enabled;
    bool signal_derivativeerror_enabled;
    bool signal_poutput_enabled;
    bool signal_ioutput_enabled;
    bool signal_doutput_enabled;
    double tuning_signal_max;
    double tuning_signal_min;
    double overshoot_perc;
    double undershot_perc;
    QtCharts::QLineSeries *lineseries_zeroline;
    QtCharts::QLineSeries *lineseries_controlgroup_view_command;// = new QLineSeries();
    QtCharts::QLineSeries *lineseries_controlgroup_view_sensor;
    QtCharts::QLineSeries *lineseries_controlgroup_view_error;
    QtCharts::QLineSeries *lineseries_controlgroup_view_error_perc;
    QtCharts::QLineSeries *lineseries_controlgroup_view_output;
    QtCharts::QLineSeries *lineseries_controlgroup_view_integralerror;
    QtCharts::QLineSeries *lineseries_controlgroup_view_derivativeerror;
    QtCharts::QLineSeries *lineseries_controlgroup_view_poutput;
    QtCharts::QLineSeries *lineseries_controlgroup_view_ioutput;
    QtCharts::QLineSeries *lineseries_controlgroup_view_doutput;
    double tuningview_timedelta;
    double sample_time;
    //QtCharts::QLineSeries *m_series;
    //QtCharts::QChart *tuning_chart;

    //QLabel iRouterActive;

};

#endif // MAINWINDOW_H
