#ifndef USERSTATE_H
#define USERSTATE_H

#include "score.h"
#include "coordinate.h"
class StickmanState;
class MementoState{
public:
    MementoState(){};
    ~MementoState(){};
    MementoState(Score score, StickmanState* state, Coordinate coordinate);
    Score score;
    StickmanState* state;
    Coordinate coordinate;
};

#endif // USERSTATE_H
