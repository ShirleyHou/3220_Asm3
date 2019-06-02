#include "mementoState.h"
MementoState::MementoState(Score score_to_save, StickmanState* state_to_save, int life):
    score(score_to_save),
    state(state_to_save),
    no_life(life)
{

}
