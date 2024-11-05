/****************************************************************************
** Meta object code from reading C++ file 'showwin_pressuresensor.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.15.17)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include <memory>
#include "../../../../ui_show/showwin_pressuresensor.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#include <QtCore/QVector>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'showwin_pressuresensor.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.15.17. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
struct qt_meta_stringdata_showWin_pressureSensor_t {
    QByteArrayData data[17];
    char stringdata0[268];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_showWin_pressureSensor_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_showWin_pressureSensor_t qt_meta_stringdata_showWin_pressureSensor = {
    {
QT_MOC_LITERAL(0, 0, 22), // "showWin_pressureSensor"
QT_MOC_LITERAL(1, 23, 26), // "signal_setConfigSerialPort"
QT_MOC_LITERAL(2, 50, 0), // ""
QT_MOC_LITERAL(3, 51, 16), // "signal_closeOpen"
QT_MOC_LITERAL(4, 68, 13), // "signal_delete"
QT_MOC_LITERAL(5, 82, 31), // "on_btn_start_finish_mea_toggled"
QT_MOC_LITERAL(6, 114, 7), // "checked"
QT_MOC_LITERAL(7, 122, 17), // "on_btn_ok_clicked"
QT_MOC_LITERAL(8, 140, 27), // "slot_plot_press_from_sensor"
QT_MOC_LITERAL(9, 168, 15), // "QVector<double>"
QT_MOC_LITERAL(10, 184, 4), // "data"
QT_MOC_LITERAL(11, 189, 29), // "slot_plot_press_from_hydraSta"
QT_MOC_LITERAL(12, 219, 9), // "save_data"
QT_MOC_LITERAL(13, 229, 12), // "slot_get_err"
QT_MOC_LITERAL(14, 242, 3), // "err"
QT_MOC_LITERAL(15, 246, 16), // "update_file_name"
QT_MOC_LITERAL(16, 263, 4) // "text"

    },
    "showWin_pressureSensor\0"
    "signal_setConfigSerialPort\0\0"
    "signal_closeOpen\0signal_delete\0"
    "on_btn_start_finish_mea_toggled\0checked\0"
    "on_btn_ok_clicked\0slot_plot_press_from_sensor\0"
    "QVector<double>\0data\0slot_plot_press_from_hydraSta\0"
    "save_data\0slot_get_err\0err\0update_file_name\0"
    "text"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_showWin_pressureSensor[] = {

 // content:
       8,       // revision
       0,       // classname
       0,    0, // classinfo
      10,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       3,       // signalCount

 // signals: name, argc, parameters, tag, flags
       1,    0,   64,    2, 0x06 /* Public */,
       3,    0,   65,    2, 0x06 /* Public */,
       4,    0,   66,    2, 0x06 /* Public */,

 // slots: name, argc, parameters, tag, flags
       5,    1,   67,    2, 0x08 /* Private */,
       7,    0,   70,    2, 0x08 /* Private */,
       8,    1,   71,    2, 0x08 /* Private */,
      11,    1,   74,    2, 0x08 /* Private */,
      12,    0,   77,    2, 0x08 /* Private */,
      13,    1,   78,    2, 0x08 /* Private */,
      15,    1,   81,    2, 0x0a /* Public */,

 // signals: parameters
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,

 // slots: parameters
    QMetaType::Void, QMetaType::Bool,    6,
    QMetaType::Void,
    QMetaType::Void, 0x80000000 | 9,   10,
    QMetaType::Void, 0x80000000 | 9,   10,
    QMetaType::Void,
    QMetaType::Void, QMetaType::Bool,   14,
    QMetaType::Void, QMetaType::QString,   16,

       0        // eod
};

void showWin_pressureSensor::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        auto *_t = static_cast<showWin_pressureSensor *>(_o);
        (void)_t;
        switch (_id) {
        case 0: _t->signal_setConfigSerialPort(); break;
        case 1: _t->signal_closeOpen(); break;
        case 2: _t->signal_delete(); break;
        case 3: _t->on_btn_start_finish_mea_toggled((*reinterpret_cast< bool(*)>(_a[1]))); break;
        case 4: _t->on_btn_ok_clicked(); break;
        case 5: _t->slot_plot_press_from_sensor((*reinterpret_cast< QVector<double>(*)>(_a[1]))); break;
        case 6: _t->slot_plot_press_from_hydraSta((*reinterpret_cast< QVector<double>(*)>(_a[1]))); break;
        case 7: _t->save_data(); break;
        case 8: _t->slot_get_err((*reinterpret_cast< bool(*)>(_a[1]))); break;
        case 9: _t->update_file_name((*reinterpret_cast< const QString(*)>(_a[1]))); break;
        default: ;
        }
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        switch (_id) {
        default: *reinterpret_cast<int*>(_a[0]) = -1; break;
        case 5:
            switch (*reinterpret_cast<int*>(_a[1])) {
            default: *reinterpret_cast<int*>(_a[0]) = -1; break;
            case 0:
                *reinterpret_cast<int*>(_a[0]) = qRegisterMetaType< QVector<double> >(); break;
            }
            break;
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
            using _t = void (showWin_pressureSensor::*)();
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&showWin_pressureSensor::signal_setConfigSerialPort)) {
                *result = 0;
                return;
            }
        }
        {
            using _t = void (showWin_pressureSensor::*)();
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&showWin_pressureSensor::signal_closeOpen)) {
                *result = 1;
                return;
            }
        }
        {
            using _t = void (showWin_pressureSensor::*)();
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&showWin_pressureSensor::signal_delete)) {
                *result = 2;
                return;
            }
        }
    }
}

QT_INIT_METAOBJECT const QMetaObject showWin_pressureSensor::staticMetaObject = { {
    QMetaObject::SuperData::link<QWidget::staticMetaObject>(),
    qt_meta_stringdata_showWin_pressureSensor.data,
    qt_meta_data_showWin_pressureSensor,
    qt_static_metacall,
    nullptr,
    nullptr
} };


const QMetaObject *showWin_pressureSensor::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *showWin_pressureSensor::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_showWin_pressureSensor.stringdata0))
        return static_cast<void*>(this);
    return QWidget::qt_metacast(_clname);
}

int showWin_pressureSensor::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
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
            qt_static_metacall(this, _c, _id, _a);
        _id -= 10;
    }
    return _id;
}

// SIGNAL 0
void showWin_pressureSensor::signal_setConfigSerialPort()
{
    QMetaObject::activate(this, &staticMetaObject, 0, nullptr);
}

// SIGNAL 1
void showWin_pressureSensor::signal_closeOpen()
{
    QMetaObject::activate(this, &staticMetaObject, 1, nullptr);
}

// SIGNAL 2
void showWin_pressureSensor::signal_delete()
{
    QMetaObject::activate(this, &staticMetaObject, 2, nullptr);
}
QT_WARNING_POP
QT_END_MOC_NAMESPACE
