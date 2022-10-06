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
    _window = new Window(640,480);
    _renderer = new Renderer(_window);
    _shape = new Shape(_renderer);

    _window->InitLibrary();                              
    _window->CreateWindow();
    _window->MakeWindowContextCurrent();

    _renderer->InitGLEW();

    _shape->CreateTriangle();
    //_shape->CreateSquare();    
    _shape->SetColor(glm::vec3(0.1f, 0.8f, 1.0f));
    _shape->AttachMaterial(); // Shader

    float time = 0;

    while (!_window->WindowShouldClose())
    {
        _renderer->ClearScreen();
        if (time > 1) time = 0;
        time += glfwGetTime();

        //_shape->Scale(2 * time, 2 * time, 2 * time);
        _shape->Rotate(time, time, 0);
        //_shape->Translate(0.5, 0.5f, 0.5f);



        _shape->SetColor(glm::vec3(time, 0, 0));

        _shape->DrawTriangle();

        //_shape->DrawSquare();
        _renderer->SwapBuffers(_window->GetWindow());

        _window->PollEvents();
    }

    _window->TerminateLibrary();
    return 0;
}