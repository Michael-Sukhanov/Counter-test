/****************************************************************************
** Meta object code from reading C++ file 'ipbusinterface.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.13.0)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include <memory>
#include "ipbusinterface.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'ipbusinterface.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.13.0. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
struct qt_meta_stringdata_IPbusTarget_t {
    QByteArrayData data[27];
    char stringdata0[286];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_IPbusTarget_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_IPbusTarget_t qt_meta_stringdata_IPbusTarget = {
    {
QT_MOC_LITERAL(0, 0, 11), // "IPbusTarget"
QT_MOC_LITERAL(1, 12, 12), // "networkError"
QT_MOC_LITERAL(2, 25, 0), // ""
QT_MOC_LITERAL(3, 26, 10), // "IPbusError"
QT_MOC_LITERAL(4, 37, 10), // "logicError"
QT_MOC_LITERAL(5, 48, 13), // "IPbusStatusOK"
QT_MOC_LITERAL(6, 62, 15), // "statusDataReady"
QT_MOC_LITERAL(7, 78, 14), // "successfulRead"
QT_MOC_LITERAL(8, 93, 6), // "nWords"
QT_MOC_LITERAL(9, 100, 15), // "successfulWrite"
QT_MOC_LITERAL(10, 116, 17), // "resetTransactions"
QT_MOC_LITERAL(11, 134, 5), // "error"
QT_MOC_LITERAL(12, 140, 6), // "reinit"
QT_MOC_LITERAL(13, 147, 13), // "requestStatus"
QT_MOC_LITERAL(14, 161, 4), // "sync"
QT_MOC_LITERAL(15, 166, 12), // "readRegister"
QT_MOC_LITERAL(16, 179, 8), // "quint32*"
QT_MOC_LITERAL(17, 188, 4), // "data"
QT_MOC_LITERAL(18, 193, 7), // "address"
QT_MOC_LITERAL(19, 201, 13), // "writeRegister"
QT_MOC_LITERAL(20, 215, 29), // "Non_incrementing_readRegister"
QT_MOC_LITERAL(21, 245, 6), // "setBit"
QT_MOC_LITERAL(22, 252, 1), // "n"
QT_MOC_LITERAL(23, 254, 8), // "clearBit"
QT_MOC_LITERAL(24, 263, 10), // "writeNbits"
QT_MOC_LITERAL(25, 274, 5), // "nbits"
QT_MOC_LITERAL(26, 280, 5) // "shift"

    },
    "IPbusTarget\0networkError\0\0IPbusError\0"
    "logicError\0IPbusStatusOK\0statusDataReady\0"
    "successfulRead\0nWords\0successfulWrite\0"
    "resetTransactions\0error\0reinit\0"
    "requestStatus\0sync\0readRegister\0"
    "quint32*\0data\0address\0writeRegister\0"
    "Non_incrementing_readRegister\0setBit\0"
    "n\0clearBit\0writeNbits\0nbits\0shift"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_IPbusTarget[] = {

 // content:
       8,       // revision
       0,       // classname
       0,    0, // classinfo
      20,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       7,       // signalCount

 // signals: name, argc, parameters, tag, flags
       1,    1,  114,    2, 0x06 /* Public */,
       3,    1,  117,    2, 0x06 /* Public */,
       4,    1,  120,    2, 0x06 /* Public */,
       5,    0,  123,    2, 0x06 /* Public */,
       6,    0,  124,    2, 0x06 /* Public */,
       7,    1,  125,    2, 0x06 /* Public */,
       9,    1,  128,    2, 0x06 /* Public */,

 // slots: name, argc, parameters, tag, flags
      10,    0,  131,    2, 0x08 /* Private */,
      11,    0,  132,    2, 0x08 /* Private */,
      12,    0,  133,    2, 0x0a /* Public */,
      13,    0,  134,    2, 0x0a /* Public */,
      14,    0,  135,    2, 0x0a /* Public */,
      15,    2,  136,    2, 0x0a /* Public */,
      19,    2,  141,    2, 0x0a /* Public */,
      20,    3,  146,    2, 0x0a /* Public */,
      21,    2,  153,    2, 0x0a /* Public */,
      23,    2,  158,    2, 0x0a /* Public */,
      24,    4,  163,    2, 0x0a /* Public */,
      24,    3,  172,    2, 0x2a /* Public | MethodCloned */,
      24,    2,  179,    2, 0x2a /* Public | MethodCloned */,

 // signals: parameters
    QMetaType::Void, QMetaType::QString,    2,
    QMetaType::Void, QMetaType::QString,    2,
    QMetaType::Void, QMetaType::QString,    2,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void, QMetaType::UChar,    8,
    QMetaType::Void, QMetaType::UChar,    8,

 // slots: parameters
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Bool, 0x80000000 | 16, QMetaType::UInt,   17,   18,
    QMetaType::Bool, QMetaType::UInt, QMetaType::UInt,   17,   18,
    QMetaType::Bool, 0x80000000 | 16, QMetaType::UInt, QMetaType::UChar,   17,   18,    8,
    QMetaType::Void, QMetaType::UChar, QMetaType::UInt,   22,   18,
    QMetaType::Void, QMetaType::UChar, QMetaType::UInt,   22,   18,
    QMetaType::Void, QMetaType::UInt, QMetaType::UInt, QMetaType::UChar, QMetaType::UChar,   17,   18,   25,   26,
    QMetaType::Void, QMetaType::UInt, QMetaType::UInt, QMetaType::UChar,   17,   18,   25,
    QMetaType::Void, QMetaType::UInt, QMetaType::UInt,   17,   18,

       0        // eod
};

