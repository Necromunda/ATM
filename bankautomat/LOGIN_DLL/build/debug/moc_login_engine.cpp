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
    QByteArrayData data[18];
    char stringdata0[201];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_LOGIN_ENGINE_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_LOGIN_ENGINE_t qt_meta_stringdata_LOGIN_ENGINE = {
    {
QT_MOC_LITERAL(0, 0, 12), // "LOGIN_ENGINE"
QT_MOC_LITERAL(1, 13, 9), // "startAuth"
QT_MOC_LITERAL(2, 23, 0), // ""
QT_MOC_LITERAL(3, 24, 16), // "sendTokenToLogin"
QT_MOC_LITERAL(4, 41, 11), // "wrongPinMsg"
QT_MOC_LITERAL(5, 53, 19), // "loginFailedInEngine"
QT_MOC_LITERAL(6, 73, 10), // "beginTimer"
QT_MOC_LITERAL(7, 84, 9), // "killTimer"
QT_MOC_LITERAL(8, 94, 10), // "resetTimer"
QT_MOC_LITERAL(9, 105, 8), // "cardLock"
QT_MOC_LITERAL(10, 114, 7), // "recvPin"
QT_MOC_LITERAL(11, 122, 14), // "recvCardNumber"
QT_MOC_LITERAL(12, 137, 8), // "tokenReq"
QT_MOC_LITERAL(13, 146, 8), // "tokenRes"
QT_MOC_LITERAL(14, 155, 14), // "QNetworkReply*"
QT_MOC_LITERAL(15, 170, 5), // "reply"
QT_MOC_LITERAL(16, 176, 15), // "cardLockHandler"
QT_MOC_LITERAL(17, 192, 8) // "rejected"

    },
    "LOGIN_ENGINE\0startAuth\0\0sendTokenToLogin\0"
    "wrongPinMsg\0loginFailedInEngine\0"
    "beginTimer\0killTimer\0resetTimer\0"
    "cardLock\0recvPin\0recvCardNumber\0"
    "tokenReq\0tokenRes\0QNetworkReply*\0reply\0"
    "cardLockHandler\0rejected"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_LOGIN_ENGINE[] = {

 // content:
       8,       // revision
       0,       // classname
       0,    0, // classinfo
      14,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       8,       // signalCount

 // signals: name, argc, parameters, tag, flags
       1,    1,   84,    2, 0x06 /* Public */,
       3,    1,   87,    2, 0x06 /* Public */,
       4,    1,   90,    2, 0x06 /* Public */,
       5,    0,   93,    2, 0x06 /* Public */,
       6,    0,   94,    2, 0x06 /* Public */,
       7,    0,   95,    2, 0x06 /* Public */,
       8,    0,   96,    2, 0x06 /* Public */,
       9,    1,   97,    2, 0x06 /* Public */,

 // slots: name, argc, parameters, tag, flags
      10,    1,  100,    2, 0x08 /* Private */,
      11,    1,  103,    2, 0x08 /* Private */,
      12,    1,  106,    2, 0x08 /* Private */,
      13,    1,  109,    2, 0x08 /* Private */,
      16,    1,  112,    2, 0x08 /* Private */,
      17,    0,  115,    2, 0x08 /* Private */,

 // signals: parameters
    QMetaType::Void, QMetaType::QString,    2,
    QMetaType::Void, QMetaType::QByteArray,    2,
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
    QMetaType::Void, 0x80000000 | 14,   15,
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
        case 0: _t->startAuth((*reinterpret_cast< QString(*)>(_a[1]))); break;
        case 1: _t->sendTokenToLogin((*reinterpret_cast< QByteArray(*)>(_a[1]))); break;
        case 2: _t->wrongPinMsg((*reinterpret_cast< QString(*)>(_a[1]))); break;
        case 3: _t->loginFailedInEngine(); break;
        case 4: _t->beginTimer(); break;
        case 5: _t->killTimer(); break;
        case 6: _t->resetTimer(); break;
        case 7: _t->cardLock((*reinterpret_cast< QString(*)>(_a[1]))); break;
        case 8: _t->recvPin((*reinterpret_cast< QString(*)>(_a[1]))); break;
        case 9: _t->recvCardNumber((*reinterpret_cast< QString(*)>(_a[1]))); break;
        case 10: _t->tokenReq((*reinterpret_cast< QString(*)>(_a[1]))); break;
        case 11: _t->tokenRes((*reinterpret_cast< QNetworkReply*(*)>(_a[1]))); break;
        case 12: _t->cardLockHandler((*reinterpret_cast< QString(*)>(_a[1]))); break;
        case 13: _t->rejected(); break;
        default: ;
        }
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        switch (_id) {
        default: *reinterpret_cast<int*>(_a[0]) = -1; break;
        case 11:
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
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&LOGIN_ENGINE::startAuth)) {
                *result = 0;
                return;
            }
        }
        {
            using _t = void (LOGIN_ENGINE::*)(QByteArray );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&LOGIN_ENGINE::sendTokenToLogin)) {
                *result = 1;
                return;
            }
        }
        {
            using _t = void (LOGIN_ENGINE::*)(QString );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&LOGIN_ENGINE::wrongPinMsg)) {
                *result = 2;
                return;
            }
        }
        {
            using _t = void (LOGIN_ENGINE::*)();
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&LOGIN_ENGINE::loginFailedInEngine)) {
                *result = 3;
                return;
            }
        }
        {
            using _t = void (LOGIN_ENGINE::*)();
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&LOGIN_ENGINE::beginTimer)) {
                *result = 4;
                return;
            }
        }
        {
            using _t = void (LOGIN_ENGINE::*)();
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&LOGIN_ENGINE::killTimer)) {
                *result = 5;
                return;
            }
        }
        {
            using _t = void (LOGIN_ENGINE::*)();
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&LOGIN_ENGINE::resetTimer)) {
                *result = 6;
                return;
            }
        }
        {
            using _t = void (LOGIN_ENGINE::*)(QString );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&LOGIN_ENGINE::cardLock)) {
                *result = 7;
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
        if (_id < 14)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 14;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 14)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 14;
    }
    return _id;
}

// SIGNAL 0
void LOGIN_ENGINE::startAuth(QString _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t1))) };
    QMetaObject::activate(this, &staticMetaObject, 0, _a);
}

// SIGNAL 1
void LOGIN_ENGINE::sendTokenToLogin(QByteArray _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t1))) };
    QMetaObject::activate(this, &staticMetaObject, 1, _a);
}

// SIGNAL 2
void LOGIN_ENGINE::wrongPinMsg(QString _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t1))) };
    QMetaObject::activate(this, &staticMetaObject, 2, _a);
}

// SIGNAL 3
void LOGIN_ENGINE::loginFailedInEngine()
{
    QMetaObject::activate(this, &staticMetaObject, 3, nullptr);
}

// SIGNAL 4
void LOGIN_ENGINE::beginTimer()
{
    QMetaObject::activate(this, &staticMetaObject, 4, nullptr);
}

// SIGNAL 5
void LOGIN_ENGINE::killTimer()
{
    QMetaObject::activate(this, &staticMetaObject, 5, nullptr);
}

// SIGNAL 6
void LOGIN_ENGINE::resetTimer()
{
    QMetaObject::activate(this, &staticMetaObject, 6, nullptr);
}

// SIGNAL 7
void LOGIN_ENGINE::cardLock(QString _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t1))) };
    QMetaObject::activate(this, &staticMetaObject, 7, _a);
}
QT_WARNING_POP
QT_END_MOC_NAMESPACE
