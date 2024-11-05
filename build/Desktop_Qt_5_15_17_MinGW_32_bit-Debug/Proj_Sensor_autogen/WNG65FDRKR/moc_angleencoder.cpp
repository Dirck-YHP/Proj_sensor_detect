/****************************************************************************
** Meta object code from reading C++ file 'angleencoder.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.15.17)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include <memory>
#include "../../../../sensors/angleencoder.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#include <QtCore/QVector>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'angleencoder.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.15.17. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
struct qt_meta_stringdata_AngleEncoder_t {
    QByteArrayData data[21];
    char stringdata0[283];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_AngleEncoder_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_AngleEncoder_t qt_meta_stringdata_AngleEncoder = {
    {
QT_MOC_LITERAL(0, 0, 12), // "AngleEncoder"
QT_MOC_LITERAL(1, 13, 18), // "send_vol_cur_to_ui"
QT_MOC_LITERAL(2, 32, 0), // ""
QT_MOC_LITERAL(3, 33, 15), // "QVector<double>"
QT_MOC_LITERAL(4, 49, 4), // "data"
QT_MOC_LITERAL(5, 54, 16), // "send_pulse_to_ui"
QT_MOC_LITERAL(6, 71, 25), // "QVector<QVector<double> >"
QT_MOC_LITERAL(7, 97, 10), // "data_final"
QT_MOC_LITERAL(8, 108, 16), // "send_angle_to_ui"
QT_MOC_LITERAL(9, 125, 15), // "QVector<uInt32>"
QT_MOC_LITERAL(10, 141, 5), // "data2"
QT_MOC_LITERAL(11, 147, 5), // "data3"
QT_MOC_LITERAL(12, 153, 5), // "data4"
QT_MOC_LITERAL(13, 159, 13), // "sig_err_to_ui"
QT_MOC_LITERAL(14, 173, 3), // "err"
QT_MOC_LITERAL(15, 177, 13), // "signal_delete"
QT_MOC_LITERAL(16, 191, 20), // "rev_data_from_ni9205"
QT_MOC_LITERAL(17, 212, 20), // "rev_data_from_ni9403"
QT_MOC_LITERAL(18, 233, 20), // "rev_data_from_ni9401"
QT_MOC_LITERAL(19, 254, 12), // "slot_get_err"
QT_MOC_LITERAL(20, 267, 15) // "slot_acq_delete"

    },
    "AngleEncoder\0send_vol_cur_to_ui\0\0"
    "QVector<double>\0data\0send_pulse_to_ui\0"
    "QVector<QVector<double> >\0data_final\0"
    "send_angle_to_ui\0QVector<uInt32>\0data2\0"
    "data3\0data4\0sig_err_to_ui\0err\0"
    "signal_delete\0rev_data_from_ni9205\0"
    "rev_data_from_ni9403\0rev_data_from_ni9401\0"
    "slot_get_err\0slot_acq_delete"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_AngleEncoder[] = {

 // content:
       8,       // revision
       0,       // classname
       0,    0, // classinfo
      10,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       5,       // signalCount

 // signals: name, argc, parameters, tag, flags
       1,    1,   64,    2, 0x06 /* Public */,
       5,    1,   67,    2, 0x06 /* Public */,
       8,    4,   70,    2, 0x06 /* Public */,
      13,    1,   79,    2, 0x06 /* Public */,
      15,    0,   82,    2, 0x06 /* Public */,

 // slots: name, argc, parameters, tag, flags
      16,    1,   83,    2, 0x08 /* Private */,
      17,    1,   86,    2, 0x08 /* Private */,
      18,    4,   89,    2, 0x08 /* Private */,
      19,    1,   98,    2, 0x08 /* Private */,
      20,    0,  101,    2, 0x0a /* Public */,

 // signals: parameters
    QMetaType::Void, 0x80000000 | 3,    4,
    QMetaType::Void, 0x80000000 | 6,    7,
    QMetaType::Void, 0x80000000 | 3, 0x80000000 | 9, 0x80000000 | 3, 0x80000000 | 3,    4,   10,   11,   12,
    QMetaType::Void, QMetaType::Bool,   14,
    QMetaType::Void,

 // slots: parameters
    QMetaType::Void, 0x80000000 | 3,    4,
    QMetaType::Void, 0x80000000 | 6,    7,
    QMetaType::Void, 0x80000000 | 3, 0x80000000 | 9, 0x80000000 | 3, 0x80000000 | 3,    4,   10,   11,   12,
    QMetaType::Void, QMetaType::Bool,   14,
    QMetaType::Void,

       0        // eod
};

