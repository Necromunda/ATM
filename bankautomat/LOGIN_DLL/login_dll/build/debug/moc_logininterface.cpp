/****************************************************************************
** Meta object code from reading C++ file 'logininterface.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.15.2)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include <memory>
#include "../../logininterface.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'logininterface.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.15.2. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
struct qt_meta_stringdata_LoginInterface_t {
    QByteArrayData data[15];
    char stringdata0[315];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_LoginInterface_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_LoginInterface_t qt_meta_stringdata_LoginInterface = {
    {
QT_MOC_LITERAL(0, 0, 14), // "LoginInterface"
QT_MOC_LITERAL(1, 15, 21), // "on_btn_addone_clicked"
QT_MOC_LITERAL(2, 37, 0), // ""
QT_MOC_LITERAL(3, 38, 21), // "on_btn_addtwo_clicked"
QT_MOC_LITERAL(4, 60, 23), // "on_btn_addthree_clicked"
QT_MOC_LITERAL(5, 84, 22), // "on_btn_addfour_clicked"
QT_MOC_LITERAL(6, 107, 22), // "on_btn_addfive_clicked"
QT_MOC_LITERAL(7, 130, 21), // "on_btn_addsix_clicked"
QT_MOC_LITERAL(8, 152, 23), // "on_btn_addseven_clicked"
QT_MOC_LITERAL(9, 176, 23), // "on_btn_addeight_clicked"
QT_MOC_LITERAL(10, 200, 22), // "on_btn_addnine_clicked"
QT_MOC_LITERAL(11, 223, 22), // "on_btn_addzero_clicked"
QT_MOC_LITERAL(12, 246, 20), // "on_btn_clear_clicked"
QT_MOC_LITERAL(13, 267, 21), // "on_btn_cancel_clicked"
QT_MOC_LITERAL(14, 289, 25) // "on_btn_addconfirm_clicked"

    },
    "LoginInterface\0on_btn_addone_clicked\0"
    "\0on_btn_addtwo_clicked\0on_btn_addthree_clicked\0"
    "on_btn_addfour_clicked\0on_btn_addfive_clicked\0"
    "on_btn_addsix_clicked\0on_btn_addseven_clicked\0"
    "on_btn_addeight_clicked\0on_btn_addnine_clicked\0"
    "on_btn_addzero_clicked\0on_btn_clear_clicked\0"
    "on_btn_cancel_clicked\0on_btn_addconfirm_clicked"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_LoginInterface[] = {

 // content:
       8,       // revision
       0,       // classname
       0,    0, // classinfo
      13,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // slots: name, argc, parameters, tag, flags
       1,    0,   79,    2, 0x08 /* Private */,
       3,    0,   80,    2, 0x08 /* Private */,
       4,    0,   81,    2, 0x08 /* Private */,
       5,    0,   82,    2, 0x08 /* Private */,
       6,    0,   83,    2, 0x08 /* Private */,
       7,    0,   84,    2, 0x08 /* Private */,
       8,    0,   85,    2, 0x08 /* Private */,
       9,    0,   86,    2, 0x08 /* Private */,
      10,    0,   87,    2, 0x08 /* Private */,
      11,    0,   88,    2, 0x08 /* Private */,
      12,    0,   89,    2, 0x08 /* Private */,
      13,    0,   90,    2, 0x08 /* Private */,
      14,    0,   91,    2, 0x08 /* Private */,

 // slots: parameters
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,

       0        // eod
};

void LoginInterface::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        auto *_t = static_cast<LoginInterface *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->on_btn_addone_clicked(); break;
        case 1: _t->on_btn_addtwo_clicked(); break;
        case 2: _t->on_btn_addthree_clicked(); break;
        case 3: _t->on_btn_addfour_clicked(); break;
        case 4: _t->on_btn_addfive_clicked(); break;
        case 5: _t->on_btn_addsix_clicked(); break;
        case 6: _t->on_btn_addseven_clicked(); break;
        case 7: _t->on_btn_addeight_clicked(); break;
        case 8: _t->on_btn_addnine_clicked(); break;
        case 9: _t->on_btn_addzero_clicked(); break;
        case 10: _t->on_btn_clear_clicked(); break;
        case 11: _t->on_btn_cancel_clicked(); break;
        case 12: _t->on_btn_addconfirm_clicked(); break;
        default: ;
        }
    }
    Q_UNUSED(_a);
}

QT_INIT_METAOBJECT const QMetaObject LoginInterface::staticMetaObject = { {
    QMetaObject::SuperData::link<QDialog::staticMetaObject>(),
    qt_meta_stringdata_LoginInterface.data,
    qt_meta_data_LoginInterface,
    qt_static_metacall,
    nullptr,
    nullptr
} };


const QMetaObject *LoginInterface::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *LoginInterface::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_LoginInterface.stringdata0))
        return static_cast<void*>(this);
    return QDialog::qt_metacast(_clname);
}

int LoginInterface::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QDialog::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 13)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 13;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 13)
            *reinterpret_cast<int*>(_a[0]) = -1;
        _id -= 13;
    }
    return _id;
}
QT_WARNING_POP
QT_END_MOC_NAMESPACE
