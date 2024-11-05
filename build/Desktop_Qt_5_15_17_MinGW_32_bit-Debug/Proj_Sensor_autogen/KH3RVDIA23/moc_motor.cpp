/****************************************************************************
** Meta object code from reading C++ file 'motor.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.15.17)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include <memory>
#include "../../../../devices/motor.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'motor.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.15.17. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
struct qt_meta_stringdata_Motor_t {
    QByteArrayData data[17];
    char stringdata0[238];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_Motor_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_Motor_t qt_meta_stringdata_Motor = {
    {
QT_MOC_LITERAL(0, 0, 5), // "Motor"
QT_MOC_LITERAL(1, 6, 24), // "signal_set_config_modbus"
QT_MOC_LITERAL(2, 31, 0), // ""
QT_MOC_LITERAL(3, 32, 19), // "signal_close_modbus"
QT_MOC_LITERAL(4, 52, 16), // "send_angle_to_ui"
QT_MOC_LITERAL(5, 69, 5), // "angle"
QT_MOC_LITERAL(6, 75, 14), // "send_spd_to_ui"
QT_MOC_LITERAL(7, 90, 3), // "spd"
QT_MOC_LITERAL(8, 94, 13), // "signal_delete"
QT_MOC_LITERAL(9, 108, 17), // "signal_angle_cali"
QT_MOC_LITERAL(10, 126, 10), // "angle_cali"
QT_MOC_LITERAL(11, 137, 20), // "rev_data_from_modbus"
QT_MOC_LITERAL(12, 158, 4), // "data"
QT_MOC_LITERAL(13, 163, 19), // "rev_spd_from_modbus"
QT_MOC_LITERAL(14, 183, 17), // "get_config_signal"
QT_MOC_LITERAL(15, 201, 16), // "get_close_signal"
QT_MOC_LITERAL(16, 218, 19) // "slot_get_angle_cali"

    },
    "Motor\0signal_set_config_modbus\0\0"
    "signal_close_modbus\0send_angle_to_ui\0"
    "angle\0send_spd_to_ui\0spd\0signal_delete\0"
    "signal_angle_cali\0angle_cali\0"
    "rev_data_from_modbus\0data\0rev_spd_from_modbus\0"
    "get_config_signal\0get_close_signal\0"
    "slot_get_angle_cali"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_Motor[] = {

 // content:
       8,       // revision
       0,       // classname
       0,    0, // classinfo
      11,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       6,       // signalCount

 // signals: name, argc, parameters, tag, flags
       1,    0,   69,    2, 0x06 /* Public */,
       3,    0,   70,    2, 0x06 /* Public */,
       4,    1,   71,    2, 0x06 /* Public */,
       6,    1,   74,    2, 0x06 /* Public */,
       8,    0,   77,    2, 0x06 /* Public */,
       9,    1,   78,    2, 0x06 /* Public */,

 // slots: name, argc, parameters, tag, flags
      11,    1,   81,    2, 0x08 /* Private */,
      13,    1,   84,    2, 0x08 /* Private */,
      14,    0,   87,    2, 0x0a /* Public */,
      15,    0,   88,    2, 0x0a /* Public */,
      16,    1,   89,    2, 0x0a /* Public */,

 // signals: parameters
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void, QMetaType::Double,    5,
    QMetaType::Void, QMetaType::Double,    7,
    QMetaType::Void,
    QMetaType::Void, QMetaType::Double,   10,

 // slots: parameters
    QMetaType::Void, QMetaType::Int,   12,
    QMetaType::Void, QMetaType::Int,   12,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void, QMetaType::Double,   10,

       0        // eod
};

void Motor::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        auto *_t = static_cast<Motor *>(_o);
        (void)_t;
        switch (_id) {
        case 0: _t->signal_set_config_modbus(); break;
        case 1: _t->signal_close_modbus(); break;
        case 2: _t->send_angle_to_ui((*reinterpret_cast< double(*)>(_a[1]))); break;
        case 3: _t->send_spd_to_ui((*reinterpret_cast< double(*)>(_a[1]))); break;
        case 4: _t->signal_delete(); break;
        case 5: _t->signal_angle_cali((*reinterpret_cast< double(*)>(_a[1]))); break;
        case 6: _t->rev_data_from_modbus((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 7: _t->rev_spd_from_modbus((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 8: _t->get_config_signal(); break;
        case 9: _t->get_close_signal(); break;
        case 10: _t->slot_get_angle_cali((*reinterpret_cast< double(*)>(_a[1]))); break;
        default: ;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        {
            using _t = void (Motor::*)();
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&Motor::signal_set_config_modbus)) {
                *result = 0;
                return;
            }
        }
        {
            using _t = void (Motor::*)();
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&Motor::signal_close_modbus)) {
                *result = 1;
                return;
            }
        }
        {
            using _t = void (Motor::*)(double );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&Motor::send_angle_to_ui)) {
                *result = 2;
                return;
            }
        }
        {
            using _t = void (Motor::*)(double );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&Motor::send_spd_to_ui)) {
                *result = 3;
                return;
            }
        }
        {
            using _t = void (Motor::*)();
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&Motor::signal_delete)) {
                *result = 4;
                return;
            }
        }
        {
            using _t = void (Motor::*)(double );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&Motor::signal_angle_cali)) {
                *result = 5;
                return;
            }
        }
    }
}

QT_INIT_METAOBJECT const QMetaObject Motor::staticMetaObject = { {
    QMetaObject::SuperData::link<QObject::staticMetaObject>(),
    qt_meta_stringdata_Motor.data,
    qt_meta_data_Motor,
    qt_static_metacall,
    nullptr,
    nullptr
} };


const QMetaObject *Motor::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *Motor::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_Motor.stringdata0))
        return static_cast<void*>(this);
    return QObject::qt_metacast(_clname);
}

int Motor::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QObject::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 11)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 11;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 11)
            *reinterpret_cast<int*>(_a[0]) = -1;
        _id -= 11;
    }
    return _id;
}

// SIGNAL 0
void Motor::signal_set_config_modbus()
{
    QMetaObject::activate(this, &staticMetaObject, 0, nullptr);
}

// SIGNAL 1
void Motor::signal_close_modbus()
{
    QMetaObject::activate(this, &staticMetaObject, 1, nullptr);
}

// SIGNAL 2
void Motor::send_angle_to_ui(double _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t1))) };
    QMetaObject::activate(this, &staticMetaObject, 2, _a);
}

// SIGNAL 3
void Motor::send_spd_to_ui(double _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t1))) };
    QMetaObject::activate(this, &staticMetaObject, 3, _a);
}

// SIGNAL 4
void Motor::signal_delete()
{
    QMetaObject::activate(this, &staticMetaObject, 4, nullptr);
}

// SIGNAL 5
void Motor::signal_angle_cali(double _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t1))) };
    QMetaObject::activate(this, &staticMetaObject, 5, _a);
}
QT_WARNING_POP
QT_END_MOC_NAMESPACE
