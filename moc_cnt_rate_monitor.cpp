/****************************************************************************
** Meta object code from reading C++ file 'cnt_rate_monitor.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.13.0)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include <memory>
#include "cnt_rate_monitor.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'cnt_rate_monitor.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.13.0. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
struct qt_meta_stringdata_counter_rate_monitor_t {
    QByteArrayData data[12];
    char stringdata0[145];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_counter_rate_monitor_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_counter_rate_monitor_t qt_meta_stringdata_counter_rate_monitor = {
    {
QT_MOC_LITERAL(0, 0, 20), // "counter_rate_monitor"
QT_MOC_LITERAL(1, 21, 14), // "cnt_rate_ready"
QT_MOC_LITERAL(2, 36, 0), // ""
QT_MOC_LITERAL(3, 37, 16), // "cnt_rate_message"
QT_MOC_LITERAL(4, 54, 7), // "FIFO_OK"
QT_MOC_LITERAL(5, 62, 14), // "check_overfill"
QT_MOC_LITERAL(6, 77, 12), // "No_FIFO_data"
QT_MOC_LITERAL(7, 90, 9), // "FIFO_isOK"
QT_MOC_LITERAL(8, 100, 10), // "clear_FIFO"
QT_MOC_LITERAL(9, 111, 8), // "cnt_rate"
QT_MOC_LITERAL(10, 120, 11), // "clear_rates"
QT_MOC_LITERAL(11, 132, 12) // "get_counters"

    },
    "counter_rate_monitor\0cnt_rate_ready\0"
    "\0cnt_rate_message\0FIFO_OK\0check_overfill\0"
    "No_FIFO_data\0FIFO_isOK\0clear_FIFO\0"
    "cnt_rate\0clear_rates\0get_counters"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_counter_rate_monitor[] = {

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
       1,    0,   64,    2, 0x06 /* Public */,
       3,    1,   65,    2, 0x06 /* Public */,
       4,    0,   68,    2, 0x06 /* Public */,
       5,    0,   69,    2, 0x06 /* Public */,
       6,    0,   70,    2, 0x06 /* Public */,

 // slots: name, argc, parameters, tag, flags
       7,    0,   71,    2, 0x08 /* Private */,
       8,    0,   72,    2, 0x08 /* Private */,
       9,    0,   73,    2, 0x08 /* Private */,
      10,    0,   74,    2, 0x08 /* Private */,
      11,    0,   75,    2, 0x08 /* Private */,

 // signals: parameters
    QMetaType::Void,
    QMetaType::Void, QMetaType::QString,    2,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,

 // slots: parameters
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,

       0        // eod
};

void counter_rate_monitor::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        auto *_t = static_cast<counter_rate_monitor *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->cnt_rate_ready(); break;
        case 1: _t->cnt_rate_message((*reinterpret_cast< QString(*)>(_a[1]))); break;
        case 2: _t->FIFO_OK(); break;
        case 3: _t->check_overfill(); break;
        case 4: _t->No_FIFO_data(); break;
        case 5: _t->FIFO_isOK(); break;
        case 6: _t->clear_FIFO(); break;
        case 7: _t->cnt_rate(); break;
        case 8: _t->clear_rates(); break;
        case 9: _t->get_counters(); break;
        default: ;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        {
            using _t = void (counter_rate_monitor::*)();
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&counter_rate_monitor::cnt_rate_ready)) {
                *result = 0;
                return;
            }
        }
        {
            using _t = void (counter_rate_monitor::*)(QString );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&counter_rate_monitor::cnt_rate_message)) {
                *result = 1;
                return;
            }
        }
        {
            using _t = void (counter_rate_monitor::*)();
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&counter_rate_monitor::FIFO_OK)) {
                *result = 2;
                return;
            }
        }
        {
            using _t = void (counter_rate_monitor::*)();
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&counter_rate_monitor::check_overfill)) {
                *result = 3;
                return;
            }
        }
        {
            using _t = void (counter_rate_monitor::*)();
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&counter_rate_monitor::No_FIFO_data)) {
                *result = 4;
                return;
            }
        }
    }
}

QT_INIT_METAOBJECT const QMetaObject counter_rate_monitor::staticMetaObject = { {
    &QObject::staticMetaObject,
    qt_meta_stringdata_counter_rate_monitor.data,
    qt_meta_data_counter_rate_monitor,
    qt_static_metacall,
    nullptr,
    nullptr
} };


const QMetaObject *counter_rate_monitor::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *counter_rate_monitor::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_counter_rate_monitor.stringdata0))
        return static_cast<void*>(this);
    return QObject::qt_metacast(_clname);
}

int counter_rate_monitor::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
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
            *reinterpret_cast<int*>(_a[0]) = -1;
        _id -= 10;
    }
    return _id;
}

// SIGNAL 0
void counter_rate_monitor::cnt_rate_ready()
{
    QMetaObject::activate(this, &staticMetaObject, 0, nullptr);
}

// SIGNAL 1
void counter_rate_monitor::cnt_rate_message(QString _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t1))) };
    QMetaObject::activate(this, &staticMetaObject, 1, _a);
}

// SIGNAL 2
void counter_rate_monitor::FIFO_OK()
{
    QMetaObject::activate(this, &staticMetaObject, 2, nullptr);
}

// SIGNAL 3
void counter_rate_monitor::check_overfill()
{
    QMetaObject::activate(this, &staticMetaObject, 3, nullptr);
}

// SIGNAL 4
void counter_rate_monitor::No_FIFO_data()
{
    QMetaObject::activate(this, &staticMetaObject, 4, nullptr);
}
QT_WARNING_POP
QT_END_MOC_NAMESPACE
