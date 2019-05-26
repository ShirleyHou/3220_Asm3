#include "stage3dialog.h"
#include <iostream>

Stage3Dialog::Stage3Dialog(Game &game,
                           std::unique_ptr<Stickman> stickman,
                           std::unique_ptr<EntityFactory> factory,
                           std::vector<std::pair<std::unique_ptr<Entity>, int>> obstacleLayout):
    Stage2Dialog(game,
                 std::move(stickman),
                 std::move(factory),
                 std::move(obstacleLayout))
{
    std::cout<<"stage 3 triggered"<<std::endl;
    frameVelocity = background.initialVelocity;

}

void Stage3Dialog::moveLeft(){
    frameVelocity = -3;
}
void Stage3Dialog::moveRight(){
    frameVelocity = 3;
}
void Stage3Dialog::input(QKeyEvent &event){

    stickman->handleInput(event);
    if (event.key() == Qt::Key_Left && game.longPressed==true) {
        moveLeft();
    }
    if (event.key() == Qt::Key_Right && game.longPressed==true) {
        moveRight();
    }

}


void Stage3Dialog::update() {

    if(game.longPressed==false){
        background.setVelocity(0);
    }else{
        background.setVelocity(frameVelocity);
    }


    //background.setVelocity(background.getVelocity()+frameVelocity);
    stickman->update(obstacles);
    if (!stickman->isColliding()) {
        // Reduce distance to next obstacle
        distanceToSpawn -= background.getVelocity();
        background.update();
        speedUp(counter);
        score.increment();
    }
    spawnObstacles(counter);

    for (auto &c : clouds) {
        c->collisionLogic(*stickman);
    }

    for (auto &o : obstacles) {
        o->collisionLogic(*stickman);
    }
}