void AngleEncoder::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        auto *_t = static_cast<AngleEncoder *>(_o);
        (void)_t;
        switch (_id) {
        case 0: _t->send_vol_cur_to_ui((*reinterpret_cast< QVector<double>(*)>(_a[1]))); break;
        case 1: _t->send_pulse_to_ui((*reinterpret_cast< QVector<QVector<double> >(*)>(_a[1]))); break;
        case 2: _t->send_angle_to_ui((*reinterpret_cast< QVector<double>(*)>(_a[1])),(*reinterpret_cast< QVector<uInt32>(*)>(_a[2])),(*reinterpret_cast< QVector<double>(*)>(_a[3])),(*reinterpret_cast< QVector<double>(*)>(_a[4]))); break;
        case 3: _t->sig_err_to_ui((*reinterpret_cast< bool(*)>(_a[1]))); break;
        case 4: _t->signal_delete(); break;
        case 5: _t->rev_data_from_ni9205((*reinterpret_cast< QVector<double>(*)>(_a[1]))); break;
        case 6: _t->rev_data_from_ni9403((*reinterpret_cast< QVector<QVector<double> >(*)>(_a[1]))); break;
        case 7: _t->rev_data_from_ni9401((*reinterpret_cast< QVector<double>(*)>(_a[1])),(*reinterpret_cast< QVector<uInt32>(*)>(_a[2])),(*reinterpret_cast< QVector<double>(*)>(_a[3])),(*reinterpret_cast< QVector<double>(*)>(_a[4]))); break;
        case 8: _t->slot_get_err((*reinterpret_cast< bool(*)>(_a[1]))); break;
        case 9: _t->slot_acq_delete(); break;
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
        case 1:
            switch (*reinterpret_cast<int*>(_a[1])) {
            default: *reinterpret_cast<int*>(_a[0]) = -1; break;
            case 0:
                *reinterpret_cast<int*>(_a[0]) = qRegisterMetaType< QVector<QVector<double> > >(); break;
            }
            break;
        case 2:
            switch (*reinterpret_cast<int*>(_a[1])) {
            default: *reinterpret_cast<int*>(_a[0]) = -1; break;
            case 3:
            case 2:
            case 0:
                *reinterpret_cast<int*>(_a[0]) = qRegisterMetaType< QVector<double> >(); break;
            }
            break;
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
                *reinterpret_cast<int*>(_a[0]) = qRegisterMetaType< QVector<QVector<double> > >(); break;
            }
            break;
        case 7:
            switch (*reinterpret_cast<int*>(_a[1])) {
            default: *reinterpret_cast<int*>(_a[0]) = -1; break;
            case 3:
            case 2:
            case 0:
                *reinterpret_cast<int*>(_a[0]) = qRegisterMetaType< QVector<double> >(); break;
            }
            break;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        {
            using _t = void (AngleEncoder::*)(QVector<double> );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&AngleEncoder::send_vol_cur_to_ui)) {
                *result = 0;
                return;
            }
        }
        {
            using _t = void (AngleEncoder::*)(QVector<QVector<double>> );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&AngleEncoder::send_pulse_to_ui)) {
                *result = 1;
                return;
            }
        }
        {
            using _t = void (AngleEncoder::*)(QVector<double> , QVector<uInt32> , QVector<double> , QVector<double> );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&AngleEncoder::send_angle_to_ui)) {
                *result = 2;
                return;
            }
        }
        {
            using _t = void (AngleEncoder::*)(bool );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&AngleEncoder::sig_err_to_ui)) {
                *result = 3;
                return;
            }
        }
        {
            using _t = void (AngleEncoder::*)();
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&AngleEncoder::signal_delete)) {
                *result = 4;
                return;
            }
        }
    }
}

QT_INIT_METAOBJECT const QMetaObject AngleEncoder::staticMetaObject = { {
    QMetaObject::SuperData::link<QObject::staticMetaObject>(),
    qt_meta_stringdata_AngleEncoder.data,
    qt_meta_data_AngleEncoder,
    qt_static_metacall,
    nullptr,
    nullptr
} };


const QMetaObject *AngleEncoder::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *AngleEncoder::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_AngleEncoder.stringdata0))
        return static_cast<void*>(this);
    return QObject::qt_metacast(_clname);
}

int AngleEncoder::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QObject::qt_metacall(_c, _id, _a);
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
void AngleEncoder::send_vol_cur_to_ui(QVector<double> _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t1))) };
    QMetaObject::activate(this, &staticMetaObject, 0, _a);
}

// SIGNAL 1
void AngleEncoder::send_pulse_to_ui(QVector<QVector<double>> _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t1))) };
    QMetaObject::activate(this, &staticMetaObject, 1, _a);
}

// SIGNAL 2
void AngleEncoder::send_angle_to_ui(QVector<double> _t1, QVector<uInt32> _t2, QVector<double> _t3, QVector<double> _t4)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t1))), const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t2))), const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t3))), const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t4))) };
    QMetaObject::activate(this, &staticMetaObject, 2, _a);
}

// SIGNAL 3
void AngleEncoder::sig_err_to_ui(bool _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t1))) };
    QMetaObject::activate(this, &staticMetaObject, 3, _a);
}

// SIGNAL 4
void AngleEncoder::signal_delete()
{
    QMetaObject::activate(this, &staticMetaObject, 4, nullptr);
}
QT_WARNING_POP
QT_END_MOC_NAMESPACE
