/****************************************************************************
** Meta object code from reading C++ file 'gamemanager.h'
**
** Created by: The Qt Meta Object Compiler version 63 (Qt 4.8.7)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../MazeTester/gamemanager.h"
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'gamemanager.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 63
#error "This file was generated using the moc from 4.8.7. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
static const uint qt_meta_data_GameManager[] = {

 // content:
       6,       // revision
       0,       // classname
       0,    0, // classinfo
       8,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       4,       // signalCount

 // signals: signature, parameters, type, tag, flags
      21,   13,   12,   12, 0x05,
      35,   12,   12,   12, 0x05,
      44,   12,   12,   12, 0x05,
      57,   12,   12,   12, 0x05,

 // slots: signature, parameters, type, tag, flags
      70,   65,   12,   12, 0x0a,
      83,   12,   12,   12, 0x0a,
     105,   95,   12,   12, 0x0a,
     123,   12,   12,   12, 0x08,

       0        // eod
};

static const char qt_meta_stringdata_GameManager[] = {
    "GameManager\0\0seconds\0gameOver(int)\0"
    "update()\0viewSignal()\0pause()\0size\0"
    "newGame(int)\0pauseGame()\0dirx,diry\0"
    "stepGame(int,int)\0timerUpdate()\0"
};

void GameManager::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        Q_ASSERT(staticMetaObject.cast(_o));
        GameManager *_t = static_cast<GameManager *>(_o);
        switch (_id) {
        case 0: _t->gameOver((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 1: _t->update(); break;
        case 2: _t->viewSignal(); break;
        case 3: _t->pause(); break;
        case 4: _t->newGame((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 5: _t->pauseGame(); break;
        case 6: _t->stepGame((*reinterpret_cast< int(*)>(_a[1])),(*reinterpret_cast< int(*)>(_a[2]))); break;
        case 7: _t->timerUpdate(); break;
        default: ;
        }
    }
}

const QMetaObjectExtraData GameManager::staticMetaObjectExtraData = {
    0,  qt_static_metacall 
};

const QMetaObject GameManager::staticMetaObject = {
    { &QObject::staticMetaObject, qt_meta_stringdata_GameManager,
      qt_meta_data_GameManager, &staticMetaObjectExtraData }
};

#ifdef Q_NO_DATA_RELOCATION
const QMetaObject &GameManager::getStaticMetaObject() { return staticMetaObject; }
#endif //Q_NO_DATA_RELOCATION

const QMetaObject *GameManager::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->metaObject : &staticMetaObject;
}

void *GameManager::qt_metacast(const char *_clname)
{
    if (!_clname) return 0;
    if (!strcmp(_clname, qt_meta_stringdata_GameManager))
        return static_cast<void*>(const_cast< GameManager*>(this));
    return QObject::qt_metacast(_clname);
}

int GameManager::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QObject::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 8)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 8;
    }
    return _id;
}

// SIGNAL 0
void GameManager::gameOver(int _t1)
{
    void *_a[] = { 0, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 0, _a);
}

// SIGNAL 1
void GameManager::update()
{
    QMetaObject::activate(this, &staticMetaObject, 1, 0);
}

// SIGNAL 2
void GameManager::viewSignal()
{
    QMetaObject::activate(this, &staticMetaObject, 2, 0);
}

// SIGNAL 3
void GameManager::pause()
{
    QMetaObject::activate(this, &staticMetaObject, 3, 0);
}
QT_END_MOC_NAMESPACE
