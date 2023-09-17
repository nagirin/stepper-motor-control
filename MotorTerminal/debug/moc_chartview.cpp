/****************************************************************************
** Meta object code from reading C++ file 'chartview.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.15.2)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include <memory>
#include "../chartview.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'chartview.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.15.2. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
struct qt_meta_stringdata_ChartView_t {
    QByteArrayData data[11];
    char stringdata0[113];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_ChartView_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_ChartView_t qt_meta_stringdata_ChartView = {
    {
QT_MOC_LITERAL(0, 0, 9), // "ChartView"
QT_MOC_LITERAL(1, 10, 14), // "connectMarkers"
QT_MOC_LITERAL(2, 25, 0), // ""
QT_MOC_LITERAL(3, 26, 19), // "handleMarkerClicked"
QT_MOC_LITERAL(4, 46, 7), // "tooltip"
QT_MOC_LITERAL(5, 54, 5), // "point"
QT_MOC_LITERAL(6, 60, 5), // "state"
QT_MOC_LITERAL(7, 66, 13), // "handleTimeout"
QT_MOC_LITERAL(8, 80, 10), // "applyClear"
QT_MOC_LITERAL(9, 91, 9), // "applySave"
QT_MOC_LITERAL(10, 101, 11) // "applyExport"

    },
    "ChartView\0connectMarkers\0\0handleMarkerClicked\0"
    "tooltip\0point\0state\0handleTimeout\0"
    "applyClear\0applySave\0applyExport"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_ChartView[] = {

 // content:
       8,       // revision
       0,       // classname
       0,    0, // classinfo
       7,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // slots: name, argc, parameters, tag, flags
       1,    0,   49,    2, 0x0a /* Public */,
       3,    0,   50,    2, 0x0a /* Public */,
       4,    2,   51,    2, 0x0a /* Public */,
       7,    0,   56,    2, 0x08 /* Private */,
       8,    0,   57,    2, 0x08 /* Private */,
       9,    0,   58,    2, 0x08 /* Private */,
      10,    0,   59,    2, 0x08 /* Private */,

 // slots: parameters
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void, QMetaType::QPointF, QMetaType::Bool,    5,    6,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,

       0        // eod
};

void ChartView::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        auto *_t = static_cast<ChartView *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->connectMarkers(); break;
        case 1: _t->handleMarkerClicked(); break;
        case 2: _t->tooltip((*reinterpret_cast< QPointF(*)>(_a[1])),(*reinterpret_cast< bool(*)>(_a[2]))); break;
        case 3: _t->handleTimeout(); break;
        case 4: _t->applyClear(); break;
        case 5: _t->applySave(); break;
        case 6: _t->applyExport(); break;
        default: ;
        }
    }
}

QT_INIT_METAOBJECT const QMetaObject ChartView::staticMetaObject = { {
    QMetaObject::SuperData::link<QChartView::staticMetaObject>(),
    qt_meta_stringdata_ChartView.data,
    qt_meta_data_ChartView,
    qt_static_metacall,
    nullptr,
    nullptr
} };


const QMetaObject *ChartView::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *ChartView::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_ChartView.stringdata0))
        return static_cast<void*>(this);
    return QChartView::qt_metacast(_clname);
}

int ChartView::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QChartView::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 7)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 7;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 7)
            *reinterpret_cast<int*>(_a[0]) = -1;
        _id -= 7;
    }
    return _id;
}
QT_WARNING_POP
QT_END_MOC_NAMESPACE
