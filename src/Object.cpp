#include "Object.h"

// Render loop
void Object::render(GLuint textureId) {
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

    int vertexNormal = glGetAttribLocation(program,"a_normal");
    glVertexAttribPointer(vertexNormal, 3, GL_FLOAT,false, stride, mesh->normal);
    glEnableVertexAttribArray(vertexNormal);

    glActiveTexture(GL_TEXTURE0);
    glBindTexture(GL_TEXTURE_2D, textureId);

    auto time = (float) glfwGetTime();

    int time_index = glGetUniformLocation(program, "u_time");
    glUniform1f(time_index, time);

    // Matrices in OpenGL are defined in columns
    this->rotation = this->rotation * Quaternion::to_quaternion(0.03, 0.03, 0.03);
    
    float *rotation_matrix = this->rotation.to_rotation_matrix(0,-15,-75);

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
