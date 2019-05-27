#include "life.h"
#include <iostream>
Life::Life():
    no_life(10){
    heart = QPixmap(":sprites/heart.png");
}
void Life::decrement(){
    if (no_life>0){
        no_life--;
    }
}
void Life::increment(){
    no_life++;
}

// Render score from left to right. Requires FILO reading of integer
void Life::render(Renderer &renderer) {

    for (int i = 0; i < no_life; i++) {
        renderer.draw(500+i*30, 50, heart);
    }
}

