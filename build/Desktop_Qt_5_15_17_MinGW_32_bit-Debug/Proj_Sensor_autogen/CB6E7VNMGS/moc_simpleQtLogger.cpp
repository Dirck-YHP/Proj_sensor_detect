/****************************************************************************
** Meta object code from reading C++ file 'simpleQtLogger.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.15.17)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include <memory>
#include "../../../../tools/simpleQtLogger.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'simpleQtLogger.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.15.17. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
struct qt_meta_stringdata_simpleqtlogger__Sink_t {
    QByteArrayData data[1];
    char stringdata0[21];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_simpleqtlogger__Sink_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_simpleqtlogger__Sink_t qt_meta_stringdata_simpleqtlogger__Sink = {
    {
QT_MOC_LITERAL(0, 0, 20) // "simpleqtlogger::Sink"

    },
    "simpleqtlogger::Sink"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_simpleqtlogger__Sink[] = {

 // content:
       8,       // revision
       0,       // classname
       0,    0, // classinfo
       0,    0, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

       0        // eod
};

void simpleqtlogger::Sink::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    (void)_o;
    (void)_id;
    (void)_c;
    (void)_a;
}

QT_INIT_METAOBJECT const QMetaObject simpleqtlogger::Sink::staticMetaObject = { {
    QMetaObject::SuperData::link<QObject::staticMetaObject>(),
    qt_meta_stringdata_simpleqtlogger__Sink.data,
    qt_meta_data_simpleqtlogger__Sink,
    qt_static_metacall,
    nullptr,
    nullptr
} };


const QMetaObject *simpleqtlogger::Sink::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *simpleqtlogger::Sink::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_simpleqtlogger__Sink.stringdata0))
        return static_cast<void*>(this);
    return QObject::qt_metacast(_clname);
}

int simpleqtlogger::Sink::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QObject::qt_metacall(_c, _id, _a);
    return _id;
}
struct qt_meta_stringdata_simpleqtlogger__SinkFileLog_t {
    QByteArrayData data[12];
    char stringdata0[125];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_simpleqtlogger__SinkFileLog_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_simpleqtlogger__SinkFileLog_t qt_meta_stringdata_simpleqtlogger__SinkFileLog = {
    {
QT_MOC_LITERAL(0, 0, 27), // "simpleqtlogger::SinkFileLog"
QT_MOC_LITERAL(1, 28, 7), // "slotLog"
QT_MOC_LITERAL(2, 36, 0), // ""
QT_MOC_LITERAL(3, 37, 2), // "ts"
QT_MOC_LITERAL(4, 40, 3), // "tid"
QT_MOC_LITERAL(5, 44, 4), // "text"
QT_MOC_LITERAL(6, 49, 8), // "LogLevel"
QT_MOC_LITERAL(7, 58, 8), // "logLevel"
QT_MOC_LITERAL(8, 67, 12), // "functionName"
QT_MOC_LITERAL(9, 80, 8), // "fileName"
QT_MOC_LITERAL(10, 89, 10), // "lineNumber"
QT_MOC_LITERAL(11, 100, 24) // "slotCheckLogFileActivity"

    },
    "simpleqtlogger::SinkFileLog\0slotLog\0"
    "\0ts\0tid\0text\0LogLevel\0logLevel\0"
    "functionName\0fileName\0lineNumber\0"
    "slotCheckLogFileActivity"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_simpleqtlogger__SinkFileLog[] = {

 // content:
       8,       // revision
       0,       // classname
       0,    0, // classinfo
       2,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // slots: name, argc, parameters, tag, flags
       1,    7,   24,    2, 0x08 /* Private */,
      11,    0,   39,    2, 0x08 /* Private */,

 // slots: parameters
    QMetaType::Void, QMetaType::QString, QMetaType::QString, QMetaType::QString, 0x80000000 | 6, QMetaType::QString, QMetaType::QString, QMetaType::UInt,    3,    4,    5,    7,    8,    9,   10,
    QMetaType::Void,

       0        // eod
};

