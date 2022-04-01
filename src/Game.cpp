#include "Game.h"
#include "DragonData.h"

void Game::render() {
    auto program = this->shader->getProgram();
    glUseProgram(program);

    auto* mesh = reinterpret_cast<Vertex *>(DragonVertices);

    int location = glGetAttribLocation(program, "a_position");
    glEnableVertexAttribArray(location);
    glVertexAttribPointer(location, 2, GL_FLOAT, false, sizeof(float) * 2, mesh->position);

    static const float colors[] = {
            0.0, 0.0, 1.0,
            0.0, 1.0, 0.0,
            1.0, 0.0, 0.0,
    };

    int color = glGetAttribLocation(program, "a_color");
    glEnableVertexAttribArray(color);
    glVertexAttribPointer(color, 3, GL_FLOAT, false, sizeof(float) * 3, mesh->normal);

    auto time = (float) glfwGetTime();

    int time_index = glGetUniformLocation(program, "u_time");
    glUniform1f(time_index, time);

    // Matrices in OpenGL are defined in columns
    float rotation_matrix[16] = {
            cosf(time), sinf(time), 0, 1, // 1st column
            -sinf(time), cosf(time), 0, 0, // 2nd column
            0, 0, 1 ,0,
            0, 0, -10 /* Move triangle back */, 1
    };

    const auto rotation_index = glGetUniformLocation(program, "u_rotation");
    glUniformMatrix4fv(rotation_index, 1, GL_FALSE, rotation_matrix);

    float projection_matrix[16] = {
            FOCAL_DISTANCE / ASPECT_RATIO, 0, 0, 0,
            0, FOCAL_DISTANCE, 0, 0,
            0, 0, -Z_FAR / (Z_FAR - Z_NEAR), -1,
            0, 0, -Z_FAR * Z_NEAR / (Z_FAR - Z_NEAR), 0
    };

    const auto projection_index = glGetUniformLocation(program, "u_projection");
    glUniformMatrix4fv(projection_index, 1, GL_FALSE, projection_matrix);

    const size_t dragon_byte_size = sizeof(DragonVertices);
    const size_t vertex_count = dragon_byte_size / sizeof(Vertex);
    glDrawArrays(GL_TRIANGLES, 0, vertex_count);
}
