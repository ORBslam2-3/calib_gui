/****************************************************************************
** Meta object code from reading C++ file 'main_window.hpp'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.12.8)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../../../../src/ros_qt_demo/include/ros_qt_demo/main_window.hpp"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'main_window.hpp' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.12.8. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
struct qt_meta_stringdata_class1_ros_qt_demo__MainWindow_t {
    QByteArrayData data[23];
    char stringdata0[447];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_class1_ros_qt_demo__MainWindow_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_class1_ros_qt_demo__MainWindow_t qt_meta_stringdata_class1_ros_qt_demo__MainWindow = {
    {
QT_MOC_LITERAL(0, 0, 30), // "class1_ros_qt_demo::MainWindow"
QT_MOC_LITERAL(1, 31, 24), // "on_actionAbout_triggered"
QT_MOC_LITERAL(2, 56, 0), // ""
QT_MOC_LITERAL(3, 57, 27), // "on_action_Connect_triggered"
QT_MOC_LITERAL(4, 85, 27), // "on_action_Roscore_triggered"
QT_MOC_LITERAL(5, 113, 31), // "on_action_InitSetting_triggered"
QT_MOC_LITERAL(6, 145, 24), // "on_action_view_triggered"
QT_MOC_LITERAL(7, 170, 30), // "on_action_BagSetting_triggered"
QT_MOC_LITERAL(8, 201, 23), // "slot_set_global_options"
QT_MOC_LITERAL(9, 225, 33), // "slot_onStyleComboBox_text_cha..."
QT_MOC_LITERAL(10, 259, 38), // "slot_onPointSizeLineEdit_edit..."
QT_MOC_LITERAL(11, 298, 23), // "translationDataReceived"
QT_MOC_LITERAL(12, 322, 1), // "x"
QT_MOC_LITERAL(13, 324, 1), // "y"
QT_MOC_LITERAL(14, 326, 1), // "z"
QT_MOC_LITERAL(15, 328, 17), // "eulerDataReceived"
QT_MOC_LITERAL(16, 346, 6), // "eulerx"
QT_MOC_LITERAL(17, 353, 6), // "eulery"
QT_MOC_LITERAL(18, 360, 6), // "eulerz"
QT_MOC_LITERAL(19, 367, 25), // "onCalibrationFinishedSlot"
QT_MOC_LITERAL(20, 393, 22), // "updateFitnessScorePlot"
QT_MOC_LITERAL(21, 416, 12), // "fitnessScore"
QT_MOC_LITERAL(22, 429, 17) // "updateLoggingView"

    },
    "class1_ros_qt_demo::MainWindow\0"
    "on_actionAbout_triggered\0\0"
    "on_action_Connect_triggered\0"
    "on_action_Roscore_triggered\0"
    "on_action_InitSetting_triggered\0"
    "on_action_view_triggered\0"
    "on_action_BagSetting_triggered\0"
    "slot_set_global_options\0"
    "slot_onStyleComboBox_text_changed\0"
    "slot_onPointSizeLineEdit_edit_finished\0"
    "translationDataReceived\0x\0y\0z\0"
    "eulerDataReceived\0eulerx\0eulery\0eulerz\0"
    "onCalibrationFinishedSlot\0"
    "updateFitnessScorePlot\0fitnessScore\0"
    "updateLoggingView"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_class1_ros_qt_demo__MainWindow[] = {

 // content:
       8,       // revision
       0,       // classname
       0,    0, // classinfo
      14,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // slots: name, argc, parameters, tag, flags
       1,    0,   84,    2, 0x0a /* Public */,
       3,    0,   85,    2, 0x0a /* Public */,
       4,    0,   86,    2, 0x0a /* Public */,
       5,    0,   87,    2, 0x0a /* Public */,
       6,    0,   88,    2, 0x0a /* Public */,
       7,    0,   89,    2, 0x0a /* Public */,
       8,    0,   90,    2, 0x0a /* Public */,
       9,    0,   91,    2, 0x0a /* Public */,
      10,    0,   92,    2, 0x0a /* Public */,
      11,    3,   93,    2, 0x0a /* Public */,
      15,    3,  100,    2, 0x0a /* Public */,
      19,    0,  107,    2, 0x0a /* Public */,
      20,    1,  108,    2, 0x0a /* Public */,
      22,    0,  111,    2, 0x0a /* Public */,

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
    QMetaType::Void, QMetaType::Double, QMetaType::Double, QMetaType::Double,   12,   13,   14,
    QMetaType::Void, QMetaType::Double, QMetaType::Double, QMetaType::Double,   16,   17,   18,
    QMetaType::Void,
    QMetaType::Void, QMetaType::Double,   21,
    QMetaType::Void,

       0        // eod
};

void class1_ros_qt_demo::MainWindow::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        auto *_t = static_cast<MainWindow *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->on_actionAbout_triggered(); break;
        case 1: _t->on_action_Connect_triggered(); break;
        case 2: _t->on_action_Roscore_triggered(); break;
        case 3: _t->on_action_InitSetting_triggered(); break;
        case 4: _t->on_action_view_triggered(); break;
        case 5: _t->on_action_BagSetting_triggered(); break;
        case 6: _t->slot_set_global_options(); break;
        case 7: _t->slot_onStyleComboBox_text_changed(); break;
        case 8: _t->slot_onPointSizeLineEdit_edit_finished(); break;
        case 9: _t->translationDataReceived((*reinterpret_cast< double(*)>(_a[1])),(*reinterpret_cast< double(*)>(_a[2])),(*reinterpret_cast< double(*)>(_a[3]))); break;
        case 10: _t->eulerDataReceived((*reinterpret_cast< double(*)>(_a[1])),(*reinterpret_cast< double(*)>(_a[2])),(*reinterpret_cast< double(*)>(_a[3]))); break;
        case 11: _t->onCalibrationFinishedSlot(); break;
        case 12: _t->updateFitnessScorePlot((*reinterpret_cast< double(*)>(_a[1]))); break;
        case 13: _t->updateLoggingView(); break;
        default: ;
        }
    }
}

QT_INIT_METAOBJECT const QMetaObject class1_ros_qt_demo::MainWindow::staticMetaObject = { {
    &QMainWindow::staticMetaObject,
    qt_meta_stringdata_class1_ros_qt_demo__MainWindow.data,
    qt_meta_data_class1_ros_qt_demo__MainWindow,
    qt_static_metacall,
    nullptr,
    nullptr
} };


const QMetaObject *class1_ros_qt_demo::MainWindow::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *class1_ros_qt_demo::MainWindow::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_class1_ros_qt_demo__MainWindow.stringdata0))
        return static_cast<void*>(this);
    return QMainWindow::qt_metacast(_clname);
}

int class1_ros_qt_demo::MainWindow::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QMainWindow::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 14)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 14;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 14)
            *reinterpret_cast<int*>(_a[0]) = -1;
        _id -= 14;
    }
    return _id;
}
QT_WARNING_POP
QT_END_MOC_NAMESPACE
