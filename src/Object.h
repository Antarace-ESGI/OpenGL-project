#ifndef INC_2022_03_30_OBJECT_H
#define INC_2022_03_30_OBJECT_H

#include "main.h"
#include "Vertex.h"
#include "libs/stb/stb_image.h"
#include "Quaternion.h"

class Object {
public:
    GLShader *shader;
    Quaternion rotation;

    Object(std::string objfile, std::string mtlfile) {
        this->vertices = loadModel(this->vertex_count, objfile, mtlfile);
        this->shader = new GLShader;
        this->rotation = Quaternion::to_quaternion(0.0f, 0.0f, 0.0f);

        
    };

    ~Object(void) {
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

#endif //INC_2022_03_30_OBJECT_H
