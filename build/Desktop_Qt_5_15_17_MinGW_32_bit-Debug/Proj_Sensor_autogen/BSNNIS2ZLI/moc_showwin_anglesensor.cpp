/****************************************************************************
** Meta object code from reading C++ file 'showwin_anglesensor.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.15.17)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include <memory>
#include "../../../../ui_show/showwin_anglesensor.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#include <QtCore/QVector>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'showwin_anglesensor.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.15.17. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
struct qt_meta_stringdata_showWin_angleSensor_t {
    QByteArrayData data[25];
    char stringdata0[413];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_showWin_angleSensor_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_showWin_angleSensor_t qt_meta_stringdata_showWin_angleSensor = {
    {
QT_MOC_LITERAL(0, 0, 19), // "showWin_angleSensor"
QT_MOC_LITERAL(1, 20, 22), // "signal_setConfigModbus"
QT_MOC_LITERAL(2, 43, 0), // ""
QT_MOC_LITERAL(3, 44, 22), // "signal_closeOpenModbus"
QT_MOC_LITERAL(4, 67, 17), // "signal_angle_cali"
QT_MOC_LITERAL(5, 85, 9), // "cur_angle"
QT_MOC_LITERAL(6, 95, 13), // "signal_delete"
QT_MOC_LITERAL(7, 109, 17), // "on_btn_ok_clicked"
QT_MOC_LITERAL(8, 127, 31), // "on_btn_start_finish_mea_toggled"
QT_MOC_LITERAL(9, 159, 7), // "checked"
QT_MOC_LITERAL(10, 167, 31), // "slot_get_vol_cur_angle_and_show"
QT_MOC_LITERAL(11, 199, 15), // "QVector<double>"
QT_MOC_LITERAL(12, 215, 5), // "angle"
QT_MOC_LITERAL(13, 221, 14), // "slot_get_angle"
QT_MOC_LITERAL(14, 236, 11), // "motor_angle"
QT_MOC_LITERAL(15, 248, 9), // "save_data"
QT_MOC_LITERAL(16, 258, 12), // "slot_get_err"
QT_MOC_LITERAL(17, 271, 3), // "err"
QT_MOC_LITERAL(18, 275, 23), // "on_btn_run_stop_toggled"
QT_MOC_LITERAL(19, 299, 23), // "on_btn_stop_now_clicked"
QT_MOC_LITERAL(20, 323, 25), // "on_btn_angle_cali_clicked"
QT_MOC_LITERAL(21, 349, 22), // "update_motor_tar_angle"
QT_MOC_LITERAL(22, 372, 4), // "text"
QT_MOC_LITERAL(23, 377, 18), // "update_motor_speed"
QT_MOC_LITERAL(24, 396, 16) // "update_file_name"

    },
    "showWin_angleSensor\0signal_setConfigModbus\0"
    "\0signal_closeOpenModbus\0signal_angle_cali\0"
    "cur_angle\0signal_delete\0on_btn_ok_clicked\0"
    "on_btn_start_finish_mea_toggled\0checked\0"
    "slot_get_vol_cur_angle_and_show\0"
    "QVector<double>\0angle\0slot_get_angle\0"
    "motor_angle\0save_data\0slot_get_err\0"
    "err\0on_btn_run_stop_toggled\0"
    "on_btn_stop_now_clicked\0"
    "on_btn_angle_cali_clicked\0"
    "update_motor_tar_angle\0text\0"
    "update_motor_speed\0update_file_name"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_showWin_angleSensor[] = {

 // content:
       8,       // revision
       0,       // classname
       0,    0, // classinfo
      16,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       4,       // signalCount

 // signals: name, argc, parameters, tag, flags
       1,    0,   94,    2, 0x06 /* Public */,
       3,    0,   95,    2, 0x06 /* Public */,
       4,    1,   96,    2, 0x06 /* Public */,
       6,    0,   99,    2, 0x06 /* Public */,

 // slots: name, argc, parameters, tag, flags
       7,    0,  100,    2, 0x08 /* Private */,
       8,    1,  101,    2, 0x08 /* Private */,
      10,    1,  104,    2, 0x08 /* Private */,
      13,    1,  107,    2, 0x08 /* Private */,
      15,    0,  110,    2, 0x08 /* Private */,
      16,    1,  111,    2, 0x08 /* Private */,
      18,    1,  114,    2, 0x08 /* Private */,
      19,    0,  117,    2, 0x08 /* Private */,
      20,    0,  118,    2, 0x08 /* Private */,
      21,    1,  119,    2, 0x0a /* Public */,
      23,    1,  122,    2, 0x0a /* Public */,
      24,    1,  125,    2, 0x0a /* Public */,

 // signals: parameters
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void, QMetaType::Double,    5,
    QMetaType::Void,

 // slots: parameters
    QMetaType::Void,
    QMetaType::Void, QMetaType::Bool,    9,
    QMetaType::Void, 0x80000000 | 11,   12,
    QMetaType::Void, QMetaType::Double,   14,
    QMetaType::Void,
    QMetaType::Void, QMetaType::Bool,   17,
    QMetaType::Void, QMetaType::Bool,    9,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void, QMetaType::QString,   22,
    QMetaType::Void, QMetaType::QString,   22,
    QMetaType::Void, QMetaType::QString,   22,

       0        // eod
};

