/****************************************************************************
** Meta object code from reading C++ file 'mainwindow.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.15.2)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include <memory>
#include "../mainwindow.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'mainwindow.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.15.2. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
struct qt_meta_stringdata_MainWindow_t {
    QByteArrayData data[32];
    char stringdata0[336];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_MainWindow_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_MainWindow_t qt_meta_stringdata_MainWindow = {
    {
QT_MOC_LITERAL(0, 0, 10), // "MainWindow"
QT_MOC_LITERAL(1, 11, 14), // "serialDataSend"
QT_MOC_LITERAL(2, 26, 0), // ""
QT_MOC_LITERAL(3, 27, 4), // "data"
QT_MOC_LITERAL(4, 32, 9), // "sendToCmd"
QT_MOC_LITERAL(5, 42, 3), // "cmd"
QT_MOC_LITERAL(6, 46, 10), // "motorState"
QT_MOC_LITERAL(7, 57, 5), // "state"
QT_MOC_LITERAL(8, 63, 8), // "position"
QT_MOC_LITERAL(9, 72, 6), // "doHome"
QT_MOC_LITERAL(10, 79, 14), // "openSerialPort"
QT_MOC_LITERAL(11, 94, 15), // "closeSerialPort"
QT_MOC_LITERAL(12, 110, 9), // "openCurve"
QT_MOC_LITERAL(13, 120, 5), // "about"
QT_MOC_LITERAL(14, 126, 9), // "writeData"
QT_MOC_LITERAL(15, 136, 8), // "readData"
QT_MOC_LITERAL(16, 145, 11), // "handleError"
QT_MOC_LITERAL(17, 157, 28), // "QSerialPort::SerialPortError"
QT_MOC_LITERAL(18, 186, 5), // "error"
QT_MOC_LITERAL(19, 192, 13), // "handleResults"
QT_MOC_LITERAL(20, 206, 6), // "result"
QT_MOC_LITERAL(21, 213, 11), // "set_mcu_cmd"
QT_MOC_LITERAL(22, 225, 2), // "id"
QT_MOC_LITERAL(23, 228, 15), // "set_motor_spedd"
QT_MOC_LITERAL(24, 244, 9), // "applyHome"
QT_MOC_LITERAL(25, 254, 10), // "applyStart"
QT_MOC_LITERAL(26, 265, 10), // "applyPause"
QT_MOC_LITERAL(27, 276, 9), // "applyStop"
QT_MOC_LITERAL(28, 286, 10), // "applySpeed"
QT_MOC_LITERAL(29, 297, 12), // "applyForward"
QT_MOC_LITERAL(30, 310, 13), // "applyBackward"
QT_MOC_LITERAL(31, 324, 11) // "selectMotor"

    },
    "MainWindow\0serialDataSend\0\0data\0"
    "sendToCmd\0cmd\0motorState\0state\0position\0"
    "doHome\0openSerialPort\0closeSerialPort\0"
    "openCurve\0about\0writeData\0readData\0"
    "handleError\0QSerialPort::SerialPortError\0"
    "error\0handleResults\0result\0set_mcu_cmd\0"
    "id\0set_motor_spedd\0applyHome\0applyStart\0"
    "applyPause\0applyStop\0applySpeed\0"
    "applyForward\0applyBackward\0selectMotor"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_MainWindow[] = {

 // content:
       8,       // revision
       0,       // classname
       0,    0, // classinfo
      22,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       4,       // signalCount

 // signals: name, argc, parameters, tag, flags
       1,    1,  124,    2, 0x06 /* Public */,
       4,    1,  127,    2, 0x06 /* Public */,
       6,    2,  130,    2, 0x06 /* Public */,
       9,    0,  135,    2, 0x06 /* Public */,

 // slots: name, argc, parameters, tag, flags
      10,    0,  136,    2, 0x08 /* Private */,
      11,    0,  137,    2, 0x08 /* Private */,
      12,    0,  138,    2, 0x08 /* Private */,
      13,    0,  139,    2, 0x08 /* Private */,
      14,    1,  140,    2, 0x08 /* Private */,
      15,    0,  143,    2, 0x08 /* Private */,
      16,    1,  144,    2, 0x08 /* Private */,
      19,    1,  147,    2, 0x08 /* Private */,
      21,    2,  150,    2, 0x08 /* Private */,
      23,    3,  155,    2, 0x08 /* Private */,
      24,    0,  162,    2, 0x08 /* Private */,
      25,    0,  163,    2, 0x08 /* Private */,
      26,    0,  164,    2, 0x08 /* Private */,
      27,    0,  165,    2, 0x08 /* Private */,
      28,    0,  166,    2, 0x08 /* Private */,
      29,    0,  167,    2, 0x08 /* Private */,
      30,    0,  168,    2, 0x08 /* Private */,
      31,    0,  169,    2, 0x08 /* Private */,

 // signals: parameters
    QMetaType::Void, QMetaType::QByteArray,    3,
    QMetaType::Void, QMetaType::QByteArray,    5,
    QMetaType::Void, QMetaType::Bool, QMetaType::Double,    7,    8,
    QMetaType::Void,

 // slots: parameters
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void, QMetaType::QByteArray,    3,
    QMetaType::Void,
    QMetaType::Void, 0x80000000 | 17,   18,
    QMetaType::Void, QMetaType::QString,   20,
    QMetaType::Void, QMetaType::UChar, QMetaType::UChar,    5,   22,
    QMetaType::Void, QMetaType::UChar, QMetaType::UChar, QMetaType::UInt,    5,   22,    3,
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

