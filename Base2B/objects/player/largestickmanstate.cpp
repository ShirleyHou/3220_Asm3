#include "largestatestickman.h"
#include "collision.h"
#include <iostream>
LargeStateStickman::LargeStateStickman()
{

}

void LargeStateStickman::jump(Stage3Stickman* self) {
    self->jumpImpulse= 20;

}
void LargeStateStickman::update(Stage3Stickman* context, std::vector<std::unique_ptr<Entity>> &obstacles) {
    context->setSize("large");
    Coordinate &ac =context->getCoordinate();
    int newY = ac.getYCoordinate() + context->jumpVelocity;
    context->colliding = false;
    // Check for collisions
    for (auto &other : obstacles) {
        Collision::CollisonResult col = Collision::moveCast(*context, *other, 0, context->jumpVelocity);

        context->checkPass(other);
        if(other->name=="flag"){
            continue;
        }

        if (col.overlapped) {
            if(!other->collided){
                //heart are erased when hit by non tiny states.
                if(other->name!="heart"){
                context->life->decrement();
                context->reset=true;
                other->collided=true;
                return;
                }else{
                    context->life->increment();
                    other->collided=true;
                }

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
