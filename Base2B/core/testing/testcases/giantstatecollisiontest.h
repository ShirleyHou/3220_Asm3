#ifndef GIANTSTATECOLLISIONTEST_H
#define GIANTSTATECOLLISIONTEST_H

#include "stage3stickman.h"
#include "testrunner.h"
#include "entity.h"

/*
 * show colliding on giant state removes an obstacle.
 */
class GiantStateCollisionTest: public TestRunner
{
public:
    GiantStateCollisionTest();
     ~GiantStateCollisionTest()= default;
    void update();
    void render(Renderer &renderer);
private:
    int counter;
    std::unique_ptr<Stage3Stickman> stickman;
    std::vector<std::unique_ptr<Entity>> obstacles;
    int original_life;
};

#endif // GIANTCOLLISIONTEST_H
