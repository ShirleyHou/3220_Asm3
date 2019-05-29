#include "stage3dialog.h"
#include <iostream>
#include <QtMath>
#include "collision.h"

Stage3Dialog::Stage3Dialog(Game &game,
                           std::unique_ptr<Stickman> stickman,
                           std::unique_ptr<EntityFactory> factory,
                           std::vector<std::pair<std::unique_ptr<Entity>, int>> obstacleLayout):
    Stage2Dialog(game,
                 std::move(stickman),
                 std::move(factory),
                 std::move(obstacleLayout))
{

    frameVelocity = background.initialVelocity;
}

void Stage3Dialog::moveLeft(){
    frameVelocity = -3;
}
void Stage3Dialog::moveRight(){
    frameVelocity = 3;
}
void Stage3Dialog::input(QKeyEvent &event){
    Stage3Stickman& stick3 = dynamic_cast<Stage3Stickman&>(*stickman);

    stick3.handleInput(event);
    if (event.key() == Qt::Key_Left && game.longPressed==true) {
        moveLeft();
    }
    if (event.key() == Qt::Key_Right && game.longPressed==true) {
        moveRight();

    }

}



void Stage3Dialog::update() {
    Stage3Stickman& stick3 = dynamic_cast<Stage3Stickman&>(*stickman);

    if(stick3.win||stick3.lost){
        std::cout<<stick3.win <<stick3.lost<<std::endl;
        return;
    }
    if(game.longPressed==false){
        background.setVelocity(0);
        for (auto &o : obstacles) {

            o->setVelocity(0);
        }
    }else{
        background.setVelocity(frameVelocity);

        for (auto &o : obstacles) {

            o->setVelocity(frameVelocity);
        }
    }

    //Stage3Stickman& stick3 = dynamic_cast<Stage3Stickman&>(*stickman);
    if(stick3.dialog!=this){
        stick3.dialog=this;

    }
    stick3.update(obstacles);

    if (!stick3.isColliding()) {

        background.update();
    }
    spawnObstacles(counter);


    for (auto &o : obstacles) {

        o->collisionLogic(stick3);

    }

}

void Stage3Dialog::speedUp(unsigned int counter){

}




void Stage3Dialog::spawnObstacles(unsigned int counter) {
    if(obstacle_to_spawn==-1){
        return;
    }

    if(counter == obstacleSpawnFrame && (obstacle_on_current_level==current_level*5 ||obstacle_to_spawn==0) ){

        std::unique_ptr<Entity> e;
        e = factory->getEntity("flag");
        if(obstacle_to_spawn==0){
            e->isLast = true;
        }
        addObstacle(std::move(e));
        obstacleSpawnFrame += (300 / (1+background.getVelocity())) + ((rand() % 16 )* 3);
        obstacle_to_spawn--;
        obstacle_on_current_level=0;
        current_level+=1;

    }

    if (counter == obstacleSpawnFrame) {

        std::unique_ptr<Entity> e;
        int random = rand()%10;
        if (random<=1){
            e = factory->getEntity("heart");
        }else if(random<=5){
            e = factory->getEntity("bird");
        } else {
            e = factory->getEntity("cactus");
        }


        addObstacle(std::move(e));
        obstacleSpawnFrame += (300 / (1+background.getVelocity())) + ((rand() % 16 )* 3);
        obstacle_to_spawn--;
        obstacle_on_current_level++;


    }


}

void Stage3Dialog::renderObstacles(Renderer &renderer, unsigned int counter) {

    bool deleteObstacle = false;

    for (auto &o: obstacles) {

        o->render(renderer, counter);
        if (o->getCoordinate().getQtRenderingXCoordinate() + o->width() < -2400) {//do not delete obstacle unless its out of an entire frame.
            deleteObstacle = true;

        }
    }
    if (deleteObstacle) {

        obstacles.erase(obstacles.begin());
    }
}
void Stage3Dialog::render(Renderer &renderer) {
    renderBackground(renderer, counter);
    renderObstacles(renderer, counter);
    stickman->render(renderer, counter);
    counter++;
}

void Stage3Dialog::renderBackground(Renderer &renderer, unsigned int counter) {


    game.setStyleSheet("background-color: #000000;");


    QPainter& painter  = renderer.getPainter();
    QRect overlay = QRect(0,0,5000,2400);
    painter.fillRect(overlay, QBrush(QColor(40, 40, 255, (qSin((double)counter/280-100)*100+120))));
    painter.drawRect(overlay);
    QRect overlay2 = QRect(0,0,5000,2400);
    painter.fillRect(overlay2, QBrush(QColor(200, 230, 255, (qSin((double)counter/280)*120+120))));
    painter.drawRect(overlay2);

    renderClouds(renderer, counter);
    moon.render(renderer, counter);
    background.render(renderer, counter);
}

void Stage3Dialog::simpleSave(){
        int total_spawned = 0;
        int total_sum = level*(level-1)*5/2+5*level;
        for(int i=1;i<current_level;i++){
            total_spawned+=i*5;
        }
        int total_to_spawn = total_sum-total_spawned;

        dialog_memo = MementoDialogState(obstacleSpawnFrame, counter,total_to_spawn,current_level);

    }

void Stage3Dialog::simpleRestore(){
        this->obstacles.clear();

        if(current_level!=1){
            auto e = factory->getEntity("flag");
            e->getCoordinate().setXCoordinate(100);
            addObstacle(std::move(e));

        }
        this->obstacleSpawnFrame = dialog_memo.dialog_obstacleSpawnFrame;
        this->counter = dialog_memo.dialog_counter;
        this->current_level = dialog_memo.dialog_current_level;
        this->obstacle_to_spawn = dialog_memo.dialog_obstacles_to_spawn;
        this->obstacle_on_current_level = 0;

        //std::cout<<"Dialog Simple recovered from last state: "<<"current level: "<<this->current_level<< "to spawn: "<<this->obstacle_to_spawn<<std::endl;
    }
