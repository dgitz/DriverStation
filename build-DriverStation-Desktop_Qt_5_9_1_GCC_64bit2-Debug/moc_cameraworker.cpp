/****************************************************************************
** Meta object code from reading C++ file 'cameraworker.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.9.1)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../DriverStation/cameraworker.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'cameraworker.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.9.1. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
struct qt_meta_stringdata_CameraWorker_t {
    QByteArrayData data[10];
    char stringdata0[76];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_CameraWorker_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_CameraWorker_t qt_meta_stringdata_CameraWorker = {
    {
QT_MOC_LITERAL(0, 0, 12), // "CameraWorker"
QT_MOC_LITERAL(1, 13, 8), // "newImage"
QT_MOC_LITERAL(2, 22, 0), // ""
QT_MOC_LITERAL(3, 23, 3), // "img"
QT_MOC_LITERAL(4, 27, 11), // "newGSTImage"
QT_MOC_LITERAL(5, 39, 7), // "guint8*"
QT_MOC_LITERAL(6, 47, 3), // "map"
QT_MOC_LITERAL(7, 51, 13), // "captureImages"
QT_MOC_LITERAL(8, 65, 4), // "stop"
QT_MOC_LITERAL(9, 70, 5) // "reset"

    },
    "CameraWorker\0newImage\0\0img\0newGSTImage\0"
    "guint8*\0map\0captureImages\0stop\0reset"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_CameraWorker[] = {

 // content:
       7,       // revision
       0,       // classname
       0,    0, // classinfo
       5,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       2,       // signalCount

 // signals: name, argc, parameters, tag, flags
       1,    1,   39,    2, 0x06 /* Public */,
       4,    1,   42,    2, 0x06 /* Public */,

 // slots: name, argc, parameters, tag, flags
       7,    0,   45,    2, 0x0a /* Public */,
       8,    0,   46,    2, 0x0a /* Public */,
       9,    0,   47,    2, 0x0a /* Public */,

 // signals: parameters
    QMetaType::Void, QMetaType::QImage,    3,
    QMetaType::Void, 0x80000000 | 5,    6,

 // slots: parameters
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,

       0        // eod
};

void CameraWorker::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        CameraWorker *_t = static_cast<CameraWorker *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->newImage((*reinterpret_cast< QImage(*)>(_a[1]))); break;
        case 1: _t->newGSTImage((*reinterpret_cast< guint8*(*)>(_a[1]))); break;
        case 2: _t->captureImages(); break;
        case 3: _t->stop(); break;
        case 4: _t->reset(); break;
        default: ;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        void **func = reinterpret_cast<void **>(_a[1]);
        {
            typedef void (CameraWorker::*_t)(QImage );
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&CameraWorker::newImage)) {
                *result = 0;
                return;
            }
        }
        {
            typedef void (CameraWorker::*_t)(guint8 * );
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&CameraWorker::newGSTImage)) {
                *result = 1;
                return;
            }
        }
    }
}

const QMetaObject CameraWorker::staticMetaObject = {
    { &QObject::staticMetaObject, qt_meta_stringdata_CameraWorker.data,
      qt_meta_data_CameraWorker,  qt_static_metacall, nullptr, nullptr}
};


const QMetaObject *CameraWorker::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *CameraWorker::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_CameraWorker.stringdata0))
        return static_cast<void*>(const_cast< CameraWorker*>(this));
    return QObject::qt_metacast(_clname);
}

int CameraWorker::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QObject::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 5)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 5;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 5)
            *reinterpret_cast<int*>(_a[0]) = -1;
        _id -= 5;
    }
    return _id;
}

// SIGNAL 0
void CameraWorker::newImage(QImage _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 0, _a);
}

// SIGNAL 1
void CameraWorker::newGSTImage(guint8 * _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 1, _a);
}
QT_WARNING_POP
QT_END_MOC_NAMESPACE
