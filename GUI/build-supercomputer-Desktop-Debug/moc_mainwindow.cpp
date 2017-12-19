/****************************************************************************
** Meta object code from reading C++ file 'mainwindow.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.5.1)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../supercomputer/mainwindow.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'mainwindow.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.5.1. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
struct qt_meta_stringdata_MainWindow_t {
    QByteArrayData data[18];
    char stringdata0[341];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_MainWindow_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_MainWindow_t qt_meta_stringdata_MainWindow = {
    {
QT_MOC_LITERAL(0, 0, 10), // "MainWindow"
QT_MOC_LITERAL(1, 11, 18), // "set_initial_values"
QT_MOC_LITERAL(2, 30, 0), // ""
QT_MOC_LITERAL(3, 31, 17), // "show_random_users"
QT_MOC_LITERAL(4, 49, 4), // "show"
QT_MOC_LITERAL(5, 54, 16), // "show_random_jobs"
QT_MOC_LITERAL(6, 71, 26), // "show_random_student_budget"
QT_MOC_LITERAL(7, 98, 29), // "show_random_researcher_budget"
QT_MOC_LITERAL(8, 128, 21), // "on_randomUser_clicked"
QT_MOC_LITERAL(9, 150, 7), // "checked"
QT_MOC_LITERAL(10, 158, 22), // "on_randomUsers_clicked"
QT_MOC_LITERAL(11, 181, 29), // "on_constantUsers_valueChanged"
QT_MOC_LITERAL(12, 211, 4), // "arg1"
QT_MOC_LITERAL(13, 216, 22), // "on_randomUsers_toggled"
QT_MOC_LITERAL(14, 239, 21), // "on_randomJobs_toggled"
QT_MOC_LITERAL(15, 261, 26), // "on_simulateButton_released"
QT_MOC_LITERAL(16, 288, 24), // "on_randomStudent_toggled"
QT_MOC_LITERAL(17, 313, 27) // "on_randomResearcher_toggled"

    },
    "MainWindow\0set_initial_values\0\0"
    "show_random_users\0show\0show_random_jobs\0"
    "show_random_student_budget\0"
    "show_random_researcher_budget\0"
    "on_randomUser_clicked\0checked\0"
    "on_randomUsers_clicked\0"
    "on_constantUsers_valueChanged\0arg1\0"
    "on_randomUsers_toggled\0on_randomJobs_toggled\0"
    "on_simulateButton_released\0"
    "on_randomStudent_toggled\0"
    "on_randomResearcher_toggled"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_MainWindow[] = {

 // content:
       7,       // revision
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
       3,    1,   80,    2, 0x08 /* Private */,
       5,    1,   83,    2, 0x08 /* Private */,
       6,    1,   86,    2, 0x08 /* Private */,
       7,    1,   89,    2, 0x08 /* Private */,
       8,    1,   92,    2, 0x08 /* Private */,
      10,    1,   95,    2, 0x08 /* Private */,
      11,    1,   98,    2, 0x08 /* Private */,
      13,    1,  101,    2, 0x08 /* Private */,
      14,    1,  104,    2, 0x08 /* Private */,
      15,    0,  107,    2, 0x08 /* Private */,
      16,    1,  108,    2, 0x08 /* Private */,
      17,    1,  111,    2, 0x08 /* Private */,

 // slots: parameters
    QMetaType::Void,
    QMetaType::Void, QMetaType::Bool,    4,
    QMetaType::Void, QMetaType::Bool,    4,
    QMetaType::Void, QMetaType::Bool,    4,
    QMetaType::Void, QMetaType::Bool,    4,
    QMetaType::Void, QMetaType::Bool,    9,
    QMetaType::Void, QMetaType::Bool,    9,
    QMetaType::Void, QMetaType::Int,   12,
    QMetaType::Void, QMetaType::Bool,    9,
    QMetaType::Void, QMetaType::Bool,    9,
    QMetaType::Void,
    QMetaType::Void, QMetaType::Bool,    9,
    QMetaType::Void, QMetaType::Bool,    9,

       0        // eod
};

void MainWindow::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        MainWindow *_t = static_cast<MainWindow *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->set_initial_values(); break;
        case 1: _t->show_random_users((*reinterpret_cast< bool(*)>(_a[1]))); break;
        case 2: _t->show_random_jobs((*reinterpret_cast< bool(*)>(_a[1]))); break;
        case 3: _t->show_random_student_budget((*reinterpret_cast< bool(*)>(_a[1]))); break;
        case 4: _t->show_random_researcher_budget((*reinterpret_cast< bool(*)>(_a[1]))); break;
        case 7: _t->on_constantUsers_valueChanged((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 8: _t->on_randomUsers_toggled((*reinterpret_cast< bool(*)>(_a[1]))); break;
        case 9: _t->on_randomJobs_toggled((*reinterpret_cast< bool(*)>(_a[1]))); break;
        case 10: _t->on_simulateButton_released(); break;
        case 11: _t->on_randomStudent_toggled((*reinterpret_cast< bool(*)>(_a[1]))); break;
        case 12: _t->on_randomResearcher_toggled((*reinterpret_cast< bool(*)>(_a[1]))); break;
        default: ;
        }
    }
}

const QMetaObject MainWindow::staticMetaObject = {
    { &QMainWindow::staticMetaObject, qt_meta_stringdata_MainWindow.data,
      qt_meta_data_MainWindow,  qt_static_metacall, Q_NULLPTR, Q_NULLPTR}
};


const QMetaObject *MainWindow::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *MainWindow::qt_metacast(const char *_clname)
{
    if (!_clname) return Q_NULLPTR;
    if (!strcmp(_clname, qt_meta_stringdata_MainWindow.stringdata0))
        return static_cast<void*>(const_cast< MainWindow*>(this));
    return QMainWindow::qt_metacast(_clname);
}

int MainWindow::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QMainWindow::qt_metacall(_c, _id, _a);
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
QT_END_MOC_NAMESPACE
