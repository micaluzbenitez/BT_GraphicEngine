#include "BaseGame.h"

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
        cout << "Error creating the window";
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
    _window->MakeWindowContextCurrent();

    /* GLEW init */
    _renderer->InitGLEW();

    /* GLEW buffer */
    float positions[6] =
    {
        -0.5f, -0.5f,
         0.0f,  0.5f,
         0.5f, -0.5f
    };

    unsigned int buffer;
    _renderer->AssignVertexBuffer(1, buffer);
    _renderer->SetVertexBufferTarget(GL_ARRAY_BUFFER, buffer);
    _renderer->SetVertexBufferData(GL_ARRAY_BUFFER, 6 * sizeof(float), positions, GL_STATIC_DRAW);

    _renderer->EnableVertexAttribArray(0);
    _renderer->DefineVertexAttribPointer(0, 2, GL_FLOAT, GL_FALSE, sizeof(float) * 2, 0);

    return _window != nullptr;
}

void BaseGame::Update()
{
    /* Poll for and process events */
    _window->PollEvents();
}

void BaseGame::Draw()
{
    //_renderer->ClearScreen();
    _renderer->ClearScreenWithColor(1, 0, 0, 1);

    /* GLEW draw mode */
    _renderer->DrawWithoutIndexBuffer(GL_TRIANGLES, 0, 3);

    /* Swap front and back buffers */
    _renderer->SwapBuffers(_window->GetWindow());
}

void BaseGame::Deinit()
{
    _window->TerminateLibrary();
}
 