/****************************************************************************
** Meta object code from reading C++ file 'showwin_measureresis.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.15.17)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include <memory>
#include "../../../../ui_show/showwin_measureresis.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#include <QtCore/QVector>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'showwin_measureresis.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.15.17. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
struct qt_meta_stringdata_showWin_measureResis_t {
    QByteArrayData data[10];
    char stringdata0[164];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_showWin_measureResis_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_showWin_measureResis_t qt_meta_stringdata_showWin_measureResis = {
    {
QT_MOC_LITERAL(0, 0, 20), // "showWin_measureResis"
QT_MOC_LITERAL(1, 21, 13), // "signal_delete"
QT_MOC_LITERAL(2, 35, 0), // ""
QT_MOC_LITERAL(3, 36, 17), // "on_btn_ok_clicked"
QT_MOC_LITERAL(4, 54, 31), // "on_btn_start_finish_mea_toggled"
QT_MOC_LITERAL(5, 86, 7), // "checked"
QT_MOC_LITERAL(6, 94, 24), // "on_radioButton_0_clicked"
QT_MOC_LITERAL(7, 119, 23), // "slot_get_resis_and_show"
QT_MOC_LITERAL(8, 143, 15), // "QVector<double>"
QT_MOC_LITERAL(9, 159, 4) // "data"

    },
    "showWin_measureResis\0signal_delete\0\0"
    "on_btn_ok_clicked\0on_btn_start_finish_mea_toggled\0"
    "checked\0on_radioButton_0_clicked\0"
    "slot_get_resis_and_show\0QVector<double>\0"
    "data"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_showWin_measureResis[] = {

 // content:
       8,       // revision
       0,       // classname
       0,    0, // classinfo
       5,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       1,       // signalCount

 // signals: name, argc, parameters, tag, flags
       1,    0,   39,    2, 0x06 /* Public */,

 // slots: name, argc, parameters, tag, flags
       3,    0,   40,    2, 0x08 /* Private */,
       4,    1,   41,    2, 0x08 /* Private */,
       6,    0,   44,    2, 0x08 /* Private */,
       7,    1,   45,    2, 0x0a /* Public */,

 // signals: parameters
    QMetaType::Void,

 // slots: parameters
    QMetaType::Void,
    QMetaType::Void, QMetaType::Bool,    5,
    QMetaType::Void,
    QMetaType::Void, 0x80000000 | 8,    9,

       0        // eod
};

void showWin_measureResis::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        auto *_t = static_cast<showWin_measureResis *>(_o);
        (void)_t;
        switch (_id) {
        case 0: _t->signal_delete(); break;
        case 1: _t->on_btn_ok_clicked(); break;
        case 2: _t->on_btn_start_finish_mea_toggled((*reinterpret_cast< bool(*)>(_a[1]))); break;
        case 4: _t->slot_get_resis_and_show((*reinterpret_cast< QVector<double>(*)>(_a[1]))); break;
        default: ;
        }
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        switch (_id) {
        default: *reinterpret_cast<int*>(_a[0]) = -1; break;
        case 4:
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
            using _t = void (showWin_measureResis::*)();
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&showWin_measureResis::signal_delete)) {
                *result = 0;
                return;
            }
        }
    }
}

QT_INIT_METAOBJECT const QMetaObject showWin_measureResis::staticMetaObject = { {
    QMetaObject::SuperData::link<QWidget::staticMetaObject>(),
    qt_meta_stringdata_showWin_measureResis.data,
    qt_meta_data_showWin_measureResis,
    qt_static_metacall,
    nullptr,
    nullptr
} };


const QMetaObject *showWin_measureResis::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *showWin_measureResis::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_showWin_measureResis.stringdata0))
        return static_cast<void*>(this);
    return QWidget::qt_metacast(_clname);
}

int showWin_measureResis::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QWidget::qt_metacall(_c, _id, _a);
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
void showWin_measureResis::signal_delete()
{
    QMetaObject::activate(this, &staticMetaObject, 0, nullptr);
}
QT_WARNING_POP
QT_END_MOC_NAMESPACE