void simpleqtlogger::SinkFileLog::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        auto *_t = static_cast<SinkFileLog *>(_o);
        (void)_t;
        switch (_id) {
        case 0: _t->slotLog((*reinterpret_cast< const QString(*)>(_a[1])),(*reinterpret_cast< const QString(*)>(_a[2])),(*reinterpret_cast< const QString(*)>(_a[3])),(*reinterpret_cast< LogLevel(*)>(_a[4])),(*reinterpret_cast< const QString(*)>(_a[5])),(*reinterpret_cast< const QString(*)>(_a[6])),(*reinterpret_cast< uint(*)>(_a[7]))); break;
        case 1: _t->slotCheckLogFileActivity(); break;
        default: ;
        }
    }
}

QT_INIT_METAOBJECT const QMetaObject simpleqtlogger::SinkFileLog::staticMetaObject = { {
    QMetaObject::SuperData::link<Sink::staticMetaObject>(),
    qt_meta_stringdata_simpleqtlogger__SinkFileLog.data,
    qt_meta_data_simpleqtlogger__SinkFileLog,
    qt_static_metacall,
    nullptr,
    nullptr
} };


const QMetaObject *simpleqtlogger::SinkFileLog::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *simpleqtlogger::SinkFileLog::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_simpleqtlogger__SinkFileLog.stringdata0))
        return static_cast<void*>(this);
    return Sink::qt_metacast(_clname);
}

int simpleqtlogger::SinkFileLog::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = Sink::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 2)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 2;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 2)
            *reinterpret_cast<int*>(_a[0]) = -1;
        _id -= 2;
    }
    return _id;
}
struct qt_meta_stringdata_simpleqtlogger__SinkConsoleLog_t {
    QByteArrayData data[11];
    char stringdata0[103];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_simpleqtlogger__SinkConsoleLog_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_simpleqtlogger__SinkConsoleLog_t qt_meta_stringdata_simpleqtlogger__SinkConsoleLog = {
    {
QT_MOC_LITERAL(0, 0, 30), // "simpleqtlogger::SinkConsoleLog"
QT_MOC_LITERAL(1, 31, 7), // "slotLog"
QT_MOC_LITERAL(2, 39, 0), // ""
QT_MOC_LITERAL(3, 40, 2), // "ts"
QT_MOC_LITERAL(4, 43, 3), // "tid"
QT_MOC_LITERAL(5, 47, 4), // "text"
QT_MOC_LITERAL(6, 52, 8), // "LogLevel"
QT_MOC_LITERAL(7, 61, 8), // "logLevel"
QT_MOC_LITERAL(8, 70, 12), // "functionName"
QT_MOC_LITERAL(9, 83, 8), // "fileName"
QT_MOC_LITERAL(10, 92, 10) // "lineNumber"

    },
    "simpleqtlogger::SinkConsoleLog\0slotLog\0"
    "\0ts\0tid\0text\0LogLevel\0logLevel\0"
    "functionName\0fileName\0lineNumber"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_simpleqtlogger__SinkConsoleLog[] = {

 // content:
       8,       // revision
       0,       // classname
       0,    0, // classinfo
       1,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // slots: name, argc, parameters, tag, flags
       1,    7,   19,    2, 0x08 /* Private */,

 // slots: parameters
    QMetaType::Void, QMetaType::QString, QMetaType::QString, QMetaType::QString, 0x80000000 | 6, QMetaType::QString, QMetaType::QString, QMetaType::UInt,    3,    4,    5,    7,    8,    9,   10,

       0        // eod
};

void simpleqtlogger::SinkConsoleLog::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        auto *_t = static_cast<SinkConsoleLog *>(_o);
        (void)_t;
        switch (_id) {
        case 0: _t->slotLog((*reinterpret_cast< const QString(*)>(_a[1])),(*reinterpret_cast< const QString(*)>(_a[2])),(*reinterpret_cast< const QString(*)>(_a[3])),(*reinterpret_cast< LogLevel(*)>(_a[4])),(*reinterpret_cast< const QString(*)>(_a[5])),(*reinterpret_cast< const QString(*)>(_a[6])),(*reinterpret_cast< uint(*)>(_a[7]))); break;
        default: ;
        }
    }
}

