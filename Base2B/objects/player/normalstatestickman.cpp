#include "normalstatestickman.h"
#include "collision.h"
#include <iostream>
NormalStateStickman::NormalStateStickman(){
}

void NormalStateStickman::jump(Stage3Stickman* self) {
    self->jumpImpulse= 15;

}

void NormalStateStickman::update(Stage3Stickman* context, std::vector<std::unique_ptr<Entity>> &obstacles) {
    context->setSize("normal");
    Coordinate &ac =context->getCoordinate();
    int newY = ac.getYCoordinate() + context->jumpVelocity;
    context->colliding = false;
    // Check for collisions

    for (auto &other : obstacles) {

        Collision::CollisonResult col = Collision::moveCast(*context, *other, 0, context->jumpVelocity);

        context->checkPass(other);
        if (col.overlapped) {
            if (!other->collided){
                context->life->decrement();
                other->collided=true;
            }
            int by = other->getCoordinate().getYCoordinate();
            if (col.down && context->jumpVelocity < 0) {
                // Hitting obstacle from above
                context->jumpVelocity = 0;
                context->grounded = true;
                context->jumpCount = 0;
                newY = by + other->height() + 1;
            } else if (col.up) {
                // Hitting obstacle from below
                context->jumpVelocity = 0;
                newY = by - context->height() - 1;
            } else {
                // Hidding obstacle from the side
                context->colliding = true;
            }
        }
    }


    // Check if we're below the floor
    if (newY <= context->floor) {
        newY = context->floor;
        context->grounded = true;
        context->jumpVelocity = 0;
        context->jumpCount = 0;
    }

    ac.setYCoordinate(newY);
    context->jumpVelocity += context->gravity;
}

