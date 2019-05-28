#ifndef STAGE3DIALOG_H
#define STAGE3DIALOG_H
#include "stage2dialog.h"
#include "memory.h"
#include "stage3stickman.h"
class Stage3Dialog: public Stage2Dialog{
public:

    Stage3Dialog(Game &game,
                 std::unique_ptr<Stickman> stickman,
                 std::unique_ptr<EntityFactory> factory,
                 std::vector<std::pair<std::unique_ptr<Entity>, int>> obstacleLayout);
    ~Stage3Dialog(){}
    void input(QKeyEvent &event) override;
    void render(Renderer &renderer);
    void update() override;
    //since the stickman never moves, update relative velocity in dialogue instead.
    void speedUp(unsigned int counter) override;

    int frameVelocity = 0;
    int moveImpulse = 20;
    int end = false;
    void moveLeft();
    void moveRight();
    void spawnObstacles(unsigned int counter);
    void renderBackground(Renderer &renderer, unsigned int counter) override;
    void renderObstacles(Renderer &renderer, unsigned int counter) override;



};

#endif // STAGE3DIALOG_H
