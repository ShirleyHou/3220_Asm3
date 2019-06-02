#ifndef GAINLIFETEST_H
#define GAINLIFETEST_H

#include "stage3stickman.h"
#include "testrunner.h"
#include "entity.h"

/*
 * show if colliding with a heart gets you a life.
 */
class GainLifeTest : public TestRunner
{
public:
    GainLifeTest();
     ~GainLifeTest() = default;
    void update();
    void render(Renderer &renderer);
private:
    int counter;
    std::unique_ptr<Stage3Stickman> stickman;
    std::vector<std::unique_ptr<Entity>> obstacles;
    int original_life;
};

#endif // GAINLIFETEST_H
