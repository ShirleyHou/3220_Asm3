#include "stage3stickman.h"
#include "collision.h"
#include <iostream>
#include "stickmanstate.h"
#include "stage3dialog.h"
Stage3Stickman::Stage3Stickman(int floor, int jumpImpulse, int maxJumpCount, int gravity) :
    JumpingStickman (floor, jumpImpulse, maxJumpCount, gravity),
    score(Score()),
    memento_state(MementoState()),
    initial_memento_state(MementoState())
    {
    memento_state = MementoState(score, current_state);
    initial_memento_state = MementoState(score, current_state);
    gameOver = new QPixmap (":/sprites/GameOver.png");
    gameWin = new QPixmap (":/sprites/Win.png");

}
void Stage3Stickman::handleInput(QKeyEvent &event) {
    if (event.key()==Qt::Key_Return && (this->win||this->lost)){
        std::cout<<"triggered restart"<<std::endl;
        this->restart();
        this->dialog->restart();

    }

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
        std::cout<<other->name<<std::endl;
        if(other->name!="flag"&&other->name!="heart"){
            this->score.increment();
        }else if(other->name=="flag"){
            //passed a level.
            this->dialog->simpleSave(); //save dialog
            this->simpleSave();//save myself.
        }
        other->passed=true;
        if(other->isLast){
            win = true;
            this->score.hiScore = std::max(score.hiScore, score.currScore);
        }
    }
}

void Stage3Stickman::update(std::vector<std::unique_ptr<Entity>> &obstacles) {

    current_state->update(this, obstacles);

    if (life->no_life==0){
        lost = true;
        this->score.hiScore = std::max(score.hiScore, score.currScore);
    }
    if(reset==true){
        std::cout<<"triggered reset"<<std::endl;
        simpleRestore();
        if(this->dialog!=nullptr){
            this->dialog->simpleRestore();
        }
        reset=false;
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
void Stage3Stickman::restart(){

        this->score.currScore =1;
        this->current_state = this->normal_state;
        this->win=false;
        this->lost=false;
        this->life=new Life(this->initial_memento_state.no_life);
        this->simpleSave();

        std::cout<<"Stickman Simple restarted"<<std::endl;
    }

