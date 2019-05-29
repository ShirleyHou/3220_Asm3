#include "entityfactory.h"

EntityFactory::EntityFactory() {

}

EntityFactory::~EntityFactory() {

}

void EntityFactory::setVelocity(int velocity) {
    this->velocity = velocity;
}

int EntityFactory::getVelocity() {
    return velocity;
}

std::unique_ptr<Entity> EntityFactory::getEntity(std::string name) {
    if (name == "bird") {
        Coordinate coordinate(800, 160, 450);
        auto randomBird = std::make_unique<Bird>(coordinate, velocity);
        randomBird->randomiseHeight();
        return std::move(randomBird);
    } else if (name == "cactus") {
        Coordinate coordinate(800, 150, 450);
        auto randomCactus = std::make_unique<Cactus>(coordinate, velocity);
        randomCactus->randomiseSprite();
        return std::move(randomCactus);
    } else if (name == "cloud") {
        Coordinate coordinate(800, 210, 450);
        auto randomCloud = std::make_unique<Cloud>(coordinate, velocity / 2);
        randomCloud->randomiseHeight();
        return std::move(randomCloud);
    } else if (name=="flag"){
        Coordinate coordinate(800, 160, 450);
        auto levelflag = std::make_unique<Flag>(coordinate, velocity);

        return std::move(levelflag);
    }else if(name=="heart"){
        Coordinate coordinate(800, 160, 450);
        auto heart = std::make_unique<Heart>(coordinate, velocity);
        return std::move(heart);
    }
}
