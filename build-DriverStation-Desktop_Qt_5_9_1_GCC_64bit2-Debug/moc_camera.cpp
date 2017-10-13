/****************************************************************************
** Meta object code from reading C++ file 'camera.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.9.1)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../DriverStation/camera.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'camera.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.9.1. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
struct qt_meta_stringdata_Camera_t {
    QByteArrayData data[21];
    char stringdata0[205];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_Camera_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_Camera_t qt_meta_stringdata_Camera = {
    {
QT_MOC_LITERAL(0, 0, 6), // "Camera"
QT_MOC_LITERAL(1, 7, 13), // "newFrameReady"
QT_MOC_LITERAL(2, 21, 0), // ""
QT_MOC_LITERAL(3, 22, 3), // "img"
QT_MOC_LITERAL(4, 26, 5), // "error"
QT_MOC_LITERAL(5, 32, 16), // "newGSTFrameReady"
QT_MOC_LITERAL(6, 49, 7), // "guint8*"
QT_MOC_LITERAL(7, 57, 3), // "map"
QT_MOC_LITERAL(8, 61, 13), // "captureImages"
QT_MOC_LITERAL(9, 75, 17), // "stopCaptureImages"
QT_MOC_LITERAL(10, 93, 5), // "reset"
QT_MOC_LITERAL(11, 99, 13), // "camera_status"
QT_MOC_LITERAL(12, 113, 7), // "uint8_t"
QT_MOC_LITERAL(13, 121, 12), // "startCapture"
QT_MOC_LITERAL(14, 134, 11), // "std::string"
QT_MOC_LITERAL(15, 146, 9), // "ipaddress"
QT_MOC_LITERAL(16, 156, 8), // "uint32_t"
QT_MOC_LITERAL(17, 165, 4), // "port"
QT_MOC_LITERAL(18, 170, 7), // "timeOut"
QT_MOC_LITERAL(19, 178, 11), // "setNewImage"
QT_MOC_LITERAL(20, 190, 14) // "setNewGSTImage"

    },
    "Camera\0newFrameReady\0\0img\0error\0"
    "newGSTFrameReady\0guint8*\0map\0captureImages\0"
    "stopCaptureImages\0reset\0camera_status\0"
    "uint8_t\0startCapture\0std::string\0"
    "ipaddress\0uint32_t\0port\0timeOut\0"
    "setNewImage\0setNewGSTImage"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_Camera[] = {

 // content:
       7,       // revision
       0,       // classname
       0,    0, // classinfo
      12,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       8,       // signalCount

 // signals: name, argc, parameters, tag, flags
       1,    2,   74,    2, 0x06 /* Public */,
       1,    1,   79,    2, 0x26 /* Public | MethodCloned */,
       5,    2,   82,    2, 0x06 /* Public */,
       5,    1,   87,    2, 0x26 /* Public | MethodCloned */,
       8,    0,   90,    2, 0x06 /* Public */,
       9,    0,   91,    2, 0x06 /* Public */,
      10,    0,   92,    2, 0x06 /* Public */,
      11,    1,   93,    2, 0x06 /* Public */,

 // slots: name, argc, parameters, tag, flags
      13,    2,   96,    2, 0x0a /* Public */,
      18,    0,  101,    2, 0x08 /* Private */,
      19,    1,  102,    2, 0x08 /* Private */,
      20,    1,  105,    2, 0x08 /* Private */,

 // signals: parameters
    QMetaType::Void, QMetaType::QImage, QMetaType::Bool,    3,    4,
    QMetaType::Void, QMetaType::QImage,    3,
    QMetaType::Void, 0x80000000 | 6, QMetaType::Bool,    7,    4,
    QMetaType::Void, 0x80000000 | 6,    7,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void, 0x80000000 | 12,    2,

 // slots: parameters
    QMetaType::Void, 0x80000000 | 14, 0x80000000 | 16,   15,   17,
    QMetaType::Void,
    QMetaType::Void, QMetaType::QImage,    3,
    QMetaType::Void, 0x80000000 | 6,    7,

       0        // eod
};

