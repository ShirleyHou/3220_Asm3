#include "tinystatestickman.h"
#include "collision.h"
#include <iostream>
TinyStateStickman::TinyStateStickman(){
}

void TinyStateStickman::jump(Stage3Stickman* self) {
    self->jumpImpulse= 15;

}

void TinyStateStickman::update(Stage3Stickman* context, std::vector<std::unique_ptr<Entity>> &obstacles) {
    context->setSize("tiny");
    Coordinate &ac =context->getCoordinate();
    int newY = ac.getYCoordinate() + context->jumpVelocity;
    context->colliding = false;
    // Check for collisions
    for (auto &other : obstacles) {
        Collision::CollisonResult col = Collision::moveCast(*context, *other, 0, context->jumpVelocity);
//        if (!other->passed && other->getCoordinate().getXCoordinate()+other->width() <ac.getXCoordinate()){
//            context->score.incrementBy(1);
//            other->passed=true;

//        }
        context->checkPass(other);
        if (col.overlapped) {

            int by = other->getCoordinate().getYCoordinate();
            if (col.down && context->jumpVelocity < 0) {
                // Hitting obstacle from above
                context->jumpVelocity = 0;
                context->grounded = true;
                context->jumpCount = 0;
                newY = by + other->height() + 1;
            }//else we don't care.


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

