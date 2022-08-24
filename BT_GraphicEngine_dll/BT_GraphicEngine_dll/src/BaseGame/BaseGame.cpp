#include <glew.h>
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

    /* GLEW */
    if (glewInit() != GLEW_OK)
        std::cout << "Error GLEW!" << std::endl;
    
    cout << glGetString(GL_VERSION) << endl;

    /* GLEW buffers */
    float positions[6] =
    {
        -0.5f, -0.5f,
         0.0f,  0.5f,
         0.5f, -0.5f
    };

    unsigned int buffer;
    glGenBuffers(1, &buffer);
    glBindBuffer(GL_ARRAY_BUFFER, buffer);
    glBufferData(GL_ARRAY_BUFFER, 6 * sizeof(float), positions, GL_STATIC_DRAW);

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

    /* Draw triangle */
    //glBegin(GL_TRIANGLES);
    //glVertex2f(-0.5f, -0.5f);
    //glVertex2f( 0.0f,  0.5f);
    //glVertex2f( 0.5f, -0.5f);
    //glEnd();

    /* Draw mode */
    glDrawArrays(GL_TRIANGLES, 0, 3);

    /* Swap front and back buffers */
    _renderer->SwapBuffers(_window->GetWindow());
}

void BaseGame::Deinit()
{
    _window->TerminateLibrary();
}