QT_INIT_METAOBJECT const QMetaObject simpleqtlogger::SinkConsoleLog::staticMetaObject = { {
    QMetaObject::SuperData::link<Sink::staticMetaObject>(),
    qt_meta_stringdata_simpleqtlogger__SinkConsoleLog.data,
    qt_meta_data_simpleqtlogger__SinkConsoleLog,
    qt_static_metacall,
    nullptr,
    nullptr
} };


const QMetaObject *simpleqtlogger::SinkConsoleLog::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *simpleqtlogger::SinkConsoleLog::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_simpleqtlogger__SinkConsoleLog.stringdata0))
        return static_cast<void*>(this);
    return Sink::qt_metacast(_clname);
}

int simpleqtlogger::SinkConsoleLog::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = Sink::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 1)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 1;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 1)
            *reinterpret_cast<int*>(_a[0]) = -1;
        _id -= 1;
    }
    return _id;
}
struct qt_meta_stringdata_simpleqtlogger__SinkQDebugLog_t {
    QByteArrayData data[11];
    char stringdata0[102];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_simpleqtlogger__SinkQDebugLog_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_simpleqtlogger__SinkQDebugLog_t qt_meta_stringdata_simpleqtlogger__SinkQDebugLog = {
    {
QT_MOC_LITERAL(0, 0, 29), // "simpleqtlogger::SinkQDebugLog"
QT_MOC_LITERAL(1, 30, 7), // "slotLog"
QT_MOC_LITERAL(2, 38, 0), // ""
QT_MOC_LITERAL(3, 39, 2), // "ts"
QT_MOC_LITERAL(4, 42, 3), // "tid"
QT_MOC_LITERAL(5, 46, 4), // "text"
QT_MOC_LITERAL(6, 51, 8), // "LogLevel"
QT_MOC_LITERAL(7, 60, 8), // "logLevel"
QT_MOC_LITERAL(8, 69, 12), // "functionName"
QT_MOC_LITERAL(9, 82, 8), // "fileName"
QT_MOC_LITERAL(10, 91, 10) // "lineNumber"

    },
    "simpleqtlogger::SinkQDebugLog\0slotLog\0"
    "\0ts\0tid\0text\0LogLevel\0logLevel\0"
    "functionName\0fileName\0lineNumber"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_simpleqtlogger__SinkQDebugLog[] = {

 // content:
       8,       // revision
       0,       // classname
       0,    0, // classinfo
       1,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // slots: name, argc, parameters, tag, flags
       1,    7,   19,    2, 0x08 /* Private */,

 // slots: parameters
    QMetaType::Void, QMetaType::QString, QMetaType::QString, QMetaType::QString, 0x80000000 | 6, QMetaType::QString, QMetaType::QString, QMetaType::UInt,    3,    4,    5,    7,    8,    9,   10,

       0        // eod
};

void simpleqtlogger::SinkQDebugLog::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        auto *_t = static_cast<SinkQDebugLog *>(_o);
        (void)_t;
        switch (_id) {
        case 0: _t->slotLog((*reinterpret_cast< const QString(*)>(_a[1])),(*reinterpret_cast< const QString(*)>(_a[2])),(*reinterpret_cast< const QString(*)>(_a[3])),(*reinterpret_cast< LogLevel(*)>(_a[4])),(*reinterpret_cast< const QString(*)>(_a[5])),(*reinterpret_cast< const QString(*)>(_a[6])),(*reinterpret_cast< uint(*)>(_a[7]))); break;
        default: ;
        }
    }
}

QT_INIT_METAOBJECT const QMetaObject simpleqtlogger::SinkQDebugLog::staticMetaObject = { {
    QMetaObject::SuperData::link<Sink::staticMetaObject>(),
    qt_meta_stringdata_simpleqtlogger__SinkQDebugLog.data,
    qt_meta_data_simpleqtlogger__SinkQDebugLog,
    qt_static_metacall,
    nullptr,
    nullptr
} };


const QMetaObject *simpleqtlogger::SinkQDebugLog::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *simpleqtlogger::SinkQDebugLog::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_simpleqtlogger__SinkQDebugLog.stringdata0))
        return static_cast<void*>(this);
    return Sink::qt_metacast(_clname);
}

