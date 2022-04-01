#ifndef INC_2022_03_30_GAME_H
#define INC_2022_03_30_GAME_H

#include "main.h"

class Game {
public:
    GLShader* shader;

    void render();

    const float ASPECT_RATIO = WIDTH / HEIGHT;
    const float Z_NEAR = 0.1f;
    const float Z_FAR = 100;
    const float FOV_Y = 45 * M_PI / 180;
    const float FOCAL_DISTANCE = 1 / tanf(FOV_Y / 2);
};


#endif //INC_2022_03_30_GAME_H