void MainWindow::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        auto *_t = static_cast<MainWindow *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->serialDataSend((*reinterpret_cast< const QByteArray(*)>(_a[1]))); break;
        case 1: _t->sendToCmd((*reinterpret_cast< QByteArray(*)>(_a[1]))); break;
        case 2: _t->motorState((*reinterpret_cast< const bool(*)>(_a[1])),(*reinterpret_cast< const double(*)>(_a[2]))); break;
        case 3: _t->doHome(); break;
        case 4: _t->openSerialPort(); break;
        case 5: _t->closeSerialPort(); break;
        case 6: _t->openCurve(); break;
        case 7: _t->about(); break;
        case 8: _t->writeData((*reinterpret_cast< const QByteArray(*)>(_a[1]))); break;
        case 9: _t->readData(); break;
        case 10: _t->handleError((*reinterpret_cast< QSerialPort::SerialPortError(*)>(_a[1]))); break;
        case 11: _t->handleResults((*reinterpret_cast< QString(*)>(_a[1]))); break;
        case 12: _t->set_mcu_cmd((*reinterpret_cast< quint8(*)>(_a[1])),(*reinterpret_cast< quint8(*)>(_a[2]))); break;
        case 13: _t->set_motor_spedd((*reinterpret_cast< quint8(*)>(_a[1])),(*reinterpret_cast< quint8(*)>(_a[2])),(*reinterpret_cast< quint32(*)>(_a[3]))); break;
        case 14: _t->applyHome(); break;
        case 15: _t->applyStart(); break;
        case 16: _t->applyPause(); break;
        case 17: _t->applyStop(); break;
        case 18: _t->applySpeed(); break;
        case 19: _t->applyForward(); break;
        case 20: _t->applyBackward(); break;
        case 21: _t->selectMotor(); break;
        default: ;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        {
            using _t = void (MainWindow::*)(const QByteArray );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&MainWindow::serialDataSend)) {
                *result = 0;
                return;
            }
        }
        {
            using _t = void (MainWindow::*)(QByteArray );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&MainWindow::sendToCmd)) {
                *result = 1;
                return;
            }
        }
        {
            using _t = void (MainWindow::*)(const bool , const double );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&MainWindow::motorState)) {
                *result = 2;
                return;
            }
        }
        {
            using _t = void (MainWindow::*)();
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&MainWindow::doHome)) {
                *result = 3;
                return;
            }
        }
    }
}

QT_INIT_METAOBJECT const QMetaObject MainWindow::staticMetaObject = { {
    QMetaObject::SuperData::link<QMainWindow::staticMetaObject>(),
    qt_meta_stringdata_MainWindow.data,
    qt_meta_data_MainWindow,
    qt_static_metacall,
    nullptr,
    nullptr
} };


const QMetaObject *MainWindow::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *MainWindow::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_MainWindow.stringdata0))
        return static_cast<void*>(this);
    return QMainWindow::qt_metacast(_clname);
}

int MainWindow::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QMainWindow::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 22)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 22;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 22)
            *reinterpret_cast<int*>(_a[0]) = -1;
        _id -= 22;
    }
    return _id;
}

// SIGNAL 0
void MainWindow::serialDataSend(const QByteArray _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t1))) };
    QMetaObject::activate(this, &staticMetaObject, 0, _a);
}

// SIGNAL 1
void MainWindow::sendToCmd(QByteArray _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t1))) };
    QMetaObject::activate(this, &staticMetaObject, 1, _a);
}

// SIGNAL 2
void MainWindow::motorState(const bool _t1, const double _t2)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t1))), const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t2))) };
    QMetaObject::activate(this, &staticMetaObject, 2, _a);
}

// SIGNAL 3
void MainWindow::doHome()
{
    QMetaObject::activate(this, &staticMetaObject, 3, nullptr);
}
QT_WARNING_POP
QT_END_MOC_NAMESPACE
