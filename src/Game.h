#ifndef INC_2022_03_30_GAME_H
#define INC_2022_03_30_GAME_H

#include "Object.h"
#include "main.h"



class Game {
public:
    std::vector<Object*> objects;

    float tournestp = 0;

    Game(void) {};

    void initialize(void) {
        Object *skull = new Object("resources/Skull.obj", "resources/Skull.mtl", "resources/Skull.jpg");
        objects.push_back(skull);
        skull->tx = 0;
        skull->ty = -22;
        skull->tz = -65;
        skull->ry = -0.003;

        Object *suzanne = new Object("resources/suzanne.obj", "resources/suzanne.mtl", "resources/Skull.jpg");
        suzanne->tx = -10;
        suzanne->tz = -65;
        suzanne->ry = -0.03;
        suzanne->ty = 0;
        objects.push_back(suzanne);

        Object *suzanne2 = new Object("resources/suzanne.obj", "resources/suzanne.mtl", "resources/Skull.jpg");
        suzanne2->tx = -10;
        suzanne2->tz = -65;
        suzanne2->ry = -0.03;
        suzanne2->ty = 0;
        objects.push_back(suzanne2);



    };

    ~Game(void) {};

    void render(void);
};

#endif //INC_2022_03_30_GAME_H
