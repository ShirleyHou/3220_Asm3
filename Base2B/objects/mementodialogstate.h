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
    MementoDialogState(int obstacleSpawnFrame, int counter,int obstacle_render_counter,int obstacles_to_spawn,int current_level):

                       dialog_obstacleSpawnFrame(obstacleSpawnFrame),
                       dialog_counter(counter),
                       dialog_obstacle_render_counter(obstacle_render_counter),
                       dialog_obstacles_to_spawn(obstacles_to_spawn),
                       dialog_current_level(current_level)
    {}
    MementoDialogState(const MementoDialogState& s2){
        dialog_counter = s2.dialog_counter;
        dialog_obstacle_render_counter = s2.dialog_obstacle_render_counter;
        dialog_obstacleSpawnFrame=s2.dialog_obstacleSpawnFrame;
        dialog_obstacles_to_spawn = s2.dialog_obstacles_to_spawn;
        dialog_current_level = s2.dialog_current_level;
    }
    //std::vector<std::unique_ptr<Entity>> dialog_obstacles;
    int dialog_obstacleSpawnFrame;
    int dialog_counter;
    int dialog_obstacle_render_counter;
    int dialog_obstacles_to_spawn;
    int dialog_current_level;

};

#endif // MEMENTODIALOGSTATE_H
