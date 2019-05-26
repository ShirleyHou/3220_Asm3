#ifndef STAGE3STICKMAN_H
#define STAGE3STICKMAN_H

#include <memory>
#include "entity.h"
#include "jumpingstickman.h"


class Stage3Stickman : public JumpingStickman {
public:
    /**
     * @brief Stage3Stickman is An extension of the Stickman class which adds jumping and collision detection
     * @param floor The y position which is considered the floor (i.e. will stop falling at)
     * @param jumpImpulse The vertical velocity applied when jumping
     * @param maxJumpCount The maximum amount of jumps that can be peformed mid-air (including the initial jump)
     * @param gravity The falling rate
     */
    Stage3Stickman(int floor,
                   int jumpImpulse = 15,
                   int maxJumpCount = 2,
                   int gravity = -1,
                   int noOflife = 3);
    ~Stage3Stickman(){};
    virtual void handleInput(QKeyEvent &event) override;
    int life;
    void update(std::vector<std::unique_ptr<Entity>> &obstacles) override;
};

#endif // JUMPINGSTICKMAN_H
