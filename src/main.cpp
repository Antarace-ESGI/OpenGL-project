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

    // TODO : init texture ici ->

    // resources/planks.jpg
    // init texture avec image
    // Crée un object pour stocker la texture
    // Prier pour que ça marche

    /*std::ifstream texture_file;
    texture_file.open("resources/planks.jpg", std::ios::out | std::ios::app | std::ios::binary);
    texture_file.seekg(0, std::ios::end);
    std::ifstream::pos_type endFile = texture_file.tellg();*/

    initialize(game.shader);

   /* int width, height, comp; // Ce sont des paramètres out (cf. ligne 145 stb_image.h pour la doc)
    uint8_t *data = stbi_load("resources/planks.jpg", &width, &height, &comp, STBI_rgb);

    if (!data) {
        exit(1);
    }

    glTexImage2D(GL_TEXTURE_2D, 0, GL_RGB8, width, height, 0, GL_RGB, GL_UNSIGNED_BYTE, data);

    // TODO: Déplacer ceci dans loader.cpp
    GLuint textureId;
    glGenTextures(1, &textureId);

    GL_ACTIVE_TEXTURE(GL_TEXTURE0);
    glBindTexture(GL_TEXTURE_2D, textureId); // <- c pas comment ça marche pour l'instant

    // TODO: Penser à inclure ça quelque part
    //stbi_image_free(data);*/

    glEnable(GL_CULL_FACE);
    glEnable(GL_DEPTH_TEST);

    /* Loop until the user closes the window */
    while (!glfwWindowShouldClose(window)) {
        /* Render here */
        glClearColor(1.0f, 1.0f, 1.0f, 1);
        glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

        game.render();

        /* Swap front and back buffers */
        glfwSwapBuffers(window);

        /* Poll for and process events */
        glfwPollEvents();
    }

    game.shader->destroy();
    //glDeleteTextures(1, &textureId);

    glfwTerminate();
    return 0;
}
