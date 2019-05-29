#ifndef MEMENTO_H
#define MEMENTO_H

#include "mementoState.h"
class Memento{
public:
    Memento(MementoState toSave):
        savedState(toSave){}
protected:
    const MementoState savedState;
    friend class Stage3Stickman;

};

#endif // MEMENTO_H
