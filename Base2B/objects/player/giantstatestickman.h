#ifndef GIANTSTATESTICKMAN_H
#define GIANTSTATESTICKMAN_H
#include "stickmanstate.h"

class GiantStateStickman:public StickmanState
{
public:
    GiantStateStickman();
    virtual ~GiantStateStickman(){};
    void update(Stage3Stickman* self, std::vector<std::unique_ptr<Entity>> &obstacles);
    void jump(Stage3Stickman* self);
};

#endif // GIANTSTATESTICKMAN_H
