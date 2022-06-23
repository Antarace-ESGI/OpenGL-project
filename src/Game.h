#ifndef INC_2022_03_30_GAME_H
#define INC_2022_03_30_GAME_H

#include "main.h"
#include "Vertex.h"
#include "libs/stb/stb_image.h"
#include "Quaternion.h"
#include <vector>




class Game {
public:
   std::vector<Object> objects;

    Game(void) {

        Object suzanne("resources/suzanne.obj", "resources/suzanne.mtl");
        objects.push_back(suzanne);

        
    };

    ~Game(void) {
        

    };

    void render(void);

    
};

#endif //INC_2022_03_30_GAME_H
