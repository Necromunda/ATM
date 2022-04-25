/****************************************************************************
** Meta object code from reading C++ file 'login_dll.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.15.2)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include <memory>
#include "../../login_dll.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'login_dll.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.15.2. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
struct qt_meta_stringdata_LOGIN_DLL_t {
    QByteArrayData data[8];
    char stringdata0[120];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_LOGIN_DLL_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_LOGIN_DLL_t qt_meta_stringdata_LOGIN_DLL = {
    {
QT_MOC_LITERAL(0, 0, 9), // "LOGIN_DLL"
QT_MOC_LITERAL(1, 10, 11), // "restartRFID"
QT_MOC_LITERAL(2, 22, 0), // ""
QT_MOC_LITERAL(3, 23, 27), // "sendCardNumberToLoginEngine"
QT_MOC_LITERAL(4, 51, 14), // "sendTokenToExe"
QT_MOC_LITERAL(5, 66, 11), // "loginFailed"
QT_MOC_LITERAL(6, 78, 21), // "recvCardNumberFromExe"
QT_MOC_LITERAL(7, 100, 19) // "recvTokenFromEngine"

    },
    "LOGIN_DLL\0restartRFID\0\0"
    "sendCardNumberToLoginEngine\0sendTokenToExe\0"
    "loginFailed\0recvCardNumberFromExe\0"
    "recvTokenFromEngine"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_LOGIN_DLL[] = {

 // content:
       8,       // revision
       0,       // classname
       0,    0, // classinfo
       6,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       3,       // signalCount

 // signals: name, argc, parameters, tag, flags
       1,    0,   44,    2, 0x06 /* Public */,
       3,    1,   45,    2, 0x06 /* Public */,
       4,    1,   48,    2, 0x06 /* Public */,

 // slots: name, argc, parameters, tag, flags
       5,    0,   51,    2, 0x08 /* Private */,
       6,    1,   52,    2, 0x08 /* Private */,
       7,    1,   55,    2, 0x08 /* Private */,

 // signals: parameters
    QMetaType::Void,
    QMetaType::Void, QMetaType::QString,    2,
    QMetaType::Void, QMetaType::QByteArray,    2,

 // slots: parameters
    QMetaType::Void,
    QMetaType::Void, QMetaType::QString,    2,
    QMetaType::Void, QMetaType::QByteArray,    2,

       0        // eod
};

void LOGIN_DLL::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        auto *_t = static_cast<LOGIN_DLL *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->restartRFID(); break;
        case 1: _t->sendCardNumberToLoginEngine((*reinterpret_cast< QString(*)>(_a[1]))); break;
        case 2: _t->sendTokenToExe((*reinterpret_cast< QByteArray(*)>(_a[1]))); break;
        case 3: _t->loginFailed(); break;
        case 4: _t->recvCardNumberFromExe((*reinterpret_cast< QString(*)>(_a[1]))); break;
        case 5: _t->recvTokenFromEngine((*reinterpret_cast< QByteArray(*)>(_a[1]))); break;
        default: ;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        {
            using _t = void (LOGIN_DLL::*)();
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&LOGIN_DLL::restartRFID)) {
                *result = 0;
                return;
            }
        }
        {
            using _t = void (LOGIN_DLL::*)(QString );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&LOGIN_DLL::sendCardNumberToLoginEngine)) {
                *result = 1;
                return;
            }
        }
        {
            using _t = void (LOGIN_DLL::*)(QByteArray );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&LOGIN_DLL::sendTokenToExe)) {
                *result = 2;
                return;
            }
        }
    }
}

QT_INIT_METAOBJECT const QMetaObject LOGIN_DLL::staticMetaObject = { {
    QMetaObject::SuperData::link<QObject::staticMetaObject>(),
    qt_meta_stringdata_LOGIN_DLL.data,
    qt_meta_data_LOGIN_DLL,
    qt_static_metacall,
    nullptr,
    nullptr
} };


const QMetaObject *LOGIN_DLL::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *LOGIN_DLL::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_LOGIN_DLL.stringdata0))
        return static_cast<void*>(this);
    return QObject::qt_metacast(_clname);
}

int LOGIN_DLL::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QObject::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 6)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 6;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 6)
            *reinterpret_cast<int*>(_a[0]) = -1;
        _id -= 6;
    }
    return _id;
}

// SIGNAL 0
void LOGIN_DLL::restartRFID()
{
    QMetaObject::activate(this, &staticMetaObject, 0, nullptr);
}

// SIGNAL 1
void LOGIN_DLL::sendCardNumberToLoginEngine(QString _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t1))) };
    QMetaObject::activate(this, &staticMetaObject, 1, _a);
}

// SIGNAL 2
void LOGIN_DLL::sendTokenToExe(QByteArray _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t1))) };
    QMetaObject::activate(this, &staticMetaObject, 2, _a);
}
QT_WARNING_POP
QT_END_MOC_NAMESPACE
