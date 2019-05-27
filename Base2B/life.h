#ifndef LIFE_H
#define LIFE_H

#include <string>
#include <stack>
#include <QPainter>
#include <QPixmap>
#include "renderer.h"

class Life
{
public:
    Life();
    int no_life;
    void decrement();
    void increment();
    QPixmap heart;
    void render(Renderer &renderer);
};

#endif // LIFE_H
