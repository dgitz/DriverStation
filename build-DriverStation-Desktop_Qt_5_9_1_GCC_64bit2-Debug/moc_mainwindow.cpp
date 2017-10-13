/****************************************************************************
** Meta object code from reading C++ file 'mainwindow.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.9.1)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../DriverStation/mainwindow.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'mainwindow.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.9.1. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
struct qt_meta_stringdata_MainWindow_t {
    QByteArrayData data[75];
    char stringdata0[1264];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_MainWindow_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_MainWindow_t qt_meta_stringdata_MainWindow = {
    {
QT_MOC_LITERAL(0, 0, 10), // "MainWindow"
QT_MOC_LITERAL(1, 11, 21), // "new_diagnosticmessage"
QT_MOC_LITERAL(2, 33, 0), // ""
QT_MOC_LITERAL(3, 34, 10), // "Diagnostic"
QT_MOC_LITERAL(4, 45, 17), // "new_devicemessage"
QT_MOC_LITERAL(5, 63, 6), // "Device"
QT_MOC_LITERAL(6, 70, 20), // "update_messageviewer"
QT_MOC_LITERAL(7, 91, 4), // "diag"
QT_MOC_LITERAL(8, 96, 25), // "update_armeddisarmed_text"
QT_MOC_LITERAL(9, 122, 16), // "kill_application"
QT_MOC_LITERAL(10, 139, 11), // "stop_system"
QT_MOC_LITERAL(11, 151, 13), // "launch_system"
QT_MOC_LITERAL(12, 165, 19), // "clear_messageviewer"
QT_MOC_LITERAL(13, 185, 26), // "changefilter_messageviewer"
QT_MOC_LITERAL(14, 212, 25), // "clearfilter_messageviewer"
QT_MOC_LITERAL(15, 238, 17), // "update_devicelist"
QT_MOC_LITERAL(16, 256, 6), // "device"
QT_MOC_LITERAL(17, 263, 13), // "read_joystick"
QT_MOC_LITERAL(18, 277, 31), // "check_set_allcontrols_todefault"
QT_MOC_LITERAL(19, 309, 23), // "update_devicelistviewer"
QT_MOC_LITERAL(20, 333, 16), // "change_RC_Server"
QT_MOC_LITERAL(21, 350, 3), // "set"
QT_MOC_LITERAL(22, 354, 17), // "update_commstatus"
QT_MOC_LITERAL(23, 372, 15), // "send_RC_message"
QT_MOC_LITERAL(24, 388, 23), // "send_ArmControl_message"
QT_MOC_LITERAL(25, 412, 24), // "send_Arm_Command_message"
QT_MOC_LITERAL(26, 437, 22), // "send_Heartbeat_message"
QT_MOC_LITERAL(27, 460, 18), // "bArmDisarm_pressed"
QT_MOC_LITERAL(28, 479, 12), // "update_estop"
QT_MOC_LITERAL(29, 492, 5), // "EStop"
QT_MOC_LITERAL(30, 498, 5), // "estop"
QT_MOC_LITERAL(31, 504, 14), // "maintabChanged"
QT_MOC_LITERAL(32, 519, 21), // "calibrationtabChanged"
QT_MOC_LITERAL(33, 541, 10), // "b1_pressed"
QT_MOC_LITERAL(34, 552, 10), // "b2_pressed"
QT_MOC_LITERAL(35, 563, 10), // "b3_pressed"
QT_MOC_LITERAL(36, 574, 10), // "b4_pressed"
QT_MOC_LITERAL(37, 585, 23), // "update_CalibrationPanel"
QT_MOC_LITERAL(38, 609, 21), // "update_OperationPanel"
QT_MOC_LITERAL(39, 631, 23), // "update_CalibrationGroup"
QT_MOC_LITERAL(40, 655, 18), // "update_TuningPanel"
QT_MOC_LITERAL(41, 674, 14), // "calibrate_Axis"
QT_MOC_LITERAL(42, 689, 15), // "calibrate_XAxis"
QT_MOC_LITERAL(43, 705, 15), // "calibrate_YAxis"
QT_MOC_LITERAL(44, 721, 15), // "calibrate_ZAxis"
QT_MOC_LITERAL(45, 737, 16), // "save_calibration"
QT_MOC_LITERAL(46, 754, 18), // "cancel_calibration"
QT_MOC_LITERAL(47, 773, 13), // "check_network"
QT_MOC_LITERAL(48, 787, 21), // "read_ControlGroupFile"
QT_MOC_LITERAL(49, 809, 24), // "check_ROSServer_finished"
QT_MOC_LITERAL(50, 834, 4), // "code"
QT_MOC_LITERAL(51, 839, 20), // "QProcess::ExitStatus"
QT_MOC_LITERAL(52, 860, 6), // "status"
QT_MOC_LITERAL(53, 867, 23), // "check_DSRouter_finished"
QT_MOC_LITERAL(54, 891, 20), // "check_Rover_finished"
QT_MOC_LITERAL(55, 912, 12), // "bRTH_pressed"
QT_MOC_LITERAL(56, 925, 19), // "controlGroupChanged"
QT_MOC_LITERAL(57, 945, 1), // "v"
QT_MOC_LITERAL(58, 947, 19), // "cameraStreamChanged"
QT_MOC_LITERAL(59, 967, 22), // "bTuningPBigger_pressed"
QT_MOC_LITERAL(60, 990, 23), // "bTuningPSmaller_pressed"
QT_MOC_LITERAL(61, 1014, 22), // "bTuningIBigger_pressed"
QT_MOC_LITERAL(62, 1037, 23), // "bTuningISmaller_pressed"
QT_MOC_LITERAL(63, 1061, 22), // "bTuningDBigger_pressed"
QT_MOC_LITERAL(64, 1084, 23), // "bTuningDSmaller_pressed"
QT_MOC_LITERAL(65, 1108, 21), // "bTuningPReset_pressed"
QT_MOC_LITERAL(66, 1130, 21), // "bTuningIReset_pressed"
QT_MOC_LITERAL(67, 1152, 21), // "bTuningDReset_pressed"
QT_MOC_LITERAL(68, 1174, 14), // "newCameraImage"
QT_MOC_LITERAL(69, 1189, 17), // "newGSTCameraImage"
QT_MOC_LITERAL(70, 1207, 7), // "guint8*"
QT_MOC_LITERAL(71, 1215, 3), // "map"
QT_MOC_LITERAL(72, 1219, 15), // "newCameraStatus"
QT_MOC_LITERAL(73, 1235, 7), // "uint8_t"
QT_MOC_LITERAL(74, 1243, 20) // "update_cameraoverlay"

    },
    "MainWindow\0new_diagnosticmessage\0\0"
    "Diagnostic\0new_devicemessage\0Device\0"
    "update_messageviewer\0diag\0"
    "update_armeddisarmed_text\0kill_application\0"
    "stop_system\0launch_system\0clear_messageviewer\0"
    "changefilter_messageviewer\0"
    "clearfilter_messageviewer\0update_devicelist\0"
    "device\0read_joystick\0"
    "check_set_allcontrols_todefault\0"
    "update_devicelistviewer\0change_RC_Server\0"
    "set\0update_commstatus\0send_RC_message\0"
    "send_ArmControl_message\0"
    "send_Arm_Command_message\0"
    "send_Heartbeat_message\0bArmDisarm_pressed\0"
    "update_estop\0EStop\0estop\0maintabChanged\0"
    "calibrationtabChanged\0b1_pressed\0"
    "b2_pressed\0b3_pressed\0b4_pressed\0"
    "update_CalibrationPanel\0update_OperationPanel\0"
    "update_CalibrationGroup\0update_TuningPanel\0"
    "calibrate_Axis\0calibrate_XAxis\0"
    "calibrate_YAxis\0calibrate_ZAxis\0"
    "save_calibration\0cancel_calibration\0"
    "check_network\0read_ControlGroupFile\0"
    "check_ROSServer_finished\0code\0"
    "QProcess::ExitStatus\0status\0"
    "check_DSRouter_finished\0check_Rover_finished\0"
    "bRTH_pressed\0controlGroupChanged\0v\0"
    "cameraStreamChanged\0bTuningPBigger_pressed\0"
    "bTuningPSmaller_pressed\0bTuningIBigger_pressed\0"
    "bTuningISmaller_pressed\0bTuningDBigger_pressed\0"
    "bTuningDSmaller_pressed\0bTuningPReset_pressed\0"
    "bTuningIReset_pressed\0bTuningDReset_pressed\0"
    "newCameraImage\0newGSTCameraImage\0"
    "guint8*\0map\0newCameraStatus\0uint8_t\0"
    "update_cameraoverlay"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_MainWindow[] = {

 // content:
       7,       // revision
       0,       // classname
       0,    0, // classinfo
      61,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       2,       // signalCount

 // signals: name, argc, parameters, tag, flags
       1,    1,  319,    2, 0x06 /* Public */,
       4,    1,  322,    2, 0x06 /* Public */,

 // slots: name, argc, parameters, tag, flags
       6,    1,  325,    2, 0x0a /* Public */,
       8,    1,  328,    2, 0x0a /* Public */,
       9,    1,  331,    2, 0x0a /* Public */,
      10,    1,  334,    2, 0x0a /* Public */,
      11,    1,  337,    2, 0x0a /* Public */,
      12,    1,  340,    2, 0x0a /* Public */,
      13,    0,  343,    2, 0x0a /* Public */,
      14,    0,  344,    2, 0x0a /* Public */,
      15,    1,  345,    2, 0x0a /* Public */,
      15,    1,  348,    2, 0x0a /* Public */,
      17,    0,  351,    2, 0x0a /* Public */,
      18,    0,  352,    2, 0x0a /* Public */,
      15,    0,  353,    2, 0x0a /* Public */,
      19,    0,  354,    2, 0x0a /* Public */,
      20,    1,  355,    2, 0x0a /* Public */,
      22,    0,  358,    2, 0x0a /* Public */,
      23,    1,  359,    2, 0x0a /* Public */,
      24,    1,  362,    2, 0x0a /* Public */,
      25,    1,  365,    2, 0x0a /* Public */,
      26,    0,  368,    2, 0x0a /* Public */,
      27,    0,  369,    2, 0x0a /* Public */,
      28,    1,  370,    2, 0x0a /* Public */,
      31,    0,  373,    2, 0x0a /* Public */,
      32,    0,  374,    2, 0x0a /* Public */,
      33,    0,  375,    2, 0x0a /* Public */,
      34,    0,  376,    2, 0x0a /* Public */,
      35,    0,  377,    2, 0x0a /* Public */,
      36,    0,  378,    2, 0x0a /* Public */,
      37,    0,  379,    2, 0x0a /* Public */,
      38,    0,  380,    2, 0x0a /* Public */,
      39,    0,  381,    2, 0x0a /* Public */,
      40,    0,  382,    2, 0x0a /* Public */,
      41,    1,  383,    2, 0x0a /* Public */,
      42,    1,  386,    2, 0x0a /* Public */,
      43,    1,  389,    2, 0x0a /* Public */,
      44,    1,  392,    2, 0x0a /* Public */,
      45,    1,  395,    2, 0x0a /* Public */,
      46,    1,  398,    2, 0x0a /* Public */,
      47,    0,  401,    2, 0x0a /* Public */,
      48,    0,  402,    2, 0x0a /* Public */,
      49,    2,  403,    2, 0x0a /* Public */,
      53,    2,  408,    2, 0x0a /* Public */,
      54,    2,  413,    2, 0x0a /* Public */,
      55,    0,  418,    2, 0x0a /* Public */,
      56,    1,  419,    2, 0x0a /* Public */,
      58,    1,  422,    2, 0x0a /* Public */,
      59,    0,  425,    2, 0x0a /* Public */,
      60,    0,  426,    2, 0x0a /* Public */,
      61,    0,  427,    2, 0x0a /* Public */,
      62,    0,  428,    2, 0x0a /* Public */,
      63,    0,  429,    2, 0x0a /* Public */,
      64,    0,  430,    2, 0x0a /* Public */,
      65,    0,  431,    2, 0x0a /* Public */,
      66,    0,  432,    2, 0x0a /* Public */,
      67,    0,  433,    2, 0x0a /* Public */,
      68,    2,  434,    2, 0x0a /* Public */,
      69,    2,  439,    2, 0x0a /* Public */,
      72,    1,  444,    2, 0x0a /* Public */,
      74,    0,  447,    2, 0x0a /* Public */,

 // signals: parameters
    QMetaType::Void, 0x80000000 | 3,    2,
    QMetaType::Void, 0x80000000 | 5,    2,

 // slots: parameters
    QMetaType::Void, 0x80000000 | 3,    7,
    QMetaType::Void, QMetaType::Int,    2,
    QMetaType::Void, QMetaType::Bool,    2,
    QMetaType::Void, QMetaType::Bool,    2,
    QMetaType::Void, QMetaType::Bool,    2,
    QMetaType::Void, QMetaType::QString,    2,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void, 0x80000000 | 3,    7,
    QMetaType::Void, 0x80000000 | 5,   16,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void, QMetaType::Bool,   21,
    QMetaType::Void,
    QMetaType::Void, QMetaType::Int,    2,
    QMetaType::Void, QMetaType::Int,    2,
    QMetaType::Void, QMetaType::Int,    2,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void, 0x80000000 | 29,   30,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void, QMetaType::Int,    2,
    QMetaType::Void, QMetaType::Bool,    2,
    QMetaType::Void, QMetaType::Bool,    2,
    QMetaType::Void, QMetaType::Bool,    2,
    QMetaType::Void, QMetaType::Bool,    2,
    QMetaType::Void, QMetaType::Bool,    2,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void, QMetaType::Int, 0x80000000 | 51,   50,   52,
    QMetaType::Void, QMetaType::Int, 0x80000000 | 51,   50,   52,
    QMetaType::Void, QMetaType::Int, 0x80000000 | 51,   50,   52,
    QMetaType::Void,
    QMetaType::Void, QMetaType::QString,   57,
    QMetaType::Void, QMetaType::Int,   57,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void, QMetaType::QImage, QMetaType::Bool,    2,    2,
    QMetaType::Void, 0x80000000 | 70, QMetaType::Bool,   71,    2,
    QMetaType::Void, 0x80000000 | 73,    2,
    QMetaType::Void,

       0        // eod
};

