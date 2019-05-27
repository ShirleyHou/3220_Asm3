#ifndef TINYSTATESTICKMAN_H
#define TINYSTATESTICKMAN_H


#include "stickmanstate.h"
#include "stage3stickman.h"

class TinyStateStickman:public StickmanState
{
public:
    TinyStateStickman();
    virtual ~TinyStateStickman(){};
    void update(Stage3Stickman* self, std::vector<std::unique_ptr<Entity>> &obstacles);
    void jump(Stage3Stickman* self);
};

#endif // TINYSTATESTICKMAN_H

