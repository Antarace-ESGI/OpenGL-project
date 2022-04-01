#ifndef INC_2022_03_30_VERTEX_H
#define INC_2022_03_30_VERTEX_H

struct Vertex {
public:
    float position[3];
    float normal[3];
    float uv[2];

    Vertex(float x, float y, float z) {
        this->position[0] = x;
        this->position[1] = y;
        this->position[2] = z;
    }
};

#endif //INC_2022_03_30_VERTEX_H
