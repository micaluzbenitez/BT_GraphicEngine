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
    _window = new Window();
    _renderer = new Renderer();                                           
                                                                     
    /* Initialize the library */                                     
    _window->InitLibrary();                                                
                                                                    
    /* Create a windowed mode window and its OpenGL context */      
    _window->CreateWindow();

    /* Make the window's context current */         
    glfwMakeContextCurrent(_window->GetWindow());   // codigo de renderizado (preguntar)

    /* Loop until the user closes the window */
    while (!_window->WindowClose(_window->GetWindow()))
    {
        /* Render here */                           
        glClear(GL_COLOR_BUFFER_BIT);               // codigo de renderizado
                                                    
        /* Swap front and back buffers */           
        glfwSwapBuffers(_window->GetWindow());      // codigo de renderizado

        /* Poll for and process events */
        _window->PollEvents();
    }

    _window->TerminateLibrary();
    return 0;
}
