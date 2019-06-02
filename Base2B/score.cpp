#include "score.h"

Score::Score():
    hiScore(1), currScore(1) {
    for (int i = 0; i < 10; i++) {
        std::string spritePath = ":sprites/" + std::to_string(i) + ".png";
        QPixmap sprite(QString::fromStdString(spritePath));
        digits[i] = sprite;
    }
}

void Score::increment() {
    currScore++;

}
void Score::incrementBy(int update) {
    currScore = currScore+update;
}
void Score::decrement() {
    currScore--;
}

void Score::setScore(int score){
    currScore = score;
}

// Render score from left to right. Requires FILO reading of integer
void Score::render(Renderer &renderer) {
    std::stack<int> number;
    std::stack<int> hinumber;
    unsigned int score = currScore;
    unsigned int hiscore = hiScore;
    while (score > 0) {
        number.push(score % 10);
        score = score / 10;
    }
    while (hiscore > 0) {
        hinumber.push(hiscore % 10);
        hiscore = hiscore / 10;
    }

    int length = number.size();
    for (int i = 0; i < length; i++) {
        renderer.draw(700+i*10, 20, digits[number.top()]);
        number.pop();
    }
    renderer.draw(590, 15,HI);

    int length2 = hinumber.size();
    for (int i = 0; i < length2; i++) {
        renderer.draw(630+i*10, 20, digits[hinumber.top()]);
        hinumber.pop();
    }
}
