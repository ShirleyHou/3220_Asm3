#include "switchstatetest.h"
#include "normalstatestickman.h"
#include "tinystatestickman.h"
#include "largestatestickman.h"
#include "giantstatestickman.h"
SwitchStateTest::SwitchStateTest():TestRunner("SwitchStateTest")
{
    counter = 0;
    stickman = std::make_unique<Stage3Stickman>(50);
    stickman->setSize("normal");//config.size is a string.
    stickman->setCoordinate(Coordinate(50, 50, 450));
    stickman->setSprite(":sprites/sprite0.png");
    stickman->life = new Life();
    stickman->normal_state = new NormalStateStickman();
    stickman->tiny_state = new TinyStateStickman();
    stickman->large_state= new LargeStateStickman();
    stickman->giant_state = new GiantStateStickman();
    stickman->current_state = stickman->normal_state;
    stickman->dialog=nullptr;
    //std::unique_ptr<Bird> obstacle = std::make_unique<Bird>(Coordinate(400, 50, 450), 2);
    //obstacles.push_back(std::move(obstacle));
}

void SwitchStateTest::update() {
    std::cout<<counter<<std::endl;
    stickman->update(obstacles);
    if (counter!=0 && counter%600==0){
        stickman->current_state = stickman->giant_state;
        std::cout<<"here"<<std::endl;
        status = Status::Passed;
    }else if(counter!=0 && counter%400==0){
        stickman->current_state = stickman->large_state;
    }else if (counter!=0 && counter%200==0){
        stickman->current_state = stickman->tiny_state;
    }



}
void SwitchStateTest::render(Renderer &renderer) {

    stickman->render(renderer, counter++);

}
