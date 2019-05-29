#ifndef USERSTATE_H
#define USERSTATE_H

#include "score.h"
#include "coordinate.h"
class StickmanState;
class MementoState{
public:
    MementoState(){};
    ~MementoState(){};
    MementoState(Score score, StickmanState* state);
    Score score;
    StickmanState* state;
};

#endif // USERSTATE_H
