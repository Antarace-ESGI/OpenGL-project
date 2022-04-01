#include "loader.h"

void initialize(GLShader *shader) {
    shader->loadVertexShader("shaders/triangle.vs");
    shader->loadFragmentShader("shaders/triangle.fs");
    shader->create();
}

float *loadModel(size_t &vertex_count) {
    std::string objfile = "resources/bete.obj";
    tinyobj::ObjReaderConfig config;
    tinyobj::ObjReader obj;

    config.triangulate = true;

    if (!obj.ParseFromFile(objfile, config)) {
        exit(1);
    }

    vertex_count = 0;


    for (const auto &shape: obj.GetShapes()) {
        // Loop over faces(polygon)
        for (unsigned char num_face_vertice: shape.mesh.num_face_vertices) {
            auto fv = size_t(num_face_vertice); // The number of vertices per face
            vertex_count += fv;
        }
    }

    auto *vertices = new float[vertex_count * 8]();
    unsigned int i = 0;

    for (size_t shape = 0; shape < obj.GetShapes().size(); shape++) {
        // Loop over faces(polygon)
        size_t index_offset = 0;

        for (size_t face = 0; face < obj.GetShapes()[shape].mesh.num_face_vertices.size(); face++) {
            auto fv = size_t(obj.GetShapes()[shape].mesh.num_face_vertices[face]);

            // Loop over vertices in the face.
            for (size_t face_vertices = 0; face_vertices < fv; face_vertices++) {
                // access to vertex
                tinyobj::index_t idx = obj.GetShapes()[shape].mesh.indices[index_offset + face_vertices];
                tinyobj::real_t vx = obj.GetAttrib().vertices[3 * size_t(idx.vertex_index) + 0];
                tinyobj::real_t vy = obj.GetAttrib().vertices[3 * size_t(idx.vertex_index) + 1];
                tinyobj::real_t vz = obj.GetAttrib().vertices[3 * size_t(idx.vertex_index) + 2];

                // 3 positions
                vertices[i++] = vx;
                vertices[i++] = vy;
                vertices[i++] = vz;

                // 3 normals
                vertices[i++] = 0;
                vertices[i++] = 1;
                vertices[i++] = 1;

                if(idx.texcoord_index && idx.texcoord_index >= 0){
                    tinyobj::real_t tx = obj.GetAttrib().texcoords[2 * size_t(idx.vertex_index) + 0];
                    tinyobj::real_t ty = obj.GetAttrib().texcoords[2 * size_t(idx.vertex_index) + 1];

                    // 2 uv
                    vertices[i++] = tx;
                    vertices[i++] = ty;

                } else {
                    i += 2;
                }
            }

            index_offset += fv;
        }
    }

    std::cout << "Model loaded" << std::endl;

    return vertices;
}