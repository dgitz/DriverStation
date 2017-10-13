/****************************************************************************
** Meta object code from reading C++ file 'udpreceiver.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.9.1)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../DriverStation/udpreceiver.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'udpreceiver.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.9.1. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
struct qt_meta_stringdata_UDPReceiver_t {
    QByteArrayData data[13];
    char stringdata0[173];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_UDPReceiver_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_UDPReceiver_t qt_meta_stringdata_UDPReceiver = {
    {
QT_MOC_LITERAL(0, 0, 11), // "UDPReceiver"
QT_MOC_LITERAL(1, 12, 21), // "new_diagnosticmessage"
QT_MOC_LITERAL(2, 34, 0), // ""
QT_MOC_LITERAL(3, 35, 10), // "Diagnostic"
QT_MOC_LITERAL(4, 46, 17), // "new_devicemessage"
QT_MOC_LITERAL(5, 64, 6), // "Device"
QT_MOC_LITERAL(6, 71, 19), // "new_resourcemessage"
QT_MOC_LITERAL(7, 91, 8), // "Resource"
QT_MOC_LITERAL(8, 100, 22), // "new_armedstatusmessage"
QT_MOC_LITERAL(9, 123, 9), // "new_image"
QT_MOC_LITERAL(10, 133, 9), // "new_estop"
QT_MOC_LITERAL(11, 143, 5), // "EStop"
QT_MOC_LITERAL(12, 149, 23) // "processPendingDatagrams"

    },
    "UDPReceiver\0new_diagnosticmessage\0\0"
    "Diagnostic\0new_devicemessage\0Device\0"
    "new_resourcemessage\0Resource\0"
    "new_armedstatusmessage\0new_image\0"
    "new_estop\0EStop\0processPendingDatagrams"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_UDPReceiver[] = {

 // content:
       7,       // revision
       0,       // classname
       0,    0, // classinfo
       7,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       6,       // signalCount

 // signals: name, argc, parameters, tag, flags
       1,    1,   49,    2, 0x06 /* Public */,
       4,    1,   52,    2, 0x06 /* Public */,
       6,    1,   55,    2, 0x06 /* Public */,
       8,    1,   58,    2, 0x06 /* Public */,
       9,    1,   61,    2, 0x06 /* Public */,
      10,    1,   64,    2, 0x06 /* Public */,

 // slots: name, argc, parameters, tag, flags
      12,    0,   67,    2, 0x08 /* Private */,

 // signals: parameters
    QMetaType::Void, 0x80000000 | 3,    2,
    QMetaType::Void, 0x80000000 | 5,    2,
    QMetaType::Void, 0x80000000 | 7,    2,
    QMetaType::Void, QMetaType::Int,    2,
    QMetaType::Void, QMetaType::QPixmap,    2,
    QMetaType::Void, 0x80000000 | 11,    2,

 // slots: parameters
    QMetaType::Void,

       0        // eod
};

void UDPReceiver::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        UDPReceiver *_t = static_cast<UDPReceiver *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->new_diagnosticmessage((*reinterpret_cast< const Diagnostic(*)>(_a[1]))); break;
        case 1: _t->new_devicemessage((*reinterpret_cast< const Device(*)>(_a[1]))); break;
        case 2: _t->new_resourcemessage((*reinterpret_cast< const Resource(*)>(_a[1]))); break;
        case 3: _t->new_armedstatusmessage((*reinterpret_cast< const int(*)>(_a[1]))); break;
        case 4: _t->new_image((*reinterpret_cast< const QPixmap(*)>(_a[1]))); break;
        case 5: _t->new_estop((*reinterpret_cast< const EStop(*)>(_a[1]))); break;
        case 6: _t->processPendingDatagrams(); break;
        default: ;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        void **func = reinterpret_cast<void **>(_a[1]);
        {
            typedef void (UDPReceiver::*_t)(const Diagnostic & );
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&UDPReceiver::new_diagnosticmessage)) {
                *result = 0;
                return;
            }
        }
        {
            typedef void (UDPReceiver::*_t)(const Device & );
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&UDPReceiver::new_devicemessage)) {
                *result = 1;
                return;
            }
        }
        {
            typedef void (UDPReceiver::*_t)(const Resource & );
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&UDPReceiver::new_resourcemessage)) {
                *result = 2;
                return;
            }
        }
        {
            typedef void (UDPReceiver::*_t)(const int & );
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&UDPReceiver::new_armedstatusmessage)) {
                *result = 3;
                return;
            }
        }
        {
            typedef void (UDPReceiver::*_t)(const QPixmap & );
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&UDPReceiver::new_image)) {
                *result = 4;
                return;
            }
        }
        {
            typedef void (UDPReceiver::*_t)(const EStop & );
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&UDPReceiver::new_estop)) {
                *result = 5;
                return;
            }
        }
    }
}

const QMetaObject UDPReceiver::staticMetaObject = {
    { &QObject::staticMetaObject, qt_meta_stringdata_UDPReceiver.data,
      qt_meta_data_UDPReceiver,  qt_static_metacall, nullptr, nullptr}
};


const QMetaObject *UDPReceiver::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *UDPReceiver::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_UDPReceiver.stringdata0))
        return static_cast<void*>(const_cast< UDPReceiver*>(this));
    return QObject::qt_metacast(_clname);
}

int UDPReceiver::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QObject::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 7)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 7;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 7)
            *reinterpret_cast<int*>(_a[0]) = -1;
        _id -= 7;
    }
    return _id;
}

// SIGNAL 0
void UDPReceiver::new_diagnosticmessage(const Diagnostic & _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 0, _a);
}

// SIGNAL 1
void UDPReceiver::new_devicemessage(const Device & _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 1, _a);
}

// SIGNAL 2
void UDPReceiver::new_resourcemessage(const Resource & _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 2, _a);
}

// SIGNAL 3
void UDPReceiver::new_armedstatusmessage(const int & _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 3, _a);
}

// SIGNAL 4
void UDPReceiver::new_image(const QPixmap & _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 4, _a);
}

// SIGNAL 5
void UDPReceiver::new_estop(const EStop & _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 5, _a);
}
QT_WARNING_POP
QT_END_MOC_NAMESPACE
