#ifndef INC_2022_03_30_GAME_H
#define INC_2022_03_30_GAME_H

#include "main.h"

struct Vertex {
    float position[3];
    float normal[3];
    float uv[2];
};

class Game {
public:
    GLShader* shader;

    void render();

    const float ASPECT_RATIO = WIDTH / HEIGHT;
    const float Z_NEAR = 0.1f;
    const float Z_FAR = 100.f;
    const float FOV_Y = 45.f * M_PI / 180.f;
    const float FOCAL_DISTANCE = 1.f / tanf(FOV_Y / 2.f);
};

#endif //INC_2022_03_30_GAME_H
