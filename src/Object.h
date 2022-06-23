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
    GLuint textureId;

    Object(std::string obj_file, std::string mtl_file, char const * texture_file) {
        this->vertices = loadModel(this->vertex_count, obj_file, mtl_file);
        this->shader = new GLShader;
        this->rotation = Quaternion::to_quaternion(0.0f, 0.0f, 0.0f);

        initialize(shader);

        glGenTextures(1, &textureId);
        glActiveTexture(GL_TEXTURE0);
        glBindTexture(GL_TEXTURE_2D, textureId);

        // Utiliser pour le redimensionnement
        glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
        glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);
        glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_CLAMP_TO_EDGE);
        glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_CLAMP_TO_EDGE);

        int width, height, comp; // Ce sont des paramètres out
        uint8_t *data = stbi_load(texture_file, &width, &height, &comp, STBI_rgb);

        if (!data) {
            exit(1);
        } else {
            glTexImage2D(GL_TEXTURE_2D, 0, GL_RGB8, width, height, 0, GL_RGB, GL_UNSIGNED_BYTE, data);
            stbi_image_free(data);
        }
    };

    ~Object(void) {
        delete this->vertices; // Free vertices
        shader->destroy();
        glDeleteTextures(1, &textureId);
    };

    void render();

    size_t vertex_count = 0;
    float *vertices;

    const float ASPECT_RATIO = WIDTH / HEIGHT;
    const float Z_NEAR = 0.1f;
    const float Z_FAR = 100.f;
    const float FOV_Y = 45.f * M_PI / 180.f;
    const float FOCAL_DISTANCE = 1.f / tanf(FOV_Y / 2.f);
};

#endif //INC_2022_03_30_OBJECT_H
