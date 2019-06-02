#ifndef SCORE_H
#define SCORE_H

#include <string>
#include <stack>
#include <QPainter>
#include <QPixmap>
#include "renderer.h"

class Score {
public:
    Score();

    void increment();
    void incrementBy(int update);
    void decrement();
    void render(Renderer &renderer);
    void setScore(int score);

    unsigned int hiScore;
    unsigned int currScore;
    QPixmap digits[10];
    QPixmap HI = QPixmap(":sprites/HI.png");
};

#endif // SCORE_H
