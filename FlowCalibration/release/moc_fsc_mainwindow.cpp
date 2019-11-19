/****************************************************************************
** Meta object code from reading C++ file 'fsc_mainwindow.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.9.8)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../fsc_mainwindow.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'fsc_mainwindow.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.9.8. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
struct qt_meta_stringdata_FSC_MainWindow_t {
    QByteArrayData data[13];
    char stringdata0[260];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_FSC_MainWindow_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_FSC_MainWindow_t qt_meta_stringdata_FSC_MainWindow = {
    {
QT_MOC_LITERAL(0, 0, 14), // "FSC_MainWindow"
QT_MOC_LITERAL(1, 15, 25), // "on_tbnSysDevCheck_clicked"
QT_MOC_LITERAL(2, 41, 0), // ""
QT_MOC_LITERAL(3, 42, 28), // "on_tbnManualCheckDev_clicked"
QT_MOC_LITERAL(4, 71, 42), // "on_comboBox_PlotSenSel_curren..."
QT_MOC_LITERAL(5, 114, 4), // "arg1"
QT_MOC_LITERAL(6, 119, 46), // "on_comboBox_SensorTypeName_cu..."
QT_MOC_LITERAL(7, 166, 5), // "index"
QT_MOC_LITERAL(8, 172, 20), // "sktScale_connect_suc"
QT_MOC_LITERAL(9, 193, 1), // "i"
QT_MOC_LITERAL(10, 195, 20), // "sktScale_connect_dis"
QT_MOC_LITERAL(11, 216, 14), // "sktScale_error"
QT_MOC_LITERAL(12, 231, 28) // "QAbstractSocket::SocketError"

    },
    "FSC_MainWindow\0on_tbnSysDevCheck_clicked\0"
    "\0on_tbnManualCheckDev_clicked\0"
    "on_comboBox_PlotSenSel_currentIndexChanged\0"
    "arg1\0on_comboBox_SensorTypeName_currentIndexChanged\0"
    "index\0sktScale_connect_suc\0i\0"
    "sktScale_connect_dis\0sktScale_error\0"
    "QAbstractSocket::SocketError"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_FSC_MainWindow[] = {

 // content:
       7,       // revision
       0,       // classname
       0,    0, // classinfo
       7,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // slots: name, argc, parameters, tag, flags
       1,    0,   49,    2, 0x08 /* Private */,
       3,    0,   50,    2, 0x08 /* Private */,
       4,    1,   51,    2, 0x08 /* Private */,
       6,    1,   54,    2, 0x08 /* Private */,
       8,    1,   57,    2, 0x08 /* Private */,
      10,    1,   60,    2, 0x08 /* Private */,
      11,    2,   63,    2, 0x08 /* Private */,

 // slots: parameters
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void, QMetaType::QString,    5,
    QMetaType::Void, QMetaType::Int,    7,
    QMetaType::Void, QMetaType::Int,    9,
    QMetaType::Void, QMetaType::Int,    9,
    QMetaType::Void, 0x80000000 | 12, QMetaType::Int,    2,    9,

       0        // eod
};

void FSC_MainWindow::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        FSC_MainWindow *_t = static_cast<FSC_MainWindow *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->on_tbnSysDevCheck_clicked(); break;
        case 1: _t->on_tbnManualCheckDev_clicked(); break;
        case 2: _t->on_comboBox_PlotSenSel_currentIndexChanged((*reinterpret_cast< const QString(*)>(_a[1]))); break;
        case 3: _t->on_comboBox_SensorTypeName_currentIndexChanged((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 4: _t->sktScale_connect_suc((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 5: _t->sktScale_connect_dis((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 6: _t->sktScale_error((*reinterpret_cast< QAbstractSocket::SocketError(*)>(_a[1])),(*reinterpret_cast< int(*)>(_a[2]))); break;
        default: ;
        }
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        switch (_id) {
        default: *reinterpret_cast<int*>(_a[0]) = -1; break;
        case 6:
            switch (*reinterpret_cast<int*>(_a[1])) {
            default: *reinterpret_cast<int*>(_a[0]) = -1; break;
            case 0:
                *reinterpret_cast<int*>(_a[0]) = qRegisterMetaType< QAbstractSocket::SocketError >(); break;
            }
            break;
        }
    }
}

const QMetaObject FSC_MainWindow::staticMetaObject = {
    { &QMainWindow::staticMetaObject, qt_meta_stringdata_FSC_MainWindow.data,
      qt_meta_data_FSC_MainWindow,  qt_static_metacall, nullptr, nullptr}
};


const QMetaObject *FSC_MainWindow::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *FSC_MainWindow::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_FSC_MainWindow.stringdata0))
        return static_cast<void*>(this);
    return QMainWindow::qt_metacast(_clname);
}

int FSC_MainWindow::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QMainWindow::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 7)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 7;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 7)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 7;
    }
    return _id;
}
QT_WARNING_POP
QT_END_MOC_NAMESPACE
