/****************************************************************************
** Meta object code from reading C++ file 'paramwin_anglesensor.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.15.17)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include <memory>
#include "../../../../ui_param/paramwin_anglesensor.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'paramwin_anglesensor.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.15.17. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
struct qt_meta_stringdata_paramWin_angleSensor_t {
    QByteArrayData data[14];
    char stringdata0[265];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_paramWin_angleSensor_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_paramWin_angleSensor_t qt_meta_stringdata_paramWin_angleSensor = {
    {
QT_MOC_LITERAL(0, 0, 20), // "paramWin_angleSensor"
QT_MOC_LITERAL(1, 21, 15), // "subWindowClosed"
QT_MOC_LITERAL(2, 37, 0), // ""
QT_MOC_LITERAL(3, 38, 26), // "motor_target_angle_changed"
QT_MOC_LITERAL(4, 65, 4), // "text"
QT_MOC_LITERAL(5, 70, 19), // "motor_speed_changed"
QT_MOC_LITERAL(6, 90, 9), // "file_name"
QT_MOC_LITERAL(7, 100, 17), // "on_btn_ok_clicked"
QT_MOC_LITERAL(8, 118, 39), // "on_checkBox_no_need_device_st..."
QT_MOC_LITERAL(9, 158, 4), // "arg1"
QT_MOC_LITERAL(10, 163, 19), // "on_btn_exit_clicked"
QT_MOC_LITERAL(11, 183, 25), // "on_btn_back_mainW_clicked"
QT_MOC_LITERAL(12, 209, 30), // "on_cBox_file_save_stateChanged"
QT_MOC_LITERAL(13, 240, 24) // "on_btn_load_data_clicked"

    },
    "paramWin_angleSensor\0subWindowClosed\0"
    "\0motor_target_angle_changed\0text\0"
    "motor_speed_changed\0file_name\0"
    "on_btn_ok_clicked\0"
    "on_checkBox_no_need_device_stateChanged\0"
    "arg1\0on_btn_exit_clicked\0"
    "on_btn_back_mainW_clicked\0"
    "on_cBox_file_save_stateChanged\0"
    "on_btn_load_data_clicked"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_paramWin_angleSensor[] = {

 // content:
       8,       // revision
       0,       // classname
       0,    0, // classinfo
      10,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       4,       // signalCount

 // signals: name, argc, parameters, tag, flags
       1,    0,   64,    2, 0x06 /* Public */,
       3,    1,   65,    2, 0x06 /* Public */,
       5,    1,   68,    2, 0x06 /* Public */,
       6,    1,   71,    2, 0x06 /* Public */,

 // slots: name, argc, parameters, tag, flags
       7,    0,   74,    2, 0x08 /* Private */,
       8,    1,   75,    2, 0x08 /* Private */,
      10,    0,   78,    2, 0x08 /* Private */,
      11,    0,   79,    2, 0x08 /* Private */,
      12,    1,   80,    2, 0x08 /* Private */,
      13,    0,   83,    2, 0x08 /* Private */,

 // signals: parameters
    QMetaType::Void,
    QMetaType::Void, QMetaType::QString,    4,
    QMetaType::Void, QMetaType::QString,    4,
    QMetaType::Void, QMetaType::QString,    4,

 // slots: parameters
    QMetaType::Void,
    QMetaType::Void, QMetaType::Int,    9,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void, QMetaType::Int,    9,
    QMetaType::Void,

       0        // eod
};

void paramWin_angleSensor::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        auto *_t = static_cast<paramWin_angleSensor *>(_o);
        (void)_t;
        switch (_id) {
        case 0: _t->subWindowClosed(); break;
        case 1: _t->motor_target_angle_changed((*reinterpret_cast< const QString(*)>(_a[1]))); break;
        case 2: _t->motor_speed_changed((*reinterpret_cast< const QString(*)>(_a[1]))); break;
        case 3: _t->file_name((*reinterpret_cast< const QString(*)>(_a[1]))); break;
        case 4: _t->on_btn_ok_clicked(); break;
        case 5: _t->on_checkBox_no_need_device_stateChanged((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 6: _t->on_btn_exit_clicked(); break;
        case 7: _t->on_btn_back_mainW_clicked(); break;
        case 8: _t->on_cBox_file_save_stateChanged((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 9: _t->on_btn_load_data_clicked(); break;
        default: ;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        {
            using _t = void (paramWin_angleSensor::*)();
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&paramWin_angleSensor::subWindowClosed)) {
                *result = 0;
                return;
            }
        }
        {
            using _t = void (paramWin_angleSensor::*)(const QString & );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&paramWin_angleSensor::motor_target_angle_changed)) {
                *result = 1;
                return;
            }
        }
        {
            using _t = void (paramWin_angleSensor::*)(const QString & );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&paramWin_angleSensor::motor_speed_changed)) {
                *result = 2;
                return;
            }
        }
        {
            using _t = void (paramWin_angleSensor::*)(const QString & );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&paramWin_angleSensor::file_name)) {
                *result = 3;
                return;
            }
        }
    }
}

QT_INIT_METAOBJECT const QMetaObject paramWin_angleSensor::staticMetaObject = { {
    QMetaObject::SuperData::link<QWidget::staticMetaObject>(),
    qt_meta_stringdata_paramWin_angleSensor.data,
    qt_meta_data_paramWin_angleSensor,
    qt_static_metacall,
    nullptr,
    nullptr
} };


const QMetaObject *paramWin_angleSensor::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *paramWin_angleSensor::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_paramWin_angleSensor.stringdata0))
        return static_cast<void*>(this);
    return QWidget::qt_metacast(_clname);
}

int paramWin_angleSensor::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QWidget::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 10)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 10;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 10)
            *reinterpret_cast<int*>(_a[0]) = -1;
        _id -= 10;
    }
    return _id;
}

// SIGNAL 0
void paramWin_angleSensor::subWindowClosed()
{
    QMetaObject::activate(this, &staticMetaObject, 0, nullptr);
}

// SIGNAL 1
void paramWin_angleSensor::motor_target_angle_changed(const QString & _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t1))) };
    QMetaObject::activate(this, &staticMetaObject, 1, _a);
}

// SIGNAL 2
void paramWin_angleSensor::motor_speed_changed(const QString & _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t1))) };
    QMetaObject::activate(this, &staticMetaObject, 2, _a);
}

// SIGNAL 3
void paramWin_angleSensor::file_name(const QString & _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t1))) };
    QMetaObject::activate(this, &staticMetaObject, 3, _a);
}
QT_WARNING_POP
QT_END_MOC_NAMESPACE