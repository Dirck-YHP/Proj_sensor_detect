/****************************************************************************
** Meta object code from reading C++ file 'proximityswitch.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.15.17)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include <memory>
#include "../../../../sensors/proximityswitch.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#include <QtCore/QVector>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'proximityswitch.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.15.17. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
struct qt_meta_stringdata_ProximitySwitch_t {
    QByteArrayData data[10];
    char stringdata0[133];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_ProximitySwitch_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_ProximitySwitch_t qt_meta_stringdata_ProximitySwitch = {
    {
QT_MOC_LITERAL(0, 0, 15), // "ProximitySwitch"
QT_MOC_LITERAL(1, 16, 26), // "send_vol_cur_pul_dis_to_ui"
QT_MOC_LITERAL(2, 43, 0), // ""
QT_MOC_LITERAL(3, 44, 15), // "QVector<double>"
QT_MOC_LITERAL(4, 60, 4), // "data"
QT_MOC_LITERAL(5, 65, 13), // "sig_err_to_ui"
QT_MOC_LITERAL(6, 79, 3), // "err"
QT_MOC_LITERAL(7, 83, 20), // "rev_data_from_ni9205"
QT_MOC_LITERAL(8, 104, 12), // "slot_get_err"
QT_MOC_LITERAL(9, 117, 15) // "slot_acq_delete"

    },
    "ProximitySwitch\0send_vol_cur_pul_dis_to_ui\0"
    "\0QVector<double>\0data\0sig_err_to_ui\0"
    "err\0rev_data_from_ni9205\0slot_get_err\0"
    "slot_acq_delete"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_ProximitySwitch[] = {

 // content:
       8,       // revision
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
       5,    1,   42,    2, 0x06 /* Public */,

 // slots: name, argc, parameters, tag, flags
       7,    1,   45,    2, 0x08 /* Private */,
       8,    1,   48,    2, 0x08 /* Private */,
       9,    0,   51,    2, 0x0a /* Public */,

 // signals: parameters
    QMetaType::Void, 0x80000000 | 3,    4,
    QMetaType::Void, QMetaType::Bool,    6,

 // slots: parameters
    QMetaType::Void, 0x80000000 | 3,    4,
    QMetaType::Void, QMetaType::Bool,    6,
    QMetaType::Void,

       0        // eod
};

void ProximitySwitch::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        auto *_t = static_cast<ProximitySwitch *>(_o);
        (void)_t;
        switch (_id) {
        case 0: _t->send_vol_cur_pul_dis_to_ui((*reinterpret_cast< QVector<double>(*)>(_a[1]))); break;
        case 1: _t->sig_err_to_ui((*reinterpret_cast< bool(*)>(_a[1]))); break;
        case 2: _t->rev_data_from_ni9205((*reinterpret_cast< QVector<double>(*)>(_a[1]))); break;
        case 3: _t->slot_get_err((*reinterpret_cast< bool(*)>(_a[1]))); break;
        case 4: _t->slot_acq_delete(); break;
        default: ;
        }
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        switch (_id) {
        default: *reinterpret_cast<int*>(_a[0]) = -1; break;
        case 0:
            switch (*reinterpret_cast<int*>(_a[1])) {
            default: *reinterpret_cast<int*>(_a[0]) = -1; break;
            case 0:
                *reinterpret_cast<int*>(_a[0]) = qRegisterMetaType< QVector<double> >(); break;
            }
            break;
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
            using _t = void (ProximitySwitch::*)(QVector<double> );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&ProximitySwitch::send_vol_cur_pul_dis_to_ui)) {
                *result = 0;
                return;
            }
        }
        {
            using _t = void (ProximitySwitch::*)(bool );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&ProximitySwitch::sig_err_to_ui)) {
                *result = 1;
                return;
            }
        }
    }
}

QT_INIT_METAOBJECT const QMetaObject ProximitySwitch::staticMetaObject = { {
    QMetaObject::SuperData::link<QObject::staticMetaObject>(),
    qt_meta_stringdata_ProximitySwitch.data,
    qt_meta_data_ProximitySwitch,
    qt_static_metacall,
    nullptr,
    nullptr
} };


const QMetaObject *ProximitySwitch::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *ProximitySwitch::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_ProximitySwitch.stringdata0))
        return static_cast<void*>(this);
    return QObject::qt_metacast(_clname);
}

int ProximitySwitch::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
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
            qt_static_metacall(this, _c, _id, _a);
        _id -= 5;
    }
    return _id;
}

// SIGNAL 0
void ProximitySwitch::send_vol_cur_pul_dis_to_ui(QVector<double> _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t1))) };
    QMetaObject::activate(this, &staticMetaObject, 0, _a);
}

// SIGNAL 1
void ProximitySwitch::sig_err_to_ui(bool _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t1))) };
    QMetaObject::activate(this, &staticMetaObject, 1, _a);
}
QT_WARNING_POP
QT_END_MOC_NAMESPACE
