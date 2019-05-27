#include "stage3stickman.h"
#include "collision.h"
#include <iostream>
#include "stickmanstate.h"
Stage3Stickman::Stage3Stickman(int floor, int jumpImpulse, int maxJumpCount, int gravity, int noOfLife) :
    JumpingStickman (floor, jumpImpulse, maxJumpCount, gravity),
    life(noOfLife){

}
void Stage3Stickman::handleInput(QKeyEvent &event) {

    if (event.key()==Qt::Key_T){
        current_state = tiny_state;
    }
    if (event.key() == Qt::Key_Space && !event.isAutoRepeat() && canJump()) {
        current_state->jump(this);
        jumpVelocity = jumpImpulse;
        jumpCount++;
        grounded = false;
    }

}

//haven't modified
void Stage3Stickman::update(std::vector<std::unique_ptr<Entity>> &obstacles) {

    current_state->update(this, obstacles);

    //Stickman* self,
    //bool& grounded,
    //int & jumpVelocity,
    //int & jumpCount,
    //Coordinate &ac,
    //bool & colliding,
    //std::vector<std::unique_ptr<Entity>> &obstacles





//    Coordinate &ac = getCoordinate();
//    int newY = ac.getYCoordinate() + jumpVelocity;
//    colliding = false;

//    // Check for collisions
//    for (auto &other : obstacles) {
//        Collision::CollisonResult col = Collision::moveCast(*this, *other, 0, jumpVelocity);

//        if (col.overlapped) {
//            int by = other->getCoordinate().getYCoordinate();
//            if (col.down && jumpVelocity < 0) {
//                // Hitting obstacle from above
//                jumpVelocity = 0;
//                grounded = true;
//                jumpCount = 0;
//                newY = by + other->height() + 1;
//            } else if (col.up) {
//                // Hitting obstacle from below
//                jumpVelocity = 0;
//                newY = by - height() - 1;
//            } else {
//                // Hidding obstacle from the side
//                colliding = true;
//            }
//        }
//    }

//    // Check if we're below the floor
//    if (newY <= floor) {
//        newY = floor;
//        grounded = true;
//        jumpVelocity = 0;
//        jumpCount = 0;
//    }

//    ac.setYCoordinate(newY);
//    jumpVelocity += gravity;
}
