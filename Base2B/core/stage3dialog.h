#ifndef STAGE3DIALOG_H
#define STAGE3DIALOG_H
#include "stage2dialog.h"
#include "memory.h"
#include "stage3stickman.h"


class Stage3Dialog: public Stage2Dialog{

    /**
     * @brief Stage3Dialog is An extension of the Stage2Dialog class because we want to overwrite
     * 1. the way dialog manages the background coordinate.
     * 2. how obstacles are spawned
     * 3. how key events are handled
     * 4. the abiltiy to save dialog state. level information. etc.
     */
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
    int obstacle_render_counter = 0;

    int obstacle_to_spawn = 0;
    int obstacle_on_current_level = 0;
    int level;
    int current_level = 1;


    void moveLeft();
    void moveRight();

    void spawnObstacles(unsigned int counter) override;
    void renderBackground(Renderer &renderer, unsigned int counter) override;
    void renderObstacles(Renderer &renderer, unsigned int counter) override;

    void simpleSave();
    void simpleRestore();
    void restart();

    MementoDialogState dialog_initial_state;
    MementoDialogState dialog_memo;



};

#endif // STAGE3DIALOG_H
