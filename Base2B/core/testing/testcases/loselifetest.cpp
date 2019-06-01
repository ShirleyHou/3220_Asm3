#include "loselifetest.h"
#include "normalstatestickman.h"
#include "life.h"
#include "stage3dialog.h"
LoseLifeTest::LoseLifeTest():TestRunner("LoseLifeTest"){
    stickman = std::make_unique<Stage3Stickman>(50);
    stickman->setSize("normal");//config.size is a string.
    stickman->setCoordinate(Coordinate(50, 50, 450));
    stickman->setSprite(":sprites/sprite0.png");
    stickman->life = new Life();
    original_life = stickman->life->no_life;
    stickman->normal_state = new NormalStateStickman();
    stickman->current_state = stickman->normal_state;
    stickman->reset = false;


    std::unique_ptr<Bird> obstacle = std::make_unique<Bird>(Coordinate(400, 50, 450), 2);
    obstacle->passed =false;
    obstacle->collided =false;
    obstacles.push_back(std::move(obstacle));
    stickman->dialog=nullptr;

}



void LoseLifeTest::update() {

    if(status!=Status::Passed){
        stickman->update(obstacles);
        obstacles[0]->collisionLogic(*stickman);
    }

    if(stickman->life->no_life!=original_life){
        status = Status::Passed;

    }

}

void LoseLifeTest::render(Renderer &renderer) {

    stickman->render(renderer, counter++);
    obstacles[0]->render(renderer, counter);
}