void Camera::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        Camera *_t = static_cast<Camera *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->newFrameReady((*reinterpret_cast< QImage(*)>(_a[1])),(*reinterpret_cast< bool(*)>(_a[2]))); break;
        case 1: _t->newFrameReady((*reinterpret_cast< QImage(*)>(_a[1]))); break;
        case 2: _t->newGSTFrameReady((*reinterpret_cast< guint8*(*)>(_a[1])),(*reinterpret_cast< bool(*)>(_a[2]))); break;
        case 3: _t->newGSTFrameReady((*reinterpret_cast< guint8*(*)>(_a[1]))); break;
        case 4: _t->captureImages(); break;
        case 5: _t->stopCaptureImages(); break;
        case 6: _t->reset(); break;
        case 7: _t->camera_status((*reinterpret_cast< uint8_t(*)>(_a[1]))); break;
        case 8: _t->startCapture((*reinterpret_cast< std::string(*)>(_a[1])),(*reinterpret_cast< uint32_t(*)>(_a[2]))); break;
        case 9: _t->timeOut(); break;
        case 10: _t->setNewImage((*reinterpret_cast< QImage(*)>(_a[1]))); break;
        case 11: _t->setNewGSTImage((*reinterpret_cast< guint8*(*)>(_a[1]))); break;
        default: ;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        void **func = reinterpret_cast<void **>(_a[1]);
        {
            typedef void (Camera::*_t)(QImage , bool );
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&Camera::newFrameReady)) {
                *result = 0;
                return;
            }
        }
        {
            typedef void (Camera::*_t)(guint8 * , bool );
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&Camera::newGSTFrameReady)) {
                *result = 2;
                return;
            }
        }
        {
            typedef void (Camera::*_t)();
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&Camera::captureImages)) {
                *result = 4;
                return;
            }
        }
        {
            typedef void (Camera::*_t)();
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&Camera::stopCaptureImages)) {
                *result = 5;
                return;
            }
        }
        {
            typedef void (Camera::*_t)();
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&Camera::reset)) {
                *result = 6;
                return;
            }
        }
        {
            typedef void (Camera::*_t)(uint8_t );
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&Camera::camera_status)) {
                *result = 7;
                return;
            }
        }
    }
}

const QMetaObject Camera::staticMetaObject = {
    { &QObject::staticMetaObject, qt_meta_stringdata_Camera.data,
      qt_meta_data_Camera,  qt_static_metacall, nullptr, nullptr}
};


const QMetaObject *Camera::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *Camera::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_Camera.stringdata0))
        return static_cast<void*>(const_cast< Camera*>(this));
    return QObject::qt_metacast(_clname);
}

int Camera::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QObject::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 12)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 12;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 12)
            *reinterpret_cast<int*>(_a[0]) = -1;
        _id -= 12;
    }
    return _id;
}

// SIGNAL 0
void Camera::newFrameReady(QImage _t1, bool _t2)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(&_t1)), const_cast<void*>(reinterpret_cast<const void*>(&_t2)) };
    QMetaObject::activate(this, &staticMetaObject, 0, _a);
}

// SIGNAL 2
void Camera::newGSTFrameReady(guint8 * _t1, bool _t2)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(&_t1)), const_cast<void*>(reinterpret_cast<const void*>(&_t2)) };
    QMetaObject::activate(this, &staticMetaObject, 2, _a);
}

// SIGNAL 4
void Camera::captureImages()
{
    QMetaObject::activate(this, &staticMetaObject, 4, nullptr);
}

// SIGNAL 5
void Camera::stopCaptureImages()
{
    QMetaObject::activate(this, &staticMetaObject, 5, nullptr);
}

// SIGNAL 6
void Camera::reset()
{
    QMetaObject::activate(this, &staticMetaObject, 6, nullptr);
}

// SIGNAL 7
void Camera::camera_status(uint8_t _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 7, _a);
}
QT_WARNING_POP
QT_END_MOC_NAMESPACE
