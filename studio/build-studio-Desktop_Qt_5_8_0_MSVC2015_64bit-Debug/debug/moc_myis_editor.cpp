/****************************************************************************
** Meta object code from reading C++ file 'myis_editor.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.8.0)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../../studio/myis_editor.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'myis_editor.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.8.0. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
struct qt_meta_stringdata_myis_editor_t {
    QByteArrayData data[11];
    char stringdata0[259];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_myis_editor_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_myis_editor_t qt_meta_stringdata_myis_editor = {
    {
QT_MOC_LITERAL(0, 0, 11), // "myis_editor"
QT_MOC_LITERAL(1, 12, 23), // "on_textEdit_textChanged"
QT_MOC_LITERAL(2, 36, 0), // ""
QT_MOC_LITERAL(3, 37, 33), // "on_textEdit_cursorPositionCha..."
QT_MOC_LITERAL(4, 71, 37), // "on_actionSyntax_Tree_Viewer_t..."
QT_MOC_LITERAL(5, 109, 23), // "on_actionSave_triggered"
QT_MOC_LITERAL(6, 133, 23), // "on_actionOpen_triggered"
QT_MOC_LITERAL(7, 157, 28), // "on_actionRecursive_triggered"
QT_MOC_LITERAL(8, 186, 22), // "on_actionLL1_triggered"
QT_MOC_LITERAL(9, 209, 22), // "on_actionLR1_triggered"
QT_MOC_LITERAL(10, 232, 26) // "on_actionCompile_triggered"

    },
    "myis_editor\0on_textEdit_textChanged\0"
    "\0on_textEdit_cursorPositionChanged\0"
    "on_actionSyntax_Tree_Viewer_triggered\0"
    "on_actionSave_triggered\0on_actionOpen_triggered\0"
    "on_actionRecursive_triggered\0"
    "on_actionLL1_triggered\0on_actionLR1_triggered\0"
    "on_actionCompile_triggered"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_myis_editor[] = {

 // content:
       7,       // revision
       0,       // classname
       0,    0, // classinfo
       9,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // slots: name, argc, parameters, tag, flags
       1,    0,   59,    2, 0x08 /* Private */,
       3,    0,   60,    2, 0x08 /* Private */,
       4,    0,   61,    2, 0x08 /* Private */,
       5,    0,   62,    2, 0x08 /* Private */,
       6,    0,   63,    2, 0x08 /* Private */,
       7,    0,   64,    2, 0x08 /* Private */,
       8,    0,   65,    2, 0x08 /* Private */,
       9,    0,   66,    2, 0x08 /* Private */,
      10,    0,   67,    2, 0x08 /* Private */,

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

       0        // eod
};

void myis_editor::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        myis_editor *_t = static_cast<myis_editor *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->on_textEdit_textChanged(); break;
        case 1: _t->on_textEdit_cursorPositionChanged(); break;
        case 2: _t->on_actionSyntax_Tree_Viewer_triggered(); break;
        case 3: _t->on_actionSave_triggered(); break;
        case 4: _t->on_actionOpen_triggered(); break;
        case 5: _t->on_actionRecursive_triggered(); break;
        case 6: _t->on_actionLL1_triggered(); break;
        case 7: _t->on_actionLR1_triggered(); break;
        case 8: _t->on_actionCompile_triggered(); break;
        default: ;
        }
    }
    Q_UNUSED(_a);
}

const QMetaObject myis_editor::staticMetaObject = {
    { &QMainWindow::staticMetaObject, qt_meta_stringdata_myis_editor.data,
      qt_meta_data_myis_editor,  qt_static_metacall, Q_NULLPTR, Q_NULLPTR}
};


const QMetaObject *myis_editor::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *myis_editor::qt_metacast(const char *_clname)
{
    if (!_clname) return Q_NULLPTR;
    if (!strcmp(_clname, qt_meta_stringdata_myis_editor.stringdata0))
        return static_cast<void*>(const_cast< myis_editor*>(this));
    return QMainWindow::qt_metacast(_clname);
}

int myis_editor::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QMainWindow::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 9)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 9;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 9)
            *reinterpret_cast<int*>(_a[0]) = -1;
        _id -= 9;
    }
    return _id;
}
QT_WARNING_POP
QT_END_MOC_NAMESPACE
