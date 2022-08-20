#include "BaseGame.h"

#include <glfw3.h>

BaseGame::BaseGame()
{
    _renderer = nullptr;
    _window = nullptr;
}

BaseGame::~BaseGame()
{
    if (_window != nullptr) {
        _window = nullptr;
        delete _window;
    }
    
    if (_renderer != nullptr) {
        _renderer = nullptr;
        delete _renderer;
    }
}

bool BaseGame::Init()
{
    GLFWwindow* window;                                                // codigo de window
                                                                       // codigo de window
    /* Initialize the library */                                       // codigo de window
    if (!glfwInit())                                                   // codigo de window
        return -1;                                                     // codigo de window
                                                                       // codigo de window
    /* Create a windowed mode window and its OpenGL context */         // codigo de window
    window = glfwCreateWindow(640, 480, "Hello World", NULL, NULL);    // codigo de window
    if (!window)                                                       // codigo de window
    {                                                                  // codigo de window
        glfwTerminate();                                               // codigo de window
        return -1;                                                     // codigo de window
    }                                                                  // codigo de window

    /* Make the window's context current */         // codigo de renderizado
    glfwMakeContextCurrent(window);                 // codigo de renderizado

    /* Loop until the user closes the window */
    while (!glfwWindowShouldClose(window))
    {
        /* Render here */                           // codigo de renderizado
        glClear(GL_COLOR_BUFFER_BIT);               // codigo de renderizado
                                                    // codigo de renderizado
        /* Swap front and back buffers */           // codigo de renderizado
        glfwSwapBuffers(window);                    // codigo de renderizado

        /* Poll for and process events */
        glfwPollEvents();
    }

    glfwTerminate();
    return 0;
}
