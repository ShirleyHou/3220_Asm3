#include "stage3stickman.h"
#include "collision.h"
#include <iostream>
#include "stickmanstate.h"
Stage3Stickman::Stage3Stickman(int floor, int jumpImpulse, int maxJumpCount, int gravity, int noOfLife) :
    JumpingStickman (floor, jumpImpulse, maxJumpCount, gravity),
    life (Life()),
    score(Score())
    {

}
void Stage3Stickman::handleInput(QKeyEvent &event) {

    if (event.key()==Qt::Key_T){
        current_state = tiny_state;
    }
    if (event.key()==Qt::Key_N){
        current_state = normal_state;
    }
    if (event.key()==Qt::Key_L){
        current_state = large_state;
    }
    if (event.key()==Qt::Key_G){
        current_state = giant_state;
    }
    if (event.key() == Qt::Key_Space && !event.isAutoRepeat() && canJump()) {
        current_state->jump(this);
        jumpVelocity = jumpImpulse;
        jumpCount++;
        grounded = false;
    }

}

void Stage3Stickman::update(std::vector<std::unique_ptr<Entity>> &obstacles) {

    current_state->update(this, obstacles);

}

void Stage3Stickman::render(Renderer &renderer, unsigned int time) {
    Stickman::render(renderer, time);
    score.render(renderer);
    life.render(renderer);
}

