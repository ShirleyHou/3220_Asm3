#ifndef MEMENTODIALOGSTATE_H
#define MEMENTODIALOGSTATE_H


#include <vector>
#include <memory>
#include "entity.h"
class MementoDialogState
{
public:
    MementoDialogState();
    ~MementoDialogState(){};
    MementoDialogState(int obstacleSpawnFrame, int counter,int obstacles_to_spawn,int current_level):

                       dialog_obstacleSpawnFrame(obstacleSpawnFrame),
                       dialog_counter(counter),
                       dialog_obstacles_to_spawn(obstacles_to_spawn),
                       dialog_current_level(current_level)
    {}
    //std::vector<std::unique_ptr<Entity>> dialog_obstacles;
    int dialog_obstacleSpawnFrame;
    int dialog_counter;
    int dialog_obstacles_to_spawn;
    int dialog_current_level;

};

#endif // MEMENTODIALOGSTATE_H
