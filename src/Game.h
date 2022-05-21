#ifndef INC_2022_03_30_GAME_H
#define INC_2022_03_30_GAME_H

#include "main.h"
#include "Vertex.h"
#include "libs/stb/stb_image.h"

class Game {
public:
    GLShader *shader;

    Game(void) {
        this->vertices = loadModel(this->vertex_count);
        this->shader = new GLShader;
    };

    ~Game(void) {
        delete this->vertices; // Free vertices
    };

    void render(GLuint textureId);

    size_t vertex_count = 0;
    float *vertices;

    const float ASPECT_RATIO = WIDTH / HEIGHT;
    const float Z_NEAR = 0.1f;
    const float Z_FAR = 100.f;
    const float FOV_Y = 45.f * M_PI / 180.f;
    const float FOCAL_DISTANCE = 1.f / tanf(FOV_Y / 2.f);
};

#endif //INC_2022_03_30_GAME_H
