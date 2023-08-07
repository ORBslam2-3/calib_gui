/****************************************************************************
** Meta object code from reading C++ file 'qnode.hpp'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.12.8)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../../../../src/ros_qt_demo/include/ros_qt_demo/qnode.hpp"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'qnode.hpp' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.12.8. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
struct qt_meta_stringdata_class1_ros_qt_demo__QNode_t {
    QByteArrayData data[15];
    char stringdata0[182];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_class1_ros_qt_demo__QNode_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_class1_ros_qt_demo__QNode_t qt_meta_stringdata_class1_ros_qt_demo__QNode = {
    {
QT_MOC_LITERAL(0, 0, 25), // "class1_ros_qt_demo::QNode"
QT_MOC_LITERAL(1, 26, 14), // "loggingUpdated"
QT_MOC_LITERAL(2, 41, 0), // ""
QT_MOC_LITERAL(3, 42, 11), // "rosShutdown"
QT_MOC_LITERAL(4, 54, 23), // "translationDataReceived"
QT_MOC_LITERAL(5, 78, 1), // "x"
QT_MOC_LITERAL(6, 80, 1), // "y"
QT_MOC_LITERAL(7, 82, 1), // "z"
QT_MOC_LITERAL(8, 84, 17), // "eulerDataReceived"
QT_MOC_LITERAL(9, 102, 6), // "eulerX"
QT_MOC_LITERAL(10, 109, 6), // "eulerY"
QT_MOC_LITERAL(11, 116, 6), // "eulerZ"
QT_MOC_LITERAL(12, 123, 25), // "calibrationFinishedSignal"
QT_MOC_LITERAL(13, 149, 19), // "fitnessScoreUpdated"
QT_MOC_LITERAL(14, 169, 12) // "fitnessScore"

    },
    "class1_ros_qt_demo::QNode\0loggingUpdated\0"
    "\0rosShutdown\0translationDataReceived\0"
    "x\0y\0z\0eulerDataReceived\0eulerX\0eulerY\0"
    "eulerZ\0calibrationFinishedSignal\0"
    "fitnessScoreUpdated\0fitnessScore"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_class1_ros_qt_demo__QNode[] = {

 // content:
       8,       // revision
       0,       // classname
       0,    0, // classinfo
       6,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       6,       // signalCount

 // signals: name, argc, parameters, tag, flags
       1,    0,   44,    2, 0x06 /* Public */,
       3,    0,   45,    2, 0x06 /* Public */,
       4,    3,   46,    2, 0x06 /* Public */,
       8,    3,   53,    2, 0x06 /* Public */,
      12,    0,   60,    2, 0x06 /* Public */,
      13,    1,   61,    2, 0x06 /* Public */,

 // signals: parameters
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void, QMetaType::Double, QMetaType::Double, QMetaType::Double,    5,    6,    7,
    QMetaType::Void, QMetaType::Double, QMetaType::Double, QMetaType::Double,    9,   10,   11,
    QMetaType::Void,
    QMetaType::Void, QMetaType::Double,   14,

       0        // eod
};

void class1_ros_qt_demo::QNode::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        auto *_t = static_cast<QNode *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->loggingUpdated(); break;
        case 1: _t->rosShutdown(); break;
        case 2: _t->translationDataReceived((*reinterpret_cast< double(*)>(_a[1])),(*reinterpret_cast< double(*)>(_a[2])),(*reinterpret_cast< double(*)>(_a[3]))); break;
        case 3: _t->eulerDataReceived((*reinterpret_cast< double(*)>(_a[1])),(*reinterpret_cast< double(*)>(_a[2])),(*reinterpret_cast< double(*)>(_a[3]))); break;
        case 4: _t->calibrationFinishedSignal(); break;
        case 5: _t->fitnessScoreUpdated((*reinterpret_cast< double(*)>(_a[1]))); break;
        default: ;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        {
            using _t = void (QNode::*)();
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&QNode::loggingUpdated)) {
                *result = 0;
                return;
            }
        }
        {
            using _t = void (QNode::*)();
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&QNode::rosShutdown)) {
                *result = 1;
                return;
            }
        }
        {
            using _t = void (QNode::*)(double , double , double );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&QNode::translationDataReceived)) {
                *result = 2;
                return;
            }
        }
        {
            using _t = void (QNode::*)(double , double , double );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&QNode::eulerDataReceived)) {
                *result = 3;
                return;
            }
        }
        {
            using _t = void (QNode::*)();
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&QNode::calibrationFinishedSignal)) {
                *result = 4;
                return;
            }
        }
        {
            using _t = void (QNode::*)(double );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&QNode::fitnessScoreUpdated)) {
                *result = 5;
                return;
            }
        }
    }
}

QT_INIT_METAOBJECT const QMetaObject class1_ros_qt_demo::QNode::staticMetaObject = { {
    &QThread::staticMetaObject,
    qt_meta_stringdata_class1_ros_qt_demo__QNode.data,
    qt_meta_data_class1_ros_qt_demo__QNode,
    qt_static_metacall,
    nullptr,
    nullptr
} };


const QMetaObject *class1_ros_qt_demo::QNode::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *class1_ros_qt_demo::QNode::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_class1_ros_qt_demo__QNode.stringdata0))
        return static_cast<void*>(this);
    return QThread::qt_metacast(_clname);
}

int class1_ros_qt_demo::QNode::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QThread::qt_metacall(_c, _id, _a);
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
void class1_ros_qt_demo::QNode::loggingUpdated()
{
    QMetaObject::activate(this, &staticMetaObject, 0, nullptr);
}

// SIGNAL 1
void class1_ros_qt_demo::QNode::rosShutdown()
{
    QMetaObject::activate(this, &staticMetaObject, 1, nullptr);
}

// SIGNAL 2
void class1_ros_qt_demo::QNode::translationDataReceived(double _t1, double _t2, double _t3)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(&_t1)), const_cast<void*>(reinterpret_cast<const void*>(&_t2)), const_cast<void*>(reinterpret_cast<const void*>(&_t3)) };
    QMetaObject::activate(this, &staticMetaObject, 2, _a);
}

// SIGNAL 3
void class1_ros_qt_demo::QNode::eulerDataReceived(double _t1, double _t2, double _t3)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(&_t1)), const_cast<void*>(reinterpret_cast<const void*>(&_t2)), const_cast<void*>(reinterpret_cast<const void*>(&_t3)) };
    QMetaObject::activate(this, &staticMetaObject, 3, _a);
}

// SIGNAL 4
void class1_ros_qt_demo::QNode::calibrationFinishedSignal()
{
    QMetaObject::activate(this, &staticMetaObject, 4, nullptr);
}

// SIGNAL 5
void class1_ros_qt_demo::QNode::fitnessScoreUpdated(double _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 5, _a);
}
QT_WARNING_POP
QT_END_MOC_NAMESPACE
