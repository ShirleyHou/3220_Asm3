#ifndef LARGESTICKMANSTATE_H
#define LARGESTICKMANSTATE_H
#include "stickmanstate.h"
#include "stage3stickman.h"

class LargeStateStickman: public StickmanState
{
public:
    LargeStateStickman();
    virtual ~LargeStateStickman(){};
    void update(Stage3Stickman* self, std::vector<std::unique_ptr<Entity>> &obstacles);
    void jump(Stage3Stickman* self);
};

#endif // LARGESTICKMANSTATE_H
