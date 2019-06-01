#ifndef LOSELIFETEST_H
#define LOSELIFETEST_H

#include "stage3stickman.h"
#include "testrunner.h"
#include "entity.h"

class LoseLifeTest : public TestRunner {
public:
    LoseLifeTest();
     ~LoseLifeTest() = default;
    void update();
    void render(Renderer &renderer);

private:
    int counter;
    std::unique_ptr<Stage3Stickman> stickman;
    std::vector<std::unique_ptr<Entity>> obstacles;
    int original_life;
};

#endif // LOSELIFETEST_H
