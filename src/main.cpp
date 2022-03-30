#include "main.h"

void initialize(GLShader *shader) {
    shader->loadVertexShader("shaders/triangle.vs");
    shader->loadFragmentShader("shaders/triangle.fs");
    shader->create();
}

int main() {
    GLFWwindow *window;

    GLShader *g_triangleShader;

    /* Initialize the library */
    if (!glfwInit()) {
        return -1;
    }

    /* create a windowed mode window and its OpenGL context */
    window = glfwCreateWindow(WIDTH, HEIGHT, "Hello World", nullptr, nullptr);
    if (!window) {
        glfwTerminate();
        return -1;
    }

    /* Make the window's context current */
    glfwMakeContextCurrent(window);

    GLenum error = glewInit();

    if (error != GL_NO_ERROR) {
        std::cout << error << std::flush;
    }

    initialize(g_triangleShader);

    /* Loop until the user closes the window */
    while (!glfwWindowShouldClose(window)) {
        /* Render here */
        glClear(GL_COLOR_BUFFER_BIT);

        /*=================*/

        auto program = g_triangleShader->getProgram();
        glUseProgram(program);

        static const float triangle[] = {
                0.0, 0.5f,
                -0.5f, -0.5f,
                0.5f, -0.5f,
        };

        const size_t stride = 2 * sizeof(float);
        glVertexAttribPointer(0, 2, GL_FLOAT, GL_FALSE, stride, triangle);
        glEnableVertexAttribArray(0);

        int location = glGetAttribLocation(program, "a_position");
        glEnableVertexAttribArray(location);
        glVertexAttribPointer(location, 2, GL_FLOAT, false, sizeof(float) * 2, triangle);

        static const float colors[] = {
                0.0, 0.0, 1.0,
                0.0, 1.0, 0.0,
                1.0, 0.0, 0.0,
        };

        int color = glGetAttribLocation(program, "a_color");
        glEnableVertexAttribArray(color);
        glVertexAttribPointer(color, 3, GL_FLOAT, false, sizeof(float) * 3, colors);

        glDrawArrays(GL_TRIANGLES, 0, 3);

        /*=================*/

        /* Swap front and back buffers */
        glfwSwapBuffers(window);

        /* Poll for and process events */
        glfwPollEvents();
    }

    g_triangleShader->destroy();

    glfwTerminate();
    return 0;
}
