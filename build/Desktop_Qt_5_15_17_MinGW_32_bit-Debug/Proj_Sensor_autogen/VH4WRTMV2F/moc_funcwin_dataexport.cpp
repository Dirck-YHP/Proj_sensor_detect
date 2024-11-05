/****************************************************************************
** Meta object code from reading C++ file 'funcwin_dataexport.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.15.17)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include <memory>
#include "../../../../ui_func/funcwin_dataexport.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'funcwin_dataexport.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.15.17. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
struct qt_meta_stringdata_funcWin_DataExport_t {
    QByteArrayData data[10];
    char stringdata0[157];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_funcWin_DataExport_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_funcWin_DataExport_t qt_meta_stringdata_funcWin_DataExport = {
    {
QT_MOC_LITERAL(0, 0, 18), // "funcWin_DataExport"
QT_MOC_LITERAL(1, 19, 15), // "subWindowClosed"
QT_MOC_LITERAL(2, 35, 0), // ""
QT_MOC_LITERAL(3, 36, 17), // "on_btn_ok_clicked"
QT_MOC_LITERAL(4, 54, 25), // "on_btn_back_mainW_clicked"
QT_MOC_LITERAL(5, 80, 21), // "on_btn_choose_clicked"
QT_MOC_LITERAL(6, 102, 19), // "on_btn_send_clicked"
QT_MOC_LITERAL(7, 122, 7), // "RcvData"
QT_MOC_LITERAL(8, 130, 17), // "HaveNewConnection"
QT_MOC_LITERAL(9, 148, 8) // "SendFile"

    },
    "funcWin_DataExport\0subWindowClosed\0\0"
    "on_btn_ok_clicked\0on_btn_back_mainW_clicked\0"
    "on_btn_choose_clicked\0on_btn_send_clicked\0"
    "RcvData\0HaveNewConnection\0SendFile"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_funcWin_DataExport[] = {

 // content:
       8,       // revision
       0,       // classname
       0,    0, // classinfo
       8,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       1,       // signalCount

 // signals: name, argc, parameters, tag, flags
       1,    0,   54,    2, 0x06 /* Public */,

 // slots: name, argc, parameters, tag, flags
       3,    0,   55,    2, 0x08 /* Private */,
       4,    0,   56,    2, 0x08 /* Private */,
       5,    0,   57,    2, 0x08 /* Private */,
       6,    0,   58,    2, 0x08 /* Private */,
       7,    0,   59,    2, 0x08 /* Private */,
       8,    0,   60,    2, 0x08 /* Private */,
       9,    0,   61,    2, 0x08 /* Private */,

 // signals: parameters
    QMetaType::Void,

 // slots: parameters
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,

       0        // eod
};

void funcWin_DataExport::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        auto *_t = static_cast<funcWin_DataExport *>(_o);
        (void)_t;
        switch (_id) {
        case 0: _t->subWindowClosed(); break;
        case 1: _t->on_btn_ok_clicked(); break;
        case 2: _t->on_btn_back_mainW_clicked(); break;
        case 3: _t->on_btn_choose_clicked(); break;
        case 4: _t->on_btn_send_clicked(); break;
        case 5: _t->RcvData(); break;
        case 6: _t->HaveNewConnection(); break;
        case 7: _t->SendFile(); break;
        default: ;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        {
            using _t = void (funcWin_DataExport::*)();
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&funcWin_DataExport::subWindowClosed)) {
                *result = 0;
                return;
            }
        }
    }
    (void)_a;
}

QT_INIT_METAOBJECT const QMetaObject funcWin_DataExport::staticMetaObject = { {
    QMetaObject::SuperData::link<QWidget::staticMetaObject>(),
    qt_meta_stringdata_funcWin_DataExport.data,
    qt_meta_data_funcWin_DataExport,
    qt_static_metacall,
    nullptr,
    nullptr
} };


const QMetaObject *funcWin_DataExport::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *funcWin_DataExport::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_funcWin_DataExport.stringdata0))
        return static_cast<void*>(this);
    return QWidget::qt_metacast(_clname);
}

int funcWin_DataExport::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QWidget::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 8)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 8;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 8)
            *reinterpret_cast<int*>(_a[0]) = -1;
        _id -= 8;
    }
    return _id;
}

// SIGNAL 0
void funcWin_DataExport::subWindowClosed()
{
    QMetaObject::activate(this, &staticMetaObject, 0, nullptr);
}
QT_WARNING_POP
QT_END_MOC_NAMESPACE
