#define STB_IMAGE_IMPLEMENTATION

#include "main.h"

// Initialize
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

    int width, height, comp; // Ce sont des paramètres out
    uint8_t *data = stbi_load("resources/planks_jungle.png", &width, &height, &comp, STBI_rgb);

    GLuint textureId;

    glGenTextures(1, &textureId);

    glActiveTexture(GL_TEXTURE0);
    glBindTexture(GL_TEXTURE_2D, textureId);


    // Utiliser pour le redimensionnement
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_CLAMP_TO_EDGE);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_CLAMP_TO_EDGE);

    if (!data) {
        exit(1);
    } else {
        glTexImage2D(GL_TEXTURE_2D, 0, GL_RGB8, width, height, 0, GL_RGB, GL_UNSIGNED_BYTE, data);
        stbi_image_free(data);
    }


    glEnable(GL_CULL_FACE);
    glEnable(GL_DEPTH_TEST);

    /* Loop until the user closes the window */
    while (!glfwWindowShouldClose(window)) {
        /* Render here */
        glClearColor(0.0f, 1.0f, 1.0f, 1);
        glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

        game.render(textureId);

        /* Swap front and back buffers */
        glfwSwapBuffers(window);

        /* Poll for and process events */
        glfwPollEvents();
    }

    // Free avant la mort

    game.shader->destroy();

    glDeleteTextures(1, &textureId);

    glfwTerminate();
    return 0;
}
