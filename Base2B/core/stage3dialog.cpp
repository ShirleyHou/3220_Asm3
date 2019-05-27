#include "stage3dialog.h"
#include <iostream>
#include <QtMath>
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
        for (auto &o : obstacles) {

            o->setVelocity(0);
        }
    }else{
        background.setVelocity(frameVelocity);

        for (auto &o : obstacles) {

            o->setVelocity(frameVelocity);
        }
    }


    stickman->update(obstacles);
    if (!stickman->isColliding()) {
        // Reduce distance to next obstacle
        distanceToSpawn -= background.getVelocity();
        background.update();


    }
    spawnObstacles(counter);

    for (auto &c : clouds) {
        c->collisionLogic(*stickman);
    }

    for (auto &o : obstacles) {

        o->collisionLogic(*stickman);
    }
}

void Stage3Dialog::speedUp(unsigned int counter){

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
