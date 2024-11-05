/****************************************************************************
** Meta object code from reading C++ file 'paramwin_angleencoder.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.15.17)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include <memory>
#include "../../../../ui_param/paramwin_angleencoder.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'paramwin_angleencoder.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.15.17. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
struct qt_meta_stringdata_paramWin_angleEncoder_t {
    QByteArrayData data[14];
    char stringdata0[266];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_paramWin_angleEncoder_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_paramWin_angleEncoder_t qt_meta_stringdata_paramWin_angleEncoder = {
    {
QT_MOC_LITERAL(0, 0, 21), // "paramWin_angleEncoder"
QT_MOC_LITERAL(1, 22, 15), // "subWindowClosed"
QT_MOC_LITERAL(2, 38, 0), // ""
QT_MOC_LITERAL(3, 39, 26), // "motor_target_angle_changed"
QT_MOC_LITERAL(4, 66, 4), // "text"
QT_MOC_LITERAL(5, 71, 19), // "motor_speed_changed"
QT_MOC_LITERAL(6, 91, 9), // "file_name"
QT_MOC_LITERAL(7, 101, 25), // "on_btn_back_mainW_clicked"
QT_MOC_LITERAL(8, 127, 19), // "on_btn_exit_clicked"
QT_MOC_LITERAL(9, 147, 17), // "on_btn_ok_clicked"
QT_MOC_LITERAL(10, 165, 39), // "on_checkBox_no_need_device_st..."
QT_MOC_LITERAL(11, 205, 4), // "arg1"
QT_MOC_LITERAL(12, 210, 30), // "on_cBox_file_save_stateChanged"
QT_MOC_LITERAL(13, 241, 24) // "on_btn_load_data_clicked"

    },
    "paramWin_angleEncoder\0subWindowClosed\0"
    "\0motor_target_angle_changed\0text\0"
    "motor_speed_changed\0file_name\0"
    "on_btn_back_mainW_clicked\0on_btn_exit_clicked\0"
    "on_btn_ok_clicked\0"
    "on_checkBox_no_need_device_stateChanged\0"
    "arg1\0on_cBox_file_save_stateChanged\0"
    "on_btn_load_data_clicked"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_paramWin_angleEncoder[] = {

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
       8,    0,   75,    2, 0x08 /* Private */,
       9,    0,   76,    2, 0x08 /* Private */,
      10,    1,   77,    2, 0x08 /* Private */,
      12,    1,   80,    2, 0x08 /* Private */,
      13,    0,   83,    2, 0x08 /* Private */,

 // signals: parameters
    QMetaType::Void,
    QMetaType::Void, QMetaType::QString,    4,
    QMetaType::Void, QMetaType::QString,    4,
    QMetaType::Void, QMetaType::QString,    4,

 // slots: parameters
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void, QMetaType::Int,   11,
    QMetaType::Void, QMetaType::Int,   11,
    QMetaType::Void,

       0        // eod
};

void paramWin_angleEncoder::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        auto *_t = static_cast<paramWin_angleEncoder *>(_o);
        (void)_t;
        switch (_id) {
        case 0: _t->subWindowClosed(); break;
        case 1: _t->motor_target_angle_changed((*reinterpret_cast< const QString(*)>(_a[1]))); break;
        case 2: _t->motor_speed_changed((*reinterpret_cast< const QString(*)>(_a[1]))); break;
        case 3: _t->file_name((*reinterpret_cast< const QString(*)>(_a[1]))); break;
        case 4: _t->on_btn_back_mainW_clicked(); break;
        case 5: _t->on_btn_exit_clicked(); break;
        case 6: _t->on_btn_ok_clicked(); break;
        case 7: _t->on_checkBox_no_need_device_stateChanged((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 8: _t->on_cBox_file_save_stateChanged((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 9: _t->on_btn_load_data_clicked(); break;
        default: ;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        {
            using _t = void (paramWin_angleEncoder::*)();
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&paramWin_angleEncoder::subWindowClosed)) {
                *result = 0;
                return;
            }
        }
        {
            using _t = void (paramWin_angleEncoder::*)(const QString & );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&paramWin_angleEncoder::motor_target_angle_changed)) {
                *result = 1;
                return;
            }
        }
        {
            using _t = void (paramWin_angleEncoder::*)(const QString & );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&paramWin_angleEncoder::motor_speed_changed)) {
                *result = 2;
                return;
            }
        }
        {
            using _t = void (paramWin_angleEncoder::*)(const QString & );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&paramWin_angleEncoder::file_name)) {
                *result = 3;
                return;
            }
        }
    }
}

QT_INIT_METAOBJECT const QMetaObject paramWin_angleEncoder::staticMetaObject = { {
    QMetaObject::SuperData::link<QWidget::staticMetaObject>(),
    qt_meta_stringdata_paramWin_angleEncoder.data,
    qt_meta_data_paramWin_angleEncoder,
    qt_static_metacall,
    nullptr,
    nullptr
} };


const QMetaObject *paramWin_angleEncoder::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *paramWin_angleEncoder::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_paramWin_angleEncoder.stringdata0))
        return static_cast<void*>(this);
    return QWidget::qt_metacast(_clname);
}

int paramWin_angleEncoder::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
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
void paramWin_angleEncoder::subWindowClosed()
{
    QMetaObject::activate(this, &staticMetaObject, 0, nullptr);
}

// SIGNAL 1
void paramWin_angleEncoder::motor_target_angle_changed(const QString & _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t1))) };
    QMetaObject::activate(this, &staticMetaObject, 1, _a);
}

// SIGNAL 2
void paramWin_angleEncoder::motor_speed_changed(const QString & _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t1))) };
    QMetaObject::activate(this, &staticMetaObject, 2, _a);
}

// SIGNAL 3
void paramWin_angleEncoder::file_name(const QString & _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t1))) };
    QMetaObject::activate(this, &staticMetaObject, 3, _a);
}
QT_WARNING_POP
QT_END_MOC_NAMESPACE
