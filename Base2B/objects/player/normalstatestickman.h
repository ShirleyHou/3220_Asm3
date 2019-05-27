#ifndef NORMALSTATESTICKMAN_H
#define NORMALSTATESTICKMAN_H
#include "stickmanstate.h"
#include "stage3stickman.h"

class NormalStateStickman: public StickmanState
{
public:
    NormalStateStickman();
    virtual ~NormalStateStickman(){};
    void update(Stage3Stickman* self, std::vector<std::unique_ptr<Entity>> &obstacles);
    void jump(Stage3Stickman* self);
};

#endif // NORMALSTATESTICKMAN_H
