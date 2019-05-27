#include "giantstatestickman.h"
#include "collision.h"
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

        if (col.overlapped) {

            to_erase.push_back(erase_pos);
//            int by = other->getCoordinate().getYCoordinate();
//            if (col.down && context->jumpVelocity < 0) {
//                // Hitting obstacle from above
//                context->jumpVelocity = 0;
//                context->grounded = true;
//                context->jumpCount = 0;
//                newY = by + other->height() + 1;
//            } else if (col.up) {
//                // Hitting obstacle from below
//                context->jumpVelocity = 0;
//                newY = by - context->height() - 1;
//            } else {
//                // Hidding obstacle from the side
//                context->colliding = true;
//            }
        }
        //erase_pos ++;
    }
    //does erase
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
