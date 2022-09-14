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

void BaseGame::RunBaseGame()
{    
    if (Init())
    {
        while (!_window->WindowShouldClose())
        {
            Update();
            Draw();
        }
        Deinit();
    }
    else cout << "Error creating the window";
}

bool BaseGame::Init()
{
    _window = new Window();
    _renderer = new Renderer();
    _input = new Input();
    _collisionManager = new CollisionManager();
    _shape = new Shape();

    /* Initialize the library */
    _window->InitLibrary();                              

    /* Create a windowed mode window and its OpenGL context */
    _window->CreateWindow();

    /* Make the window's context current */
    _window->MakeWindowContextCurrent();

    /* GLEW init */
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
    
    /* Assign out GLEW buffer */
    unsigned int buffer;
    _renderer->AssignVertexBuffer(1, buffer);
    _renderer->SetVertexBufferTarget(GL_ARRAY_BUFFER, buffer);
    _renderer->SetVertexBufferData(GL_ARRAY_BUFFER, 6 * 2 * sizeof(float), positions, GL_STATIC_DRAW);

    /* GLEW enabled vertex attrib */
    _renderer->EnableVertexAttribArray(0);
    _renderer->DefineVertexAttribPointer(0, 2, GL_FLOAT, GL_FALSE, sizeof(float) * 2, 0);

    /* Create out index buffer object */
    unsigned int ibo;
    _renderer->AssignVertexBuffer(1, ibo);
    _renderer->SetVertexBufferTarget(GL_ELEMENT_ARRAY_BUFFER, ibo);
    _renderer->SetVertexBufferData(GL_ELEMENT_ARRAY_BUFFER, 6 * sizeof(unsigned int), indices, GL_STATIC_DRAW);
    
    /* Create shader */
    _shape->AttachMaterial();

    return _window != nullptr;
}

void BaseGame::Update()
{
    /* Poll for and process events */
    _window->PollEvents();
}

void BaseGame::Draw()
{
    _renderer->ClearScreen();
    //_renderer->ClearScreenWithColor(1, 0, 0, 1);

    /* GLEW draw mode */
    _shape->DrawWithIndexBuffer(6);

    /* Swap front and back buffers */
    _renderer->SwapBuffers(_window->GetWindow());
}

void BaseGame::Deinit()
{
    _window->TerminateLibrary();
}
 