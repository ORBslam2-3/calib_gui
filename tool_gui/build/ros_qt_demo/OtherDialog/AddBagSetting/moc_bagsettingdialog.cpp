/****************************************************************************
** Meta object code from reading C++ file 'bagsettingdialog.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.12.8)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../../../../src/ros_qt_demo/OtherDialog/AddBagSetting/bagsettingdialog.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'bagsettingdialog.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.12.8. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
struct qt_meta_stringdata_bagSettingDialog_t {
    QByteArrayData data[11];
    char stringdata0[233];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_bagSettingDialog_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_bagSettingDialog_t qt_meta_stringdata_bagSettingDialog = {
    {
QT_MOC_LITERAL(0, 0, 16), // "bagSettingDialog"
QT_MOC_LITERAL(1, 17, 26), // "on_button_openFile_clicked"
QT_MOC_LITERAL(2, 44, 0), // ""
QT_MOC_LITERAL(3, 45, 32), // "on_comboBox1_currentIndexChanged"
QT_MOC_LITERAL(4, 78, 13), // "selectedTopic"
QT_MOC_LITERAL(5, 92, 32), // "on_comboBox2_currentIndexChanged"
QT_MOC_LITERAL(6, 125, 25), // "handleCustomTopicMapping1"
QT_MOC_LITERAL(7, 151, 11), // "customTopic"
QT_MOC_LITERAL(8, 163, 25), // "handleCustomTopicMapping2"
QT_MOC_LITERAL(9, 189, 17), // "updatePlayCommand"
QT_MOC_LITERAL(10, 207, 25) // "on_button_playBag_clicked"

    },
    "bagSettingDialog\0on_button_openFile_clicked\0"
    "\0on_comboBox1_currentIndexChanged\0"
    "selectedTopic\0on_comboBox2_currentIndexChanged\0"
    "handleCustomTopicMapping1\0customTopic\0"
    "handleCustomTopicMapping2\0updatePlayCommand\0"
    "on_button_playBag_clicked"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_bagSettingDialog[] = {

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
       3,    1,   50,    2, 0x0a /* Public */,
       5,    1,   53,    2, 0x0a /* Public */,
       6,    2,   56,    2, 0x0a /* Public */,
       8,    2,   61,    2, 0x0a /* Public */,
       9,    0,   66,    2, 0x0a /* Public */,
      10,    0,   67,    2, 0x0a /* Public */,

 // slots: parameters
    QMetaType::Void,
    QMetaType::Void, QMetaType::QString,    4,
    QMetaType::Void, QMetaType::QString,    4,
    QMetaType::Void, QMetaType::QString, QMetaType::QString,    4,    7,
    QMetaType::Void, QMetaType::QString, QMetaType::QString,    4,    7,
    QMetaType::Void,
    QMetaType::Void,

       0        // eod
};

void bagSettingDialog::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        auto *_t = static_cast<bagSettingDialog *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->on_button_openFile_clicked(); break;
        case 1: _t->on_comboBox1_currentIndexChanged((*reinterpret_cast< const QString(*)>(_a[1]))); break;
        case 2: _t->on_comboBox2_currentIndexChanged((*reinterpret_cast< const QString(*)>(_a[1]))); break;
        case 3: _t->handleCustomTopicMapping1((*reinterpret_cast< const QString(*)>(_a[1])),(*reinterpret_cast< const QString(*)>(_a[2]))); break;
        case 4: _t->handleCustomTopicMapping2((*reinterpret_cast< const QString(*)>(_a[1])),(*reinterpret_cast< const QString(*)>(_a[2]))); break;
        case 5: _t->updatePlayCommand(); break;
        case 6: _t->on_button_playBag_clicked(); break;
        default: ;
        }
    }
}

QT_INIT_METAOBJECT const QMetaObject bagSettingDialog::staticMetaObject = { {
    &QDialog::staticMetaObject,
    qt_meta_stringdata_bagSettingDialog.data,
    qt_meta_data_bagSettingDialog,
    qt_static_metacall,
    nullptr,
    nullptr
} };


const QMetaObject *bagSettingDialog::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *bagSettingDialog::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_bagSettingDialog.stringdata0))
        return static_cast<void*>(this);
    return QDialog::qt_metacast(_clname);
}

int bagSettingDialog::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QDialog::qt_metacall(_c, _id, _a);
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
