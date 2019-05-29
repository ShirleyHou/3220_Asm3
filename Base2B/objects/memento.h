#ifndef MEMENTO_H
#define MEMENTO_H

#include "mementoState.h"
#include "mementodialogstate.h"
class Memento{
public:
    Memento(MementoState toSave, MementoDialogState dialogState):
        savedState(toSave),
        dialogState(dialogState)
    {}
protected:
    const MementoState savedState;
    const MementoDialogState dialogState;
    friend class Stage3Stickman;
    friend class Stage3Dialog;
};

#endif // MEMENTO_H
