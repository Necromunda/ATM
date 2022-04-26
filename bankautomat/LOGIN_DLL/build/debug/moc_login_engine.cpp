/****************************************************************************
** Meta object code from reading C++ file 'login_engine.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.15.2)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include <memory>
#include "../../login_engine.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'login_engine.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.15.2. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
struct qt_meta_stringdata_LOGIN_ENGINE_t {
    QByteArrayData data[22];
    char stringdata0[266];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_LOGIN_ENGINE_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_LOGIN_ENGINE_t qt_meta_stringdata_LOGIN_ENGINE = {
    {
QT_MOC_LITERAL(0, 0, 12), // "LOGIN_ENGINE"
QT_MOC_LITERAL(1, 13, 19), // "askForDebitOrCredit"
QT_MOC_LITERAL(2, 33, 0), // ""
QT_MOC_LITERAL(3, 34, 9), // "startAuth"
QT_MOC_LITERAL(4, 44, 16), // "sendTokenToLogin"
QT_MOC_LITERAL(5, 61, 11), // "wrongPinMsg"
QT_MOC_LITERAL(6, 73, 19), // "loginFailedInEngine"
QT_MOC_LITERAL(7, 93, 10), // "beginTimer"
QT_MOC_LITERAL(8, 104, 9), // "killTimer"
QT_MOC_LITERAL(9, 114, 10), // "resetTimer"
QT_MOC_LITERAL(10, 125, 8), // "cardLock"
QT_MOC_LITERAL(11, 134, 16), // "askDebitOrCredit"
QT_MOC_LITERAL(12, 151, 14), // "checkForCredit"
QT_MOC_LITERAL(13, 166, 12), // "recvCardType"
QT_MOC_LITERAL(14, 179, 7), // "recvPin"
QT_MOC_LITERAL(15, 187, 14), // "recvCardNumber"
QT_MOC_LITERAL(16, 202, 8), // "tokenReq"
QT_MOC_LITERAL(17, 211, 8), // "tokenRes"
QT_MOC_LITERAL(18, 220, 14), // "QNetworkReply*"
QT_MOC_LITERAL(19, 235, 5), // "reply"
QT_MOC_LITERAL(20, 241, 15), // "cardLockHandler"
QT_MOC_LITERAL(21, 257, 8) // "rejected"

    },
    "LOGIN_ENGINE\0askForDebitOrCredit\0\0"
    "startAuth\0sendTokenToLogin\0wrongPinMsg\0"
    "loginFailedInEngine\0beginTimer\0killTimer\0"
    "resetTimer\0cardLock\0askDebitOrCredit\0"
    "checkForCredit\0recvCardType\0recvPin\0"
    "recvCardNumber\0tokenReq\0tokenRes\0"
    "QNetworkReply*\0reply\0cardLockHandler\0"
    "rejected"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_LOGIN_ENGINE[] = {

 // content:
       8,       // revision
       0,       // classname
       0,    0, // classinfo
      18,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       9,       // signalCount

 // signals: name, argc, parameters, tag, flags
       1,    1,  104,    2, 0x06 /* Public */,
       3,    1,  107,    2, 0x06 /* Public */,
       4,    2,  110,    2, 0x06 /* Public */,
       5,    1,  115,    2, 0x06 /* Public */,
       6,    0,  118,    2, 0x06 /* Public */,
       7,    0,  119,    2, 0x06 /* Public */,
       8,    0,  120,    2, 0x06 /* Public */,
       9,    0,  121,    2, 0x06 /* Public */,
      10,    1,  122,    2, 0x06 /* Public */,

 // slots: name, argc, parameters, tag, flags
      11,    1,  125,    2, 0x08 /* Private */,
      12,    1,  128,    2, 0x08 /* Private */,
      13,    1,  131,    2, 0x08 /* Private */,
      14,    1,  134,    2, 0x08 /* Private */,
      15,    1,  137,    2, 0x08 /* Private */,
      16,    1,  140,    2, 0x08 /* Private */,
      17,    1,  143,    2, 0x08 /* Private */,
      20,    1,  146,    2, 0x08 /* Private */,
      21,    0,  149,    2, 0x08 /* Private */,

 // signals: parameters
    QMetaType::Void, QMetaType::QString,    2,
    QMetaType::Void, QMetaType::QString,    2,
    QMetaType::Void, QMetaType::QByteArray, QMetaType::QString,    2,    2,
    QMetaType::Void, QMetaType::QString,    2,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void, QMetaType::QString,    2,

 // slots: parameters
    QMetaType::Void, QMetaType::QString,    2,
    QMetaType::Void, QMetaType::QString,    2,
    QMetaType::Void, QMetaType::QString,    2,
    QMetaType::Void, QMetaType::QString,    2,
    QMetaType::Void, QMetaType::QString,    2,
    QMetaType::Void, QMetaType::QString,    2,
    QMetaType::Void, 0x80000000 | 18,   19,
    QMetaType::Void, QMetaType::QString,    2,
    QMetaType::Void,

       0        // eod
};