void IPbusTarget::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        auto *_t = static_cast<IPbusTarget *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->networkError((*reinterpret_cast< QString(*)>(_a[1]))); break;
        case 1: _t->IPbusError((*reinterpret_cast< QString(*)>(_a[1]))); break;
        case 2: _t->logicError((*reinterpret_cast< QString(*)>(_a[1]))); break;
        case 3: _t->IPbusStatusOK(); break;
        case 4: _t->statusDataReady(); break;
        case 5: _t->successfulRead((*reinterpret_cast< quint8(*)>(_a[1]))); break;
        case 6: _t->successfulWrite((*reinterpret_cast< quint8(*)>(_a[1]))); break;
        case 7: _t->resetTransactions(); break;
        case 8: _t->error(); break;
        case 9: _t->reinit(); break;
        case 10: _t->requestStatus(); break;
        case 11: _t->sync(); break;
        case 12: { bool _r = _t->readRegister((*reinterpret_cast< quint32*(*)>(_a[1])),(*reinterpret_cast< quint32(*)>(_a[2])));
            if (_a[0]) *reinterpret_cast< bool*>(_a[0]) = std::move(_r); }  break;
        case 13: { bool _r = _t->writeRegister((*reinterpret_cast< quint32(*)>(_a[1])),(*reinterpret_cast< quint32(*)>(_a[2])));
            if (_a[0]) *reinterpret_cast< bool*>(_a[0]) = std::move(_r); }  break;
        case 14: { bool _r = _t->Non_incrementing_readRegister((*reinterpret_cast< quint32*(*)>(_a[1])),(*reinterpret_cast< quint32(*)>(_a[2])),(*reinterpret_cast< quint8(*)>(_a[3])));
            if (_a[0]) *reinterpret_cast< bool*>(_a[0]) = std::move(_r); }  break;
        case 15: _t->setBit((*reinterpret_cast< quint8(*)>(_a[1])),(*reinterpret_cast< quint32(*)>(_a[2]))); break;
        case 16: _t->clearBit((*reinterpret_cast< quint8(*)>(_a[1])),(*reinterpret_cast< quint32(*)>(_a[2]))); break;
        case 17: _t->writeNbits((*reinterpret_cast< quint32(*)>(_a[1])),(*reinterpret_cast< quint32(*)>(_a[2])),(*reinterpret_cast< quint8(*)>(_a[3])),(*reinterpret_cast< quint8(*)>(_a[4]))); break;
        case 18: _t->writeNbits((*reinterpret_cast< quint32(*)>(_a[1])),(*reinterpret_cast< quint32(*)>(_a[2])),(*reinterpret_cast< quint8(*)>(_a[3]))); break;
        case 19: _t->writeNbits((*reinterpret_cast< quint32(*)>(_a[1])),(*reinterpret_cast< quint32(*)>(_a[2]))); break;
        default: ;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        {
            using _t = void (IPbusTarget::*)(QString );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&IPbusTarget::networkError)) {
                *result = 0;
                return;
            }
        }
        {
            using _t = void (IPbusTarget::*)(QString );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&IPbusTarget::IPbusError)) {
                *result = 1;
                return;
            }
        }
        {
            using _t = void (IPbusTarget::*)(QString );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&IPbusTarget::logicError)) {
                *result = 2;
                return;
            }
        }
        {
            using _t = void (IPbusTarget::*)();
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&IPbusTarget::IPbusStatusOK)) {
                *result = 3;
                return;
            }
        }
        {
            using _t = void (IPbusTarget::*)();
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&IPbusTarget::statusDataReady)) {
                *result = 4;
                return;
            }
        }
        {
            using _t = void (IPbusTarget::*)(quint8 );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&IPbusTarget::successfulRead)) {
                *result = 5;
                return;
            }
        }
        {
            using _t = void (IPbusTarget::*)(quint8 );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&IPbusTarget::successfulWrite)) {
                *result = 6;
                return;
            }
        }
    }
}

QT_INIT_METAOBJECT const QMetaObject IPbusTarget::staticMetaObject = { {
    &QObject::staticMetaObject,
    qt_meta_stringdata_IPbusTarget.data,
    qt_meta_data_IPbusTarget,
    qt_static_metacall,
    nullptr,
    nullptr
} };


const QMetaObject *IPbusTarget::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *IPbusTarget::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_IPbusTarget.stringdata0))
        return static_cast<void*>(this);
    return QObject::qt_metacast(_clname);
}

int IPbusTarget::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QObject::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 20)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 20;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 20)
            *reinterpret_cast<int*>(_a[0]) = -1;
        _id -= 20;
    }
    return _id;
}

// SIGNAL 0
void IPbusTarget::networkError(QString _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t1))) };
    QMetaObject::activate(this, &staticMetaObject, 0, _a);
}

// SIGNAL 1
void IPbusTarget::IPbusError(QString _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t1))) };
    QMetaObject::activate(this, &staticMetaObject, 1, _a);
}

// SIGNAL 2
void IPbusTarget::logicError(QString _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t1))) };
    QMetaObject::activate(this, &staticMetaObject, 2, _a);
}

// SIGNAL 3
void IPbusTarget::IPbusStatusOK()
{
    QMetaObject::activate(this, &staticMetaObject, 3, nullptr);
}

// SIGNAL 4
void IPbusTarget::statusDataReady()
{
    QMetaObject::activate(this, &staticMetaObject, 4, nullptr);
}

// SIGNAL 5
void IPbusTarget::successfulRead(quint8 _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t1))) };
    QMetaObject::activate(this, &staticMetaObject, 5, _a);
}

// SIGNAL 6
void IPbusTarget::successfulWrite(quint8 _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t1))) };
    QMetaObject::activate(this, &staticMetaObject, 6, _a);
}
QT_WARNING_POP
QT_END_MOC_NAMESPACE