int simpleqtlogger::SinkQDebugLog::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = Sink::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 1)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 1;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 1)
            *reinterpret_cast<int*>(_a[0]) = -1;
        _id -= 1;
    }
    return _id;
}
struct qt_meta_stringdata_simpleqtlogger__SinkSignalLog_t {
    QByteArrayData data[14];
    char stringdata0[155];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_simpleqtlogger__SinkSignalLog_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_simpleqtlogger__SinkSignalLog_t qt_meta_stringdata_simpleqtlogger__SinkSignalLog = {
    {
QT_MOC_LITERAL(0, 0, 29), // "simpleqtlogger::SinkSignalLog"
QT_MOC_LITERAL(1, 30, 16), // "signalLogMessage"
QT_MOC_LITERAL(2, 47, 0), // ""
QT_MOC_LITERAL(3, 48, 24), // "simpleqtlogger::LogLevel"
QT_MOC_LITERAL(4, 73, 8), // "logLevel"
QT_MOC_LITERAL(5, 82, 10), // "logMessage"
QT_MOC_LITERAL(6, 93, 7), // "slotLog"
QT_MOC_LITERAL(7, 101, 2), // "ts"
QT_MOC_LITERAL(8, 104, 3), // "tid"
QT_MOC_LITERAL(9, 108, 4), // "text"
QT_MOC_LITERAL(10, 113, 8), // "LogLevel"
QT_MOC_LITERAL(11, 122, 12), // "functionName"
QT_MOC_LITERAL(12, 135, 8), // "fileName"
QT_MOC_LITERAL(13, 144, 10) // "lineNumber"

    },
    "simpleqtlogger::SinkSignalLog\0"
    "signalLogMessage\0\0simpleqtlogger::LogLevel\0"
    "logLevel\0logMessage\0slotLog\0ts\0tid\0"
    "text\0LogLevel\0functionName\0fileName\0"
    "lineNumber"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_simpleqtlogger__SinkSignalLog[] = {

 // content:
       8,       // revision
       0,       // classname
       0,    0, // classinfo
       2,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       1,       // signalCount

 // signals: name, argc, parameters, tag, flags
       1,    2,   24,    2, 0x06 /* Public */,

 // slots: name, argc, parameters, tag, flags
       6,    7,   29,    2, 0x08 /* Private */,

 // signals: parameters
    QMetaType::Void, 0x80000000 | 3, QMetaType::QString,    4,    5,

 // slots: parameters
    QMetaType::Void, QMetaType::QString, QMetaType::QString, QMetaType::QString, 0x80000000 | 10, QMetaType::QString, QMetaType::QString, QMetaType::UInt,    7,    8,    9,    4,   11,   12,   13,

       0        // eod
};

void simpleqtlogger::SinkSignalLog::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        auto *_t = static_cast<SinkSignalLog *>(_o);
        (void)_t;
        switch (_id) {
        case 0: _t->signalLogMessage((*reinterpret_cast< simpleqtlogger::LogLevel(*)>(_a[1])),(*reinterpret_cast< const QString(*)>(_a[2]))); break;
        case 1: _t->slotLog((*reinterpret_cast< const QString(*)>(_a[1])),(*reinterpret_cast< const QString(*)>(_a[2])),(*reinterpret_cast< const QString(*)>(_a[3])),(*reinterpret_cast< LogLevel(*)>(_a[4])),(*reinterpret_cast< const QString(*)>(_a[5])),(*reinterpret_cast< const QString(*)>(_a[6])),(*reinterpret_cast< uint(*)>(_a[7]))); break;
        default: ;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        {
            using _t = void (SinkSignalLog::*)(simpleqtlogger::LogLevel , const QString & );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&SinkSignalLog::signalLogMessage)) {
                *result = 0;
                return;
            }
        }
    }
}

QT_INIT_METAOBJECT const QMetaObject simpleqtlogger::SinkSignalLog::staticMetaObject = { {
    QMetaObject::SuperData::link<Sink::staticMetaObject>(),
    qt_meta_stringdata_simpleqtlogger__SinkSignalLog.data,
    qt_meta_data_simpleqtlogger__SinkSignalLog,
    qt_static_metacall,
    nullptr,
    nullptr
} };


const QMetaObject *simpleqtlogger::SinkSignalLog::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *simpleqtlogger::SinkSignalLog::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_simpleqtlogger__SinkSignalLog.stringdata0))
        return static_cast<void*>(this);
    return Sink::qt_metacast(_clname);
}

