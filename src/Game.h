#ifndef INC_2022_03_30_GAME_H
#define INC_2022_03_30_GAME_H

#include "Object.h"
#include "main.h"

class Game {
public:
    std::vector<Object*> objects;

    Game(void) {};

    void initialize(void) {
        Object *skull = new Object("resources/Skull.obj", "resources/Skull.mtl", "resources/Skull.jpg");
        objects.push_back(skull);
        skull->tx = 15;
        skull->ty = -15;
        skull->tz = -75;
        skull->rz = 0.01;

        Object *suzanne = new Object("resources/suzanne.obj", "resources/suzanne.mtl", "resources/Skull.jpg");
        suzanne->tx = -10;
        suzanne->ty = 0;
        suzanne->tz = -20;
        suzanne->ry = 0.01;
        objects.push_back(suzanne);
    };

    ~Game(void) {};

    void render(void);
};

#endif //INC_2022_03_30_GAME_H