void MainWindow::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        MainWindow *_t = static_cast<MainWindow *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->new_diagnosticmessage((*reinterpret_cast< Diagnostic(*)>(_a[1]))); break;
        case 1: _t->new_devicemessage((*reinterpret_cast< Device(*)>(_a[1]))); break;
        case 2: _t->update_messageviewer((*reinterpret_cast< const Diagnostic(*)>(_a[1]))); break;
        case 3: _t->update_armeddisarmed_text((*reinterpret_cast< const int(*)>(_a[1]))); break;
        case 4: _t->kill_application((*reinterpret_cast< const bool(*)>(_a[1]))); break;
        case 5: _t->stop_system((*reinterpret_cast< const bool(*)>(_a[1]))); break;
        case 6: _t->launch_system((*reinterpret_cast< const bool(*)>(_a[1]))); break;
        case 7: _t->clear_messageviewer((*reinterpret_cast< const QString(*)>(_a[1]))); break;
        case 8: _t->changefilter_messageviewer(); break;
        case 9: _t->clearfilter_messageviewer(); break;
        case 10: _t->update_devicelist((*reinterpret_cast< const Diagnostic(*)>(_a[1]))); break;
        case 11: _t->update_devicelist((*reinterpret_cast< const Device(*)>(_a[1]))); break;
        case 12: _t->read_joystick(); break;
        case 13: _t->check_set_allcontrols_todefault(); break;
        case 14: _t->update_devicelist(); break;
        case 15: _t->update_devicelistviewer(); break;
        case 16: _t->change_RC_Server((*reinterpret_cast< bool(*)>(_a[1]))); break;
        case 17: _t->update_commstatus(); break;
        case 18: _t->send_RC_message((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 19: _t->send_ArmControl_message((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 20: _t->send_Arm_Command_message((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 21: _t->send_Heartbeat_message(); break;
        case 22: _t->bArmDisarm_pressed(); break;
        case 23: _t->update_estop((*reinterpret_cast< EStop(*)>(_a[1]))); break;
        case 24: _t->maintabChanged(); break;
        case 25: _t->calibrationtabChanged(); break;
        case 26: _t->b1_pressed(); break;
        case 27: _t->b2_pressed(); break;
        case 28: _t->b3_pressed(); break;
        case 29: _t->b4_pressed(); break;
        case 30: _t->update_CalibrationPanel(); break;
        case 31: _t->update_OperationPanel(); break;
        case 32: _t->update_CalibrationGroup(); break;
        case 33: _t->update_TuningPanel(); break;
        case 34: _t->calibrate_Axis((*reinterpret_cast< const int(*)>(_a[1]))); break;
        case 35: _t->calibrate_XAxis((*reinterpret_cast< const bool(*)>(_a[1]))); break;
        case 36: _t->calibrate_YAxis((*reinterpret_cast< const bool(*)>(_a[1]))); break;
        case 37: _t->calibrate_ZAxis((*reinterpret_cast< const bool(*)>(_a[1]))); break;
        case 38: _t->save_calibration((*reinterpret_cast< const bool(*)>(_a[1]))); break;
        case 39: _t->cancel_calibration((*reinterpret_cast< const bool(*)>(_a[1]))); break;
        case 40: _t->check_network(); break;
        case 41: _t->read_ControlGroupFile(); break;
        case 42: _t->check_ROSServer_finished((*reinterpret_cast< int(*)>(_a[1])),(*reinterpret_cast< QProcess::ExitStatus(*)>(_a[2]))); break;
        case 43: _t->check_DSRouter_finished((*reinterpret_cast< int(*)>(_a[1])),(*reinterpret_cast< QProcess::ExitStatus(*)>(_a[2]))); break;
        case 44: _t->check_Rover_finished((*reinterpret_cast< int(*)>(_a[1])),(*reinterpret_cast< QProcess::ExitStatus(*)>(_a[2]))); break;
        case 45: _t->bRTH_pressed(); break;
        case 46: _t->controlGroupChanged((*reinterpret_cast< QString(*)>(_a[1]))); break;
        case 47: _t->cameraStreamChanged((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 48: _t->bTuningPBigger_pressed(); break;
        case 49: _t->bTuningPSmaller_pressed(); break;
        case 50: _t->bTuningIBigger_pressed(); break;
        case 51: _t->bTuningISmaller_pressed(); break;
        case 52: _t->bTuningDBigger_pressed(); break;
        case 53: _t->bTuningDSmaller_pressed(); break;
        case 54: _t->bTuningPReset_pressed(); break;
        case 55: _t->bTuningIReset_pressed(); break;
        case 56: _t->bTuningDReset_pressed(); break;
        case 57: _t->newCameraImage((*reinterpret_cast< QImage(*)>(_a[1])),(*reinterpret_cast< bool(*)>(_a[2]))); break;
        case 58: _t->newGSTCameraImage((*reinterpret_cast< guint8*(*)>(_a[1])),(*reinterpret_cast< bool(*)>(_a[2]))); break;
        case 59: _t->newCameraStatus((*reinterpret_cast< uint8_t(*)>(_a[1]))); break;
        case 60: _t->update_cameraoverlay(); break;
        default: ;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        void **func = reinterpret_cast<void **>(_a[1]);
        {
            typedef void (MainWindow::*_t)(Diagnostic );
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&MainWindow::new_diagnosticmessage)) {
                *result = 0;
                return;
            }
        }
        {
            typedef void (MainWindow::*_t)(Device );
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&MainWindow::new_devicemessage)) {
                *result = 1;
                return;
            }
        }
    }
}

const QMetaObject MainWindow::staticMetaObject = {
    { &QMainWindow::staticMetaObject, qt_meta_stringdata_MainWindow.data,
      qt_meta_data_MainWindow,  qt_static_metacall, nullptr, nullptr}
};


const QMetaObject *MainWindow::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *MainWindow::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_MainWindow.stringdata0))
        return static_cast<void*>(const_cast< MainWindow*>(this));
    return QMainWindow::qt_metacast(_clname);
}

int MainWindow::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QMainWindow::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 61)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 61;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 61)
            *reinterpret_cast<int*>(_a[0]) = -1;
        _id -= 61;
    }
    return _id;
}

// SIGNAL 0
void MainWindow::new_diagnosticmessage(Diagnostic _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 0, _a);
}

// SIGNAL 1
void MainWindow::new_devicemessage(Device _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 1, _a);
}
QT_WARNING_POP
QT_END_MOC_NAMESPACE
