#include "giantstatecollisiontest.h"
#include "normalstatestickman.h"
#include "life.h"
#include "stage3dialog.h"
#include "giantstatestickman.h"
GiantStateCollisionTest::GiantStateCollisionTest(): TestRunner("Giant Collision Test")
{
    stickman = std::make_unique<Stage3Stickman>(50);
    stickman->setSize("normal");//config.size is a string.
    stickman->setCoordinate(Coordinate(50, 50, 450));
    stickman->setSprite(":sprites/sprite0.png");
    stickman->life = new Life(3);
    original_life = stickman->life->no_life;
    stickman->normal_state = new NormalStateStickman();
    stickman->giant_state = new GiantStateStickman();
    stickman->current_state = stickman->giant_state;//normal_state;
    stickman->reset = false;


    std::unique_ptr<Bird> obstacle = std::make_unique<Bird>(Coordinate(400, 50, 450), 2);
    std::unique_ptr<Bird> obstacle2 = std::make_unique<Bird>(Coordinate(1400, 50, 450), 2);
    obstacle->passed =false;
    obstacle->collided =false;
    obstacles.push_back(std::move(obstacle));
    obstacles.push_back(std::move(obstacle2));
    stickman->dialog=nullptr;
}

void GiantStateCollisionTest::update() {

    if(status!=Status::Passed && obstacles.size()!=0){
        stickman->update(obstacles);
        obstacles[0]->collisionLogic(*stickman);
    }

    if(obstacles.size()==1){
        status = Status::Passed;

    }

}

void GiantStateCollisionTest::render(Renderer &renderer) {

    stickman->render(renderer, counter++);
    if(obstacles.size()>0){
        obstacles[0]->render(renderer, counter);
    }
}
