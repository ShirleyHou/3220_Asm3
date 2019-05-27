#ifndef STICKMANSTATE_H
#define STICKMANSTATE_H
#include <QKeyEvent>
#include <memory>
#include "entity.h"
#include "coordinate.h"
#include "stage3stickman.h"

class StickmanState{
public:
    StickmanState(){}
    virtual ~StickmanState(){}
    //virtual void render()=0;
    virtual void update(Stage3Stickman* self,std::vector<std::unique_ptr<Entity>> &obstacles)=0;
    virtual void jump(Stage3Stickman* self) = 0;

};
#endif // STICKMANSTATE_H