void showWin_angleSensor::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        auto *_t = static_cast<showWin_angleSensor *>(_o);
        (void)_t;
        switch (_id) {
        case 0: _t->signal_setConfigModbus(); break;
        case 1: _t->signal_closeOpenModbus(); break;
        case 2: _t->signal_angle_cali((*reinterpret_cast< double(*)>(_a[1]))); break;
        case 3: _t->signal_delete(); break;
        case 4: _t->on_btn_ok_clicked(); break;
        case 5: _t->on_btn_start_finish_mea_toggled((*reinterpret_cast< bool(*)>(_a[1]))); break;
        case 6: _t->slot_get_vol_cur_angle_and_show((*reinterpret_cast< QVector<double>(*)>(_a[1]))); break;
        case 7: _t->slot_get_angle((*reinterpret_cast< double(*)>(_a[1]))); break;
        case 8: _t->save_data(); break;
        case 9: _t->slot_get_err((*reinterpret_cast< bool(*)>(_a[1]))); break;
        case 10: _t->on_btn_run_stop_toggled((*reinterpret_cast< bool(*)>(_a[1]))); break;
        case 11: _t->on_btn_stop_now_clicked(); break;
        case 12: _t->on_btn_angle_cali_clicked(); break;
        case 13: _t->update_motor_tar_angle((*reinterpret_cast< const QString(*)>(_a[1]))); break;
        case 14: _t->update_motor_speed((*reinterpret_cast< const QString(*)>(_a[1]))); break;
        case 15: _t->update_file_name((*reinterpret_cast< const QString(*)>(_a[1]))); break;
        default: ;
        }
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        switch (_id) {
        default: *reinterpret_cast<int*>(_a[0]) = -1; break;
        case 6:
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
            using _t = void (showWin_angleSensor::*)();
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&showWin_angleSensor::signal_setConfigModbus)) {
                *result = 0;
                return;
            }
        }
        {
            using _t = void (showWin_angleSensor::*)();
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&showWin_angleSensor::signal_closeOpenModbus)) {
                *result = 1;
                return;
            }
        }
        {
            using _t = void (showWin_angleSensor::*)(double );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&showWin_angleSensor::signal_angle_cali)) {
                *result = 2;
                return;
            }
        }
        {
            using _t = void (showWin_angleSensor::*)();
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&showWin_angleSensor::signal_delete)) {
                *result = 3;
                return;
            }
        }
    }
}

QT_INIT_METAOBJECT const QMetaObject showWin_angleSensor::staticMetaObject = { {
    QMetaObject::SuperData::link<QWidget::staticMetaObject>(),
    qt_meta_stringdata_showWin_angleSensor.data,
    qt_meta_data_showWin_angleSensor,
    qt_static_metacall,
    nullptr,
    nullptr
} };


const QMetaObject *showWin_angleSensor::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *showWin_angleSensor::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_showWin_angleSensor.stringdata0))
        return static_cast<void*>(this);
    return QWidget::qt_metacast(_clname);
}

int showWin_angleSensor::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QWidget::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 16)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 16;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 16)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 16;
    }
    return _id;
}

// SIGNAL 0
void showWin_angleSensor::signal_setConfigModbus()
{
    QMetaObject::activate(this, &staticMetaObject, 0, nullptr);
}

// SIGNAL 1
void showWin_angleSensor::signal_closeOpenModbus()
{
    QMetaObject::activate(this, &staticMetaObject, 1, nullptr);
}

// SIGNAL 2
void showWin_angleSensor::signal_angle_cali(double _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t1))) };
    QMetaObject::activate(this, &staticMetaObject, 2, _a);
}

// SIGNAL 3
void showWin_angleSensor::signal_delete()
{
    QMetaObject::activate(this, &staticMetaObject, 3, nullptr);
}
QT_WARNING_POP
QT_END_MOC_NAMESPACE
