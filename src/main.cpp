#include "main.h"

void initialize(GLShader *shader) {
    shader->loadVertexShader("shaders/triangle.vs");
    shader->loadFragmentShader("shaders/triangle.fs");
    shader->create();
}

int main() {
    GLFWwindow *window;

    /* Initialize the library */
    if (!glfwInit()) {
        return -1;
    }

    Game game;

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

    initialize(game.shader);

    glEnable(GL_CULL_FACE);
    glEnable(GL_DEPTH_TEST);

    /* Loop until the user closes the window */
    while (!glfwWindowShouldClose(window)) {
        /* Render here */
        glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

        game.render();

        /* Swap front and back buffers */
        glfwSwapBuffers(window);

        /* Poll for and process events */
        glfwPollEvents();
    }

    game.shader->destroy();

    glfwTerminate();
    return 0;
}
