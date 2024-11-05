/****************************************************************************
** Meta object code from reading C++ file 'showwin_proximityswitch.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.15.17)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include <memory>
#include "../../../../ui_show/showwin_proximityswitch.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#include <QtCore/QVector>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'showwin_proximityswitch.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.15.17. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
struct qt_meta_stringdata_showWin_proximitySwitch_t {
    QByteArrayData data[16];
    char stringdata0[258];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_showWin_proximitySwitch_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_showWin_proximitySwitch_t qt_meta_stringdata_showWin_proximitySwitch = {
    {
QT_MOC_LITERAL(0, 0, 23), // "showWin_proximitySwitch"
QT_MOC_LITERAL(1, 24, 13), // "signal_delete"
QT_MOC_LITERAL(2, 38, 0), // ""
QT_MOC_LITERAL(3, 39, 31), // "on_btn_start_finish_mea_toggled"
QT_MOC_LITERAL(4, 71, 7), // "checked"
QT_MOC_LITERAL(5, 79, 26), // "get_data_and_plot_distance"
QT_MOC_LITERAL(6, 106, 15), // "QVector<double>"
QT_MOC_LITERAL(7, 122, 4), // "data"
QT_MOC_LITERAL(8, 127, 33), // "slot_get_vol_cur_pul_dis_and_..."
QT_MOC_LITERAL(9, 161, 17), // "on_btn_ok_clicked"
QT_MOC_LITERAL(10, 179, 29), // "on_btn_repeat_precise_clicked"
QT_MOC_LITERAL(11, 209, 9), // "save_data"
QT_MOC_LITERAL(12, 219, 12), // "slot_get_err"
QT_MOC_LITERAL(13, 232, 3), // "err"
QT_MOC_LITERAL(14, 236, 16), // "update_file_name"
QT_MOC_LITERAL(15, 253, 4) // "text"

    },
    "showWin_proximitySwitch\0signal_delete\0"
    "\0on_btn_start_finish_mea_toggled\0"
    "checked\0get_data_and_plot_distance\0"
    "QVector<double>\0data\0"
    "slot_get_vol_cur_pul_dis_and_show\0"
    "on_btn_ok_clicked\0on_btn_repeat_precise_clicked\0"
    "save_data\0slot_get_err\0err\0update_file_name\0"
    "text"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_showWin_proximitySwitch[] = {

 // content:
       8,       // revision
       0,       // classname
       0,    0, // classinfo
       9,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       1,       // signalCount

 // signals: name, argc, parameters, tag, flags
       1,    0,   59,    2, 0x06 /* Public */,

 // slots: name, argc, parameters, tag, flags
       3,    1,   60,    2, 0x08 /* Private */,
       5,    1,   63,    2, 0x08 /* Private */,
       8,    1,   66,    2, 0x08 /* Private */,
       9,    0,   69,    2, 0x08 /* Private */,
      10,    0,   70,    2, 0x08 /* Private */,
      11,    0,   71,    2, 0x08 /* Private */,
      12,    1,   72,    2, 0x08 /* Private */,
      14,    1,   75,    2, 0x0a /* Public */,

 // signals: parameters
    QMetaType::Void,

 // slots: parameters
    QMetaType::Void, QMetaType::Bool,    4,
    QMetaType::Void, 0x80000000 | 6,    7,
    QMetaType::Void, 0x80000000 | 6,    7,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void, QMetaType::Bool,   13,
    QMetaType::Void, QMetaType::QString,   15,

       0        // eod
};

void showWin_proximitySwitch::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        auto *_t = static_cast<showWin_proximitySwitch *>(_o);
        (void)_t;
        switch (_id) {
        case 0: _t->signal_delete(); break;
        case 1: _t->on_btn_start_finish_mea_toggled((*reinterpret_cast< bool(*)>(_a[1]))); break;
        case 2: _t->get_data_and_plot_distance((*reinterpret_cast< QVector<double>(*)>(_a[1]))); break;
        case 3: _t->slot_get_vol_cur_pul_dis_and_show((*reinterpret_cast< QVector<double>(*)>(_a[1]))); break;
        case 4: _t->on_btn_ok_clicked(); break;
        case 5: _t->on_btn_repeat_precise_clicked(); break;
        case 6: _t->save_data(); break;
        case 7: _t->slot_get_err((*reinterpret_cast< bool(*)>(_a[1]))); break;
        case 8: _t->update_file_name((*reinterpret_cast< const QString(*)>(_a[1]))); break;
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
        case 3:
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
            using _t = void (showWin_proximitySwitch::*)();
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&showWin_proximitySwitch::signal_delete)) {
                *result = 0;
                return;
            }
        }
    }
}

QT_INIT_METAOBJECT const QMetaObject showWin_proximitySwitch::staticMetaObject = { {
    QMetaObject::SuperData::link<QWidget::staticMetaObject>(),
    qt_meta_stringdata_showWin_proximitySwitch.data,
    qt_meta_data_showWin_proximitySwitch,
    qt_static_metacall,
    nullptr,
    nullptr
} };


const QMetaObject *showWin_proximitySwitch::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *showWin_proximitySwitch::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_showWin_proximitySwitch.stringdata0))
        return static_cast<void*>(this);
    return QWidget::qt_metacast(_clname);
}

int showWin_proximitySwitch::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QWidget::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 9)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 9;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 9)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 9;
    }
    return _id;
}

// SIGNAL 0
void showWin_proximitySwitch::signal_delete()
{
    QMetaObject::activate(this, &staticMetaObject, 0, nullptr);
}
QT_WARNING_POP
QT_END_MOC_NAMESPACE