int simpleqtlogger::SinkSignalLog::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = Sink::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 2)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 2;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 2)
            *reinterpret_cast<int*>(_a[0]) = -1;
        _id -= 2;
    }
    return _id;
}

// SIGNAL 0
void simpleqtlogger::SinkSignalLog::signalLogMessage(simpleqtlogger::LogLevel _t1, const QString & _t2)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t1))), const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t2))) };
    QMetaObject::activate(this, &staticMetaObject, 0, _a);
}
struct qt_meta_stringdata_simpleqtlogger__SinkSyslogLog_t {
    QByteArrayData data[11];
    char stringdata0[102];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_simpleqtlogger__SinkSyslogLog_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_simpleqtlogger__SinkSyslogLog_t qt_meta_stringdata_simpleqtlogger__SinkSyslogLog = {
    {
QT_MOC_LITERAL(0, 0, 29), // "simpleqtlogger::SinkSyslogLog"
QT_MOC_LITERAL(1, 30, 7), // "slotLog"
QT_MOC_LITERAL(2, 38, 0), // ""
QT_MOC_LITERAL(3, 39, 2), // "ts"
QT_MOC_LITERAL(4, 42, 3), // "tid"
QT_MOC_LITERAL(5, 46, 4), // "text"
QT_MOC_LITERAL(6, 51, 8), // "LogLevel"
QT_MOC_LITERAL(7, 60, 8), // "logLevel"
QT_MOC_LITERAL(8, 69, 12), // "functionName"
QT_MOC_LITERAL(9, 82, 8), // "fileName"
QT_MOC_LITERAL(10, 91, 10) // "lineNumber"

    },
    "simpleqtlogger::SinkSyslogLog\0slotLog\0"
    "\0ts\0tid\0text\0LogLevel\0logLevel\0"
    "functionName\0fileName\0lineNumber"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_simpleqtlogger__SinkSyslogLog[] = {

 // content:
       8,       // revision
       0,       // classname
       0,    0, // classinfo
       1,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // slots: name, argc, parameters, tag, flags
       1,    7,   19,    2, 0x08 /* Private */,

 // slots: parameters
    QMetaType::Void, QMetaType::QString, QMetaType::QString, QMetaType::QString, 0x80000000 | 6, QMetaType::QString, QMetaType::QString, QMetaType::UInt,    3,    4,    5,    7,    8,    9,   10,

       0        // eod
};

void simpleqtlogger::SinkSyslogLog::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        auto *_t = static_cast<SinkSyslogLog *>(_o);
        (void)_t;
        switch (_id) {
        case 0: _t->slotLog((*reinterpret_cast< const QString(*)>(_a[1])),(*reinterpret_cast< const QString(*)>(_a[2])),(*reinterpret_cast< const QString(*)>(_a[3])),(*reinterpret_cast< LogLevel(*)>(_a[4])),(*reinterpret_cast< const QString(*)>(_a[5])),(*reinterpret_cast< const QString(*)>(_a[6])),(*reinterpret_cast< uint(*)>(_a[7]))); break;
        default: ;
        }
    }
}

QT_INIT_METAOBJECT const QMetaObject simpleqtlogger::SinkSyslogLog::staticMetaObject = { {
    QMetaObject::SuperData::link<Sink::staticMetaObject>(),
    qt_meta_stringdata_simpleqtlogger__SinkSyslogLog.data,
    qt_meta_data_simpleqtlogger__SinkSyslogLog,
    qt_static_metacall,
    nullptr,
    nullptr
} };


const QMetaObject *simpleqtlogger::SinkSyslogLog::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *simpleqtlogger::SinkSyslogLog::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_simpleqtlogger__SinkSyslogLog.stringdata0))
        return static_cast<void*>(this);
    return Sink::qt_metacast(_clname);
}