void LOGIN_ENGINE::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        auto *_t = static_cast<LOGIN_ENGINE *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->askForDebitOrCredit((*reinterpret_cast< QString(*)>(_a[1]))); break;
        case 1: _t->startAuth((*reinterpret_cast< QString(*)>(_a[1]))); break;
        case 2: _t->sendTokenToLogin((*reinterpret_cast< QByteArray(*)>(_a[1])),(*reinterpret_cast< QString(*)>(_a[2]))); break;
        case 3: _t->wrongPinMsg((*reinterpret_cast< QString(*)>(_a[1]))); break;
        case 4: _t->loginFailedInEngine(); break;
        case 5: _t->beginTimer(); break;
        case 6: _t->killTimer(); break;
        case 7: _t->resetTimer(); break;
        case 8: _t->cardLock((*reinterpret_cast< QString(*)>(_a[1]))); break;
        case 9: _t->askDebitOrCredit((*reinterpret_cast< QString(*)>(_a[1]))); break;
        case 10: _t->checkForCredit((*reinterpret_cast< QString(*)>(_a[1]))); break;
        case 11: _t->recvCardType((*reinterpret_cast< QString(*)>(_a[1]))); break;
        case 12: _t->recvPin((*reinterpret_cast< QString(*)>(_a[1]))); break;
        case 13: _t->recvCardNumber((*reinterpret_cast< QString(*)>(_a[1]))); break;
        case 14: _t->tokenReq((*reinterpret_cast< QString(*)>(_a[1]))); break;
        case 15: _t->tokenRes((*reinterpret_cast< QNetworkReply*(*)>(_a[1]))); break;
        case 16: _t->cardLockHandler((*reinterpret_cast< QString(*)>(_a[1]))); break;
        case 17: _t->rejected(); break;
        default: ;
        }
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        switch (_id) {
        default: *reinterpret_cast<int*>(_a[0]) = -1; break;
        case 15:
            switch (*reinterpret_cast<int*>(_a[1])) {
            default: *reinterpret_cast<int*>(_a[0]) = -1; break;
            case 0:
                *reinterpret_cast<int*>(_a[0]) = qRegisterMetaType< QNetworkReply* >(); break;
            }
            break;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        {
            using _t = void (LOGIN_ENGINE::*)(QString );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&LOGIN_ENGINE::askForDebitOrCredit)) {
                *result = 0;
                return;
            }
        }
        {
            using _t = void (LOGIN_ENGINE::*)(QString );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&LOGIN_ENGINE::startAuth)) {
                *result = 1;
                return;
            }
        }
        {
            using _t = void (LOGIN_ENGINE::*)(QByteArray , QString );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&LOGIN_ENGINE::sendTokenToLogin)) {
                *result = 2;
                return;
            }
        }
        {
            using _t = void (LOGIN_ENGINE::*)(QString );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&LOGIN_ENGINE::wrongPinMsg)) {
                *result = 3;
                return;
            }
        }
        {
            using _t = void (LOGIN_ENGINE::*)();
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&LOGIN_ENGINE::loginFailedInEngine)) {
                *result = 4;
                return;
            }
        }
        {
            using _t = void (LOGIN_ENGINE::*)();
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&LOGIN_ENGINE::beginTimer)) {
                *result = 5;
                return;
            }
        }
        {
            using _t = void (LOGIN_ENGINE::*)();
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&LOGIN_ENGINE::killTimer)) {
                *result = 6;
                return;
            }
        }
        {
            using _t = void (LOGIN_ENGINE::*)();
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&LOGIN_ENGINE::resetTimer)) {
                *result = 7;
                return;
            }
        }
        {
            using _t = void (LOGIN_ENGINE::*)(QString );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&LOGIN_ENGINE::cardLock)) {
                *result = 8;
                return;
            }
        }
    }
}

QT_INIT_METAOBJECT const QMetaObject LOGIN_ENGINE::staticMetaObject = { {
    QMetaObject::SuperData::link<QObject::staticMetaObject>(),
    qt_meta_stringdata_LOGIN_ENGINE.data,
    qt_meta_data_LOGIN_ENGINE,
    qt_static_metacall,
    nullptr,
    nullptr
} };


const QMetaObject *LOGIN_ENGINE::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *LOGIN_ENGINE::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_LOGIN_ENGINE.stringdata0))
        return static_cast<void*>(this);
    return QObject::qt_metacast(_clname);
}

int LOGIN_ENGINE::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QObject::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 18)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 18;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 18)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 18;
    }
    return _id;
}

// SIGNAL 0
void LOGIN_ENGINE::askForDebitOrCredit(QString _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t1))) };
    QMetaObject::activate(this, &staticMetaObject, 0, _a);
}

// SIGNAL 1
void LOGIN_ENGINE::startAuth(QString _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t1))) };
    QMetaObject::activate(this, &staticMetaObject, 1, _a);
}

// SIGNAL 2
void LOGIN_ENGINE::sendTokenToLogin(QByteArray _t1, QString _t2)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t1))), const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t2))) };
    QMetaObject::activate(this, &staticMetaObject, 2, _a);
}

// SIGNAL 3
void LOGIN_ENGINE::wrongPinMsg(QString _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t1))) };
    QMetaObject::activate(this, &staticMetaObject, 3, _a);
}

// SIGNAL 4
void LOGIN_ENGINE::loginFailedInEngine()
{
    QMetaObject::activate(this, &staticMetaObject, 4, nullptr);
}

// SIGNAL 5
void LOGIN_ENGINE::beginTimer()
{
    QMetaObject::activate(this, &staticMetaObject, 5, nullptr);
}

// SIGNAL 6
void LOGIN_ENGINE::killTimer()
{
    QMetaObject::activate(this, &staticMetaObject, 6, nullptr);
}

// SIGNAL 7
void LOGIN_ENGINE::resetTimer()
{
    QMetaObject::activate(this, &staticMetaObject, 7, nullptr);
}

// SIGNAL 8
void LOGIN_ENGINE::cardLock(QString _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t1))) };
    QMetaObject::activate(this, &staticMetaObject, 8, _a);
}
QT_WARNING_POP
QT_END_MOC_NAMESPACE
