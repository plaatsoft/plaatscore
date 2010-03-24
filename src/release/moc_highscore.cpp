/****************************************************************************
** Meta object code from reading C++ file 'highscore.h'
**
** Created: Wed 24. Mar 07:11:57 2010
**      by: The Qt Meta Object Compiler version 62 (Qt 4.6.2)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../highscore.h"
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'highscore.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 62
#error "This file was generated using the moc from 4.6.2. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
static const uint qt_meta_data_HighScore[] = {

 // content:
       4,       // revision
       0,       // classname
       0,    0, // classinfo
       9,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // slots: signature, parameters, type, tag, flags
      11,   10,   10,   10, 0x08,
      38,   10,   10,   10, 0x08,
      72,   10,   10,   10, 0x08,
     105,   10,   10,   10, 0x08,
     136,   10,   10,   10, 0x08,
     167,   10,   10,   10, 0x08,
     194,   10,   10,   10, 0x08,
     220,   10,   10,   10, 0x08,
     228,   10,   10,   10, 0x08,

       0        // eod
};

static const char qt_meta_stringdata_HighScore[] = {
    "HighScore\0\0on_actionAbout_triggered()\0"
    "on_actionTowerDefense_triggered()\0"
    "on_actionSpaceBubble_triggered()\0"
    "on_actionRedSquare_triggered()\0"
    "on_actionBibleQuiz_triggered()\0"
    "on_actionPong2_triggered()\0"
    "on_actionExit_triggered()\0fetch()\0"
    "replyFinished(QNetworkReply*)\0"
};

const QMetaObject HighScore::staticMetaObject = {
    { &QMainWindow::staticMetaObject, qt_meta_stringdata_HighScore,
      qt_meta_data_HighScore, 0 }
};

#ifdef Q_NO_DATA_RELOCATION
const QMetaObject &HighScore::getStaticMetaObject() { return staticMetaObject; }
#endif //Q_NO_DATA_RELOCATION

const QMetaObject *HighScore::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->metaObject : &staticMetaObject;
}

void *HighScore::qt_metacast(const char *_clname)
{
    if (!_clname) return 0;
    if (!strcmp(_clname, qt_meta_stringdata_HighScore))
        return static_cast<void*>(const_cast< HighScore*>(this));
    return QMainWindow::qt_metacast(_clname);
}

int HighScore::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QMainWindow::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        switch (_id) {
        case 0: on_actionAbout_triggered(); break;
        case 1: on_actionTowerDefense_triggered(); break;
        case 2: on_actionSpaceBubble_triggered(); break;
        case 3: on_actionRedSquare_triggered(); break;
        case 4: on_actionBibleQuiz_triggered(); break;
        case 5: on_actionPong2_triggered(); break;
        case 6: on_actionExit_triggered(); break;
        case 7: fetch(); break;
        case 8: replyFinished((*reinterpret_cast< QNetworkReply*(*)>(_a[1]))); break;
        default: ;
        }
        _id -= 9;
    }
    return _id;
}
QT_END_MOC_NAMESPACE
