#ifndef DIALOG_H
#define DIALOG_H

#include <vector>
#include <QDialog>
#include <QPainter>
#include <QFile>
#include <QTimer>
#include <memory>
#include "stickman.h"
#include "background.h"
#include "entity.h"
#include "moon.h"
#include "score.h"
#include "entityfactory.h"
#include "game.h"
#include "renderer.h"

class Dialog : public GameStage {
public:
    Dialog(Game &game, std::unique_ptr<Stickman> stickman, std::unique_ptr<EntityFactory> factory);
    ~Dialog();

    virtual void update();
    virtual void render(Renderer &renderer);
    virtual void input(QKeyEvent &event);

    void setStickman(std::unique_ptr<Stickman> stickman);
    void setBackground(Background background);
    void setMoon(Moon moon);
    void setScore(int score);

protected:
    virtual void spawnObstacles(unsigned int counter);
    void addObstacle(std::unique_ptr<Entity> obstacle);
    virtual void speedUp(unsigned int counter);

    virtual void renderBackground(Renderer &renderer, unsigned int counter);
    void renderClouds(Renderer &renderer, unsigned int counter);
    void renderObstacles(Renderer &renderer, unsigned int counter);

    Game &game;
    std::unique_ptr<Stickman> stickman;
    std::unique_ptr<EntityFactory> factory;
    Background background;
    std::vector<std::unique_ptr<Entity>> obstacles;
    std::vector<std::unique_ptr<Entity>> clouds;
    Score score;
    int counter;

    Moon moon;

private:
    bool night;
    unsigned int obstacleSpawnFrame;
    unsigned int cloudSpawnFrame;
};

#endif // DIALOG_H
