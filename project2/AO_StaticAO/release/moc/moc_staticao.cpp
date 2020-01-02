/****************************************************************************
** Meta object code from reading C++ file 'staticao.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.13.1)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include <memory>
#include "../../staticao.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'staticao.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.13.1. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
struct qt_meta_stringdata_StaticAO_t {
    QByteArrayData data[14];
    char stringdata0[204];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_StaticAO_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_StaticAO_t qt_meta_stringdata_StaticAO = {
    {
QT_MOC_LITERAL(0, 0, 8), // "StaticAO"
QT_MOC_LITERAL(1, 9, 18), // "ButtonStartClicked"
QT_MOC_LITERAL(2, 28, 0), // ""
QT_MOC_LITERAL(3, 29, 19), // "ButtonStart2Clicked"
QT_MOC_LITERAL(4, 49, 19), // "ButttonPauseClicked"
QT_MOC_LITERAL(5, 69, 21), // "ButtonOpenDataClicked"
QT_MOC_LITERAL(6, 91, 17), // "ButtonStopClicked"
QT_MOC_LITERAL(7, 109, 11), // "TimerTicked"
QT_MOC_LITERAL(8, 121, 18), // "SliderValueChanged"
QT_MOC_LITERAL(9, 140, 5), // "value"
QT_MOC_LITERAL(10, 146, 22), // "ButtonConfigureClicked"
QT_MOC_LITERAL(11, 169, 13), // "ManualClicked"
QT_MOC_LITERAL(12, 183, 2), // "id"
QT_MOC_LITERAL(13, 186, 17) // "WaveButtonClicked"

    },
    "StaticAO\0ButtonStartClicked\0\0"
    "ButtonStart2Clicked\0ButttonPauseClicked\0"
    "ButtonOpenDataClicked\0ButtonStopClicked\0"
    "TimerTicked\0SliderValueChanged\0value\0"
    "ButtonConfigureClicked\0ManualClicked\0"
    "id\0WaveButtonClicked"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_StaticAO[] = {

 // content:
       8,       // revision
       0,       // classname
       0,    0, // classinfo
      10,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // slots: name, argc, parameters, tag, flags
       1,    0,   64,    2, 0x08 /* Private */,
       3,    0,   65,    2, 0x08 /* Private */,
       4,    0,   66,    2, 0x08 /* Private */,
       5,    0,   67,    2, 0x08 /* Private */,
       6,    0,   68,    2, 0x08 /* Private */,
       7,    0,   69,    2, 0x08 /* Private */,
       8,    1,   70,    2, 0x08 /* Private */,
      10,    0,   73,    2, 0x08 /* Private */,
      11,    1,   74,    2, 0x08 /* Private */,
      13,    1,   77,    2, 0x08 /* Private */,

 // slots: parameters
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void, QMetaType::Int,    9,
    QMetaType::Void,
    QMetaType::Void, QMetaType::Int,   12,
    QMetaType::Void, QMetaType::Int,   12,

       0        // eod
};

void StaticAO::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        auto *_t = static_cast<StaticAO *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->ButtonStartClicked(); break;
        case 1: _t->ButtonStart2Clicked(); break;
        case 2: _t->ButttonPauseClicked(); break;
        case 3: _t->ButtonOpenDataClicked(); break;
        case 4: _t->ButtonStopClicked(); break;
        case 5: _t->TimerTicked(); break;
        case 6: _t->SliderValueChanged((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 7: _t->ButtonConfigureClicked(); break;
        case 8: _t->ManualClicked((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 9: _t->WaveButtonClicked((*reinterpret_cast< int(*)>(_a[1]))); break;
        default: ;
        }
    }
}

QT_INIT_METAOBJECT const QMetaObject StaticAO::staticMetaObject = { {
    &QDialog::staticMetaObject,
    qt_meta_stringdata_StaticAO.data,
    qt_meta_data_StaticAO,
    qt_static_metacall,
    nullptr,
    nullptr
} };


const QMetaObject *StaticAO::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *StaticAO::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_StaticAO.stringdata0))
        return static_cast<void*>(this);
    return QDialog::qt_metacast(_clname);
}

int StaticAO::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QDialog::qt_metacall(_c, _id, _a);
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
QT_WARNING_POP
QT_END_MOC_NAMESPACE
