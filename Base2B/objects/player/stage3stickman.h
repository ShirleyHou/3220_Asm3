#ifndef STAGE3STICKMAN_H
#define STAGE3STICKMAN_H

#include <memory>
#include <iostream>
#include "entity.h"
#include "jumpingstickman.h"
#include "score.h"
#include "life.h"
#include "mementoState.h"
#include "memento.h"
#include "background.h"
class StickmanState;

class Stage3Dialog;

class Stage3Stickman : public JumpingStickman {
public:
    /**
     * @brief Stage3Stickman is An extension of the Stickman class which adds jumping and collision detection
     * @param floor The y position which is considered the floor (i.e. will stop falling at)
     * @param jumpImpulse The vertical velocity applied when jumping
     * @param maxJumpCount The maximum amount of jumps that can be peformed mid-air (including the initial jump)
     * @param gravity The falling rate
     */
    Stage3Stickman(int floor,
                   int jumpImpulse = 15,
                   int maxJumpCount = 2,
                   int gravity = -1
                   );
    ~Stage3Stickman(){};
    void handleInput(QKeyEvent &event);
    void checkPass(std::unique_ptr<Entity> &other);


    Life* life;
    void update(std::vector<std::unique_ptr<Entity>> &obstacles) override;
    void render(Renderer &renderer, unsigned int time) override;
    Score score;
    bool lost = false;
    bool win = false;
    QPixmap* gameOver;
    QPixmap* gameWin;
    bool reset = false;




    StickmanState* current_state;
    StickmanState* normal_state;
    StickmanState* tiny_state;
    StickmanState* large_state;
    StickmanState* giant_state;

    void simpleSave(){
        memento_state = MementoState(score, current_state);

    }
    void simpleRestore(){
        MementoState recover_state = memento_state;
        this->score = recover_state.score;
        this->current_state = recover_state.state;
        std::cout<<"Stickman Simple recovered from last state"<<std::endl;
    }


    MementoState memento_state;
    MementoState initial_memento_state;
    Stage3Dialog* dialog;//for notify purpose

};

#endif // JUMPINGSTICKMAN_H
