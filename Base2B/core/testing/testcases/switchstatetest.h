#ifndef SWITCHSTATETEST_H
#define SWITCHSTATETEST_H
#include "stage3stickman.h"
#include "testrunner.h"
#include "entity.h"

class SwitchStateTest : public TestRunner
{
public:
    SwitchStateTest();
    ~SwitchStateTest() = default;
    void update();
    void render(Renderer &renderer);
private:
    int counter;
    std::unique_ptr<Stage3Stickman> stickman;
    std::vector<std::unique_ptr<Entity>> obstacles;
};

#endif // SWITCHSTATETEST_H
