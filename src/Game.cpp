#include "Game.h"

// Render loop
void Game::render(GLuint textureId) {
    auto program = this->shader->getProgram();
    glUseProgram(program);
    auto *mesh = reinterpret_cast<Vertex *>(this->vertices);

    const int stride = sizeof(Vertex);

    int location = glGetAttribLocation(program, "a_position");
    glEnableVertexAttribArray(location);
    glVertexAttribPointer(location, 3, GL_FLOAT, false, stride, mesh->position);

    int texLocation = glGetAttribLocation(program, "a_texcoords");
    glVertexAttribPointer(texLocation, 2, GL_FLOAT, false, stride, mesh->uv);
    glEnableVertexAttribArray(texLocation);

    glActiveTexture(GL_TEXTURE0);
    glBindTexture(GL_TEXTURE_2D, textureId);

    auto time = (float) glfwGetTime();

    int time_index = glGetUniformLocation(program, "u_time");
    glUniform1f(time_index, time);

    // Matrices in OpenGL are defined in columns
    this->rotation.add_euler(0.0, 0.1, 0);
    float* euler = rotation.to_euler();
    printf("%f, %f, %f\n", euler[0], euler[1], euler[2]);
    float *rotation_matrix = this->rotation.to_rotation_matrix();

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

    glDrawArrays(GL_TRIANGLES, 0, (int) this->vertex_count);

    int uvLocation = glGetUniformLocation(program, "u_sampler");
    glUniform1i(uvLocation, 0); // Canal de la texture, correspond à GL_TEXTURE0
}
