## =======! VIDEO DEMO !=======
**watch demo** recording on : https://youtu.be/jJSu3OQh70Q

## ======= CONFIG FILE INSTRUCTIONS FOR STAGE 3 =======
To enable stage 2, the setting "stage: 3" should be in the config file. 

Otherwise, the specified stage 2 or 1 will run.

To enable the testing interface, the settings "stage: 3" and "testMode: on" should be in the config file.

Obstacles are randomly created for stage 3. No specification is needed. 

Set the number of lives in "life: ...". This will be the initial number of lives in every game you restart. 

Set the number of levels in "level: ...".  Each level will have n*5 number of obstacles. For example, level 1 will have 5. 
level 2 will have 10, level 3 will have 15...etc. 

## ======= additional features of stage 3 ======
1. Score is calculated by the number of obstacles you suceesfully passed.
2. Press "N" to switch to Normal State.
3. Press "T" to switch to Tiny State.
4. Press "G" to switch to Giant State.
5. Press "L" to switch to Large State.
6. Press "Space" to jump.
7. When the stickman is normal state/large state, collision with an obstacle leads to lose of a life and restart on the same level, with the state and position you started this level.
8. When the stickman hits a heart, it gains a life, no matter what state it is.
9. When you use up all your life, the game ends with lose. 
10. If you sucessfully pass all obstacles on all levels with at least one life, the game wins.
11. You can hit enter to restart the game after game win/lose.


## ======= Behavioral Design Pattern Used =======
* State Design Pattern
* - Abstract states: "stickmanstates.h"
* - Concrete states: "giantstatestickman.h", "largestatestickman.h", "normalstatestickman.h", "tinystatestickman.h"

* - Context: "stage3stickman.h"
* - handle methods: render(), update()
* this design pattern enables easy switching between how a obstacle update and rendering method.

* partially Memento
* - "mementoState.h", "stage3stickman.h", "mementodialogstate.h", "stage3dialog.h"
* - stickman saves memento information in MementoState class.
* - dialog saves memento information in MementoDialogState class.


## ======= Coding Style =======
See README_STAGE2

## ======= Extensions =======
== More powerups ==
1. You gain a life if you collide with a heart.

== Able to restart from the game ==
1. When the game wins/loses, you can hit enter and restart the game with everything set back to default.

2. The game can be start for infinite number of times, and the historical best mark on this run will be recorded as "HI SCORE", just as the same mechanism and layout in the chrome dinosaur game.