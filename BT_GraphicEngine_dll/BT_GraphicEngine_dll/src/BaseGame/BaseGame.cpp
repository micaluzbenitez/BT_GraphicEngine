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
    _input = new Input();
    _collisionManager = new CollisionManager();
    _shape = new Shape();

    _window->InitLibrary();                              
    _window->CreateWindow();
    _window->MakeWindowContextCurrent();

    _renderer->InitGLEW();

    /* GLEW buffer */
    float positions[] =
    {
        -0.5f, -0.5f,  // 0
         0.5f, -0.5f,  // 1
         0.5f,  0.5f,  // 2
        -0.5f,  0.5f   // 3
    };

    /* Index buffer */
    unsigned int indices[] =
    {
        0, 1, 2,
        2, 3, 0
    };
    
    unsigned int buffer; // Vertex buffer
    _renderer->BindBuffer(1, buffer, GL_ARRAY_BUFFER, 6 * 2 * sizeof(float), positions, GL_STATIC_DRAW);
    _renderer->EnableVertexAttributes(0, 2, GL_FLOAT, GL_FALSE, sizeof(float) * 2, 0);

    unsigned int ibo; // Index buffer
    _renderer->BindBuffer(1, ibo, GL_ELEMENT_ARRAY_BUFFER, 6 * sizeof(unsigned int), indices, GL_STATIC_DRAW);
    
    _shape->AttachMaterial(); // Shader

    while (!_window->WindowShouldClose())
    {
        _renderer->ClearScreen();
        _shape->DrawWithIndexBuffer(6);
        _renderer->SwapBuffers(_window->GetWindow());

        _window->PollEvents();
    }

    _window->TerminateLibrary();
    return 0;
}