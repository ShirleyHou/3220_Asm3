#ifndef USERSTATE_H
#define USERSTATE_H

#include "score.h"
#include "coordinate.h"

class StickmanState;
class MementoState{
public:
    MementoState(){};
    ~MementoState(){};
    MementoState(Score score, StickmanState* state, int life=3);
    Score score;
    StickmanState* state;
    int no_life;
};

#endif // USERSTATE_H
