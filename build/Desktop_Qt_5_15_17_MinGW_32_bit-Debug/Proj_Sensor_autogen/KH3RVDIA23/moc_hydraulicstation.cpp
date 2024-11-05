/****************************************************************************
** Meta object code from reading C++ file 'hydraulicstation.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.15.17)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include <memory>
#include "../../../../devices/hydraulicstation.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#include <QtCore/QVector>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'hydraulicstation.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.15.17. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
struct qt_meta_stringdata_HydraulicStation_t {
    QByteArrayData data[11];
    char stringdata0[171];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_HydraulicStation_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_HydraulicStation_t qt_meta_stringdata_HydraulicStation = {
    {
QT_MOC_LITERAL(0, 0, 16), // "HydraulicStation"
QT_MOC_LITERAL(1, 17, 29), // "signal_set_config_serial_port"
QT_MOC_LITERAL(2, 47, 0), // ""
QT_MOC_LITERAL(3, 48, 24), // "signal_close_seriao_port"
QT_MOC_LITERAL(4, 73, 16), // "send_press_to_ui"
QT_MOC_LITERAL(5, 90, 15), // "QVector<double>"
QT_MOC_LITERAL(6, 106, 4), // "data"
QT_MOC_LITERAL(7, 111, 15), // "get_serial_data"
QT_MOC_LITERAL(8, 127, 8), // "rev_data"
QT_MOC_LITERAL(9, 136, 17), // "get_config_signal"
QT_MOC_LITERAL(10, 154, 16) // "get_close_signal"

    },
    "HydraulicStation\0signal_set_config_serial_port\0"
    "\0signal_close_seriao_port\0send_press_to_ui\0"
    "QVector<double>\0data\0get_serial_data\0"
    "rev_data\0get_config_signal\0get_close_signal"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_HydraulicStation[] = {

 // content:
       8,       // revision
       0,       // classname
       0,    0, // classinfo
       6,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       3,       // signalCount

 // signals: name, argc, parameters, tag, flags
       1,    0,   44,    2, 0x06 /* Public */,
       3,    0,   45,    2, 0x06 /* Public */,
       4,    1,   46,    2, 0x06 /* Public */,

 // slots: name, argc, parameters, tag, flags
       7,    1,   49,    2, 0x0a /* Public */,
       9,    0,   52,    2, 0x0a /* Public */,
      10,    0,   53,    2, 0x0a /* Public */,

 // signals: parameters
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void, 0x80000000 | 5,    6,

 // slots: parameters
    QMetaType::Void, QMetaType::QString,    8,
    QMetaType::Void,
    QMetaType::Void,

       0        // eod
};

void HydraulicStation::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        auto *_t = static_cast<HydraulicStation *>(_o);
        (void)_t;
        switch (_id) {
        case 0: _t->signal_set_config_serial_port(); break;
        case 1: _t->signal_close_seriao_port(); break;
        case 2: _t->send_press_to_ui((*reinterpret_cast< QVector<double>(*)>(_a[1]))); break;
        case 3: _t->get_serial_data((*reinterpret_cast< QString(*)>(_a[1]))); break;
        case 4: _t->get_config_signal(); break;
        case 5: _t->get_close_signal(); break;
        default: ;
        }
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        switch (_id) {
        default: *reinterpret_cast<int*>(_a[0]) = -1; break;
        case 2:
            switch (*reinterpret_cast<int*>(_a[1])) {
            default: *reinterpret_cast<int*>(_a[0]) = -1; break;
            case 0:
                *reinterpret_cast<int*>(_a[0]) = qRegisterMetaType< QVector<double> >(); break;
            }
            break;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        {
            using _t = void (HydraulicStation::*)();
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&HydraulicStation::signal_set_config_serial_port)) {
                *result = 0;
                return;
            }
        }
        {
            using _t = void (HydraulicStation::*)();
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&HydraulicStation::signal_close_seriao_port)) {
                *result = 1;
                return;
            }
        }
        {
            using _t = void (HydraulicStation::*)(QVector<double> );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&HydraulicStation::send_press_to_ui)) {
                *result = 2;
                return;
            }
        }
    }
}

QT_INIT_METAOBJECT const QMetaObject HydraulicStation::staticMetaObject = { {
    QMetaObject::SuperData::link<QObject::staticMetaObject>(),
    qt_meta_stringdata_HydraulicStation.data,
    qt_meta_data_HydraulicStation,
    qt_static_metacall,
    nullptr,
    nullptr
} };


const QMetaObject *HydraulicStation::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *HydraulicStation::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_HydraulicStation.stringdata0))
        return static_cast<void*>(this);
    return QObject::qt_metacast(_clname);
}

int HydraulicStation::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QObject::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 6)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 6;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 6)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 6;
    }
    return _id;
}

// SIGNAL 0
void HydraulicStation::signal_set_config_serial_port()
{
    QMetaObject::activate(this, &staticMetaObject, 0, nullptr);
}

// SIGNAL 1
void HydraulicStation::signal_close_seriao_port()
{
    QMetaObject::activate(this, &staticMetaObject, 1, nullptr);
}

// SIGNAL 2
void HydraulicStation::send_press_to_ui(QVector<double> _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t1))) };
    QMetaObject::activate(this, &staticMetaObject, 2, _a);
}
QT_WARNING_POP
QT_END_MOC_NAMESPACE
