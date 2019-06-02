#include "giantstatestickman.h"
#include "collision.h"
#include <iostream>
GiantStateStickman::GiantStateStickman()
{

}

void GiantStateStickman::jump(Stage3Stickman* self) {
    self->jumpImpulse= 20;

}
void GiantStateStickman::update(Stage3Stickman* context, std::vector<std::unique_ptr<Entity>> &obstacles) {
    context->setSize("giant");
    Coordinate &ac =context->getCoordinate();
    int newY = ac.getYCoordinate() + context->jumpVelocity;
    context->colliding = false;
    // Check for collisions
    std::vector<int> to_erase;
    int erase_pos = 0;
    for (auto &other : obstacles) {

        Collision::CollisonResult col = Collision::moveCast(*context, *other, 0, context->jumpVelocity);
        context->checkPass(other);
        //erase obstacle if its not a flag.
        if (col.overlapped && other->passed==false && other->name!="flag") {
            if(other->name=="heart" && other->collided==false){
                context->life->increment();
                other->collided=true;
            }
            to_erase.push_back(erase_pos);
            context->score.increment();
            other->passed=true;

        }
        erase_pos++;

    }
    //does erase of obstacles.

    for (auto it = to_erase.rbegin(); it != to_erase.rend(); ++it){
        int i = *it;
        obstacles.erase(obstacles.begin()+i);
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
