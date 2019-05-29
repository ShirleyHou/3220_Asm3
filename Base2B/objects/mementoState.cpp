#include "mementoState.h"
MementoState::MementoState(Score score_to_save, StickmanState* state_to_save, Coordinate coord):
    score(score_to_save),
    state(state_to_save),
    coordinate(coord)
{

}
