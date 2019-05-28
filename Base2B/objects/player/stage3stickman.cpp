#include "stage3stickman.h"
#include "collision.h"
#include <iostream>
#include "stickmanstate.h"
Stage3Stickman::Stage3Stickman(int floor, int jumpImpulse, int maxJumpCount, int gravity) :
    JumpingStickman (floor, jumpImpulse, maxJumpCount, gravity),
    score(Score())
    {
    gameOver = new QPixmap (":/sprites/GameOver.png");
    gameWin = new QPixmap (":/sprites/Win.png");

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
void Stage3Stickman::checkPass(std::unique_ptr<Entity> &other){
    if (!other->passed && other->getCoordinate().getXCoordinate()+other->width() <this->getCoordinate().getXCoordinate()){
        this->score.increment();
        other->passed=true;
        if(other->isLast){
            win = true;
        }
    }
}

void Stage3Stickman::update(std::vector<std::unique_ptr<Entity>> &obstacles) {

    current_state->update(this, obstacles);
    if (life->no_life==0){
        lost = true;
    }
}

void Stage3Stickman::render(Renderer &renderer, unsigned int time) {
    Stickman::render(renderer, time);
    score.render(renderer);
    life->render(renderer);
    if(lost){
        renderer.draw(100,100,*gameOver);
    }else if(win){
        renderer.draw(100,100,*gameWin);
    }


}

