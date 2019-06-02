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
     * @brief Stage3Stickman is An extension of the JumpingStickman class which also detects
     * @param same as stage 2.
     * most dependencies required by stage3stickman are added from stagefactory.
     * This is for concern of many dependencies are not needed by the testing dialog.
     */
    Stage3Stickman(int floor,
                   int jumpImpulse = 15,
                   int maxJumpCount = 2,
                   int gravity = -1
                   );
    ~Stage3Stickman(){};

    void handleInput(QKeyEvent &event);
    void checkPass(std::unique_ptr<Entity> &other);



    void update(std::vector<std::unique_ptr<Entity>> &obstacles) override;
    void render(Renderer &renderer, unsigned int time) override;


    /*new features of Stage3Stickman:
     * 1. Life
     * 2. Score
     * 3. boolean information about win/lose
     * 4. ability to reset on win/lose/collision.
     *
    */
    Life* life;
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

    //not a full implementation of memento, but the idea is from memento design pattern
    void simpleSave(){
        memento_state = MementoState(score, current_state);
    }
    void initializeSave(){
        if(life!=nullptr){
            this->initial_memento_state.no_life = life->no_life;
        }
    }
    void simpleRestore(){
        MementoState recover_state = memento_state;
        this->score.currScore = recover_state.score.currScore;
        this->current_state = recover_state.state;
        std::cout<<"Stickman Simple recovered from last state"<<std::endl;
    }

    void restart();

    MementoState memento_state;
    MementoState initial_memento_state;

    //notifies the dialog about win/lose information because the decision is made by the stickman's condition.
    Stage3Dialog* dialog;

};

#endif // JUMPINGSTICKMAN_H
