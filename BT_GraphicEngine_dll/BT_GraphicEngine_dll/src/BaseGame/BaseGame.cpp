#include "BaseGame.h"

#include <glfw3.h>
#include <iostream>

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

void BaseGame::RunBaseGame()
{
    
    if (Init())
    {

        /* Loop until the user closes the window */
        while (!_window->WindowShouldClose())
        {
            Update();
            Draw();
        }

        Deinit();
    }

    else
    {
        std::cout << "Error creating the window";
    }
}

bool BaseGame::Init()
{
    _window = new Window();
    _renderer = new Renderer();

    /* Initialize the library */
    _window->InitLibrary();                         //Preguntar si se puede poner todo adentro del constructor de window                       

    /* Create a windowed mode window and its OpenGL context */
    _window->CreateWindow();

    /* Make the window's context current */
    _window->MakeWindowContextCurrent();

    return _window != nullptr;
}

void BaseGame::Update()
{
    /* Update here */

    /* Poll for and process events */
    _window->PollEvents();
}

void BaseGame::Draw()
{
    /* Render here */
        //_renderer->ClearScreen();
    _renderer->ClearScreenWithColor(1, 0, 0, 1);

    /* Swap front and back buffers */
    _renderer->SwapBuffers(_window->GetWindow());
}

void BaseGame::Deinit()
{
    _window->TerminateLibrary();
}