int simpleqtlogger::SinkSyslogLog::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = Sink::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 1)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 1;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 1)
            *reinterpret_cast<int*>(_a[0]) = -1;
        _id -= 1;
    }
    return _id;
}
struct qt_meta_stringdata_simpleqtlogger__SimpleQtLogger_t {
    QByteArrayData data[11];
    char stringdata0[105];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_simpleqtlogger__SimpleQtLogger_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_simpleqtlogger__SimpleQtLogger_t qt_meta_stringdata_simpleqtlogger__SimpleQtLogger = {
    {
QT_MOC_LITERAL(0, 0, 30), // "simpleqtlogger::SimpleQtLogger"
QT_MOC_LITERAL(1, 31, 9), // "signalLog"
QT_MOC_LITERAL(2, 41, 0), // ""
QT_MOC_LITERAL(3, 42, 2), // "ts"
QT_MOC_LITERAL(4, 45, 3), // "tid"
QT_MOC_LITERAL(5, 49, 4), // "text"
QT_MOC_LITERAL(6, 54, 8), // "LogLevel"
QT_MOC_LITERAL(7, 63, 8), // "logLevel"
QT_MOC_LITERAL(8, 72, 12), // "functionName"
QT_MOC_LITERAL(9, 85, 8), // "fileName"
QT_MOC_LITERAL(10, 94, 10) // "lineNumber"

    },
    "simpleqtlogger::SimpleQtLogger\0signalLog\0"
    "\0ts\0tid\0text\0LogLevel\0logLevel\0"
    "functionName\0fileName\0lineNumber"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_simpleqtlogger__SimpleQtLogger[] = {

 // content:
       8,       // revision
       0,       // classname
       0,    0, // classinfo
       1,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       1,       // signalCount

 // signals: name, argc, parameters, tag, flags
       1,    7,   19,    2, 0x06 /* Public */,

 // signals: parameters
    QMetaType::Void, QMetaType::QString, QMetaType::QString, QMetaType::QString, 0x80000000 | 6, QMetaType::QString, QMetaType::QString, QMetaType::UInt,    3,    4,    5,    7,    8,    9,   10,

       0        // eod
};

void simpleqtlogger::SimpleQtLogger::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        auto *_t = static_cast<SimpleQtLogger *>(_o);
        (void)_t;
        switch (_id) {
        case 0: _t->signalLog((*reinterpret_cast< const QString(*)>(_a[1])),(*reinterpret_cast< const QString(*)>(_a[2])),(*reinterpret_cast< const QString(*)>(_a[3])),(*reinterpret_cast< LogLevel(*)>(_a[4])),(*reinterpret_cast< const QString(*)>(_a[5])),(*reinterpret_cast< const QString(*)>(_a[6])),(*reinterpret_cast< uint(*)>(_a[7]))); break;
        default: ;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        {
            using _t = void (SimpleQtLogger::*)(const QString & , const QString & , const QString & , LogLevel , const QString & , const QString & , unsigned int );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&SimpleQtLogger::signalLog)) {
                *result = 0;
                return;
            }
        }
    }
}

QT_INIT_METAOBJECT const QMetaObject simpleqtlogger::SimpleQtLogger::staticMetaObject = { {
    QMetaObject::SuperData::link<QObject::staticMetaObject>(),
    qt_meta_stringdata_simpleqtlogger__SimpleQtLogger.data,
    qt_meta_data_simpleqtlogger__SimpleQtLogger,
    qt_static_metacall,
    nullptr,
    nullptr
} };


const QMetaObject *simpleqtlogger::SimpleQtLogger::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *simpleqtlogger::SimpleQtLogger::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_simpleqtlogger__SimpleQtLogger.stringdata0))
        return static_cast<void*>(this);
    return QObject::qt_metacast(_clname);
}

int simpleqtlogger::SimpleQtLogger::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QObject::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 1)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 1;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 1)
            *reinterpret_cast<int*>(_a[0]) = -1;
        _id -= 1;
    }
    return _id;
}

// SIGNAL 0
void simpleqtlogger::SimpleQtLogger::signalLog(const QString & _t1, const QString & _t2, const QString & _t3, LogLevel _t4, const QString & _t5, const QString & _t6, unsigned int _t7)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t1))), const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t2))), const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t3))), const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t4))), const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t5))), const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t6))), const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t7))) };
    QMetaObject::activate(this, &staticMetaObject, 0, _a);
}
QT_WARNING_POP
QT_END_MOC_NAMESPACE
