#ifndef INC_2022_03_30_GAME_H
#define INC_2022_03_30_GAME_H

#include "main.h"
#include "Vertex.h"
#include "Object.h"
#include "Quaternion.h"
#include <vector>

class Game {
public:
   std::vector<Object> objects;

    Game(void) {};

    void initialize(void) {
        Object skull("resources/Skull.obj", "resources/Skull.mtl", "resources/Skull.jpg");
        objects.push_back(skull);
    };

    ~Game(void) {};

    void render(void);
};

#endif //INC_2022_03_30_GAME_H
