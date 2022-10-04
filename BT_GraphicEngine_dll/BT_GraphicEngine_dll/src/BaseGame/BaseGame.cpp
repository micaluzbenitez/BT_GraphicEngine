#include "BaseGame.h"

BaseGame::BaseGame()
{
    _renderer = nullptr;
    _window = nullptr;
    _input = nullptr;
    _collisionManager = nullptr;
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

    if (_input != nullptr) {
        _input = nullptr;
        delete _input;
    }

    if (_collisionManager != nullptr) {
        _collisionManager = nullptr;
        delete _collisionManager;
    }
}

int BaseGame::Init()
{
    _window = new Window();
    _renderer = new Renderer();
    _shape = new Shape();

    _window->InitLibrary();                              
    _window->CreateWindow();
    _window->MakeWindowContextCurrent();

    _renderer->InitGLEW();

    //_shape->CreateTriangle();
    _shape->CreateSquare();    
    //_shape->AttachMaterial(); // Shader

    while (!_window->WindowShouldClose())
    {
        _renderer->ClearScreen();
        //_shape->DrawTriangle();
        _shape->DrawSquare();
        _renderer->SwapBuffers(_window->GetWindow());

        _window->PollEvents();
    }

    _window->TerminateLibrary();
    return 0;
}