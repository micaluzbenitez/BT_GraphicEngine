#include "BaseGame.h"

BaseGame::BaseGame()
{
    renderer = nullptr;
    window = nullptr;
    input = nullptr;
    collisionManager = nullptr;
}

BaseGame::~BaseGame()
{
    if (window != nullptr) {
        window = nullptr;
        delete window;
    }
    
    if (renderer != nullptr) {
        renderer = nullptr;
        delete renderer;
    }

    if (input != nullptr) {
        input = nullptr;
        delete input;
    }

    if (collisionManager != nullptr) {
        collisionManager = nullptr;
        delete collisionManager;
    }
}

int BaseGame::Run()
{
    window = new Window(640,480);
    renderer = new Renderer(window);

    window->InitLibrary();                              
    window->CreateWindow();
    window->MakeWindowContextCurrent();

    renderer->InitGLEW();
    Begin();

    while (!window->WindowShouldClose())
    {
        renderer->ClearScreen();   
        Update();
        renderer->SwapBuffers(window->GetWindow());
        window->PollEvents();
    }

    End();
    window->TerminateLibrary();
    return 0;
}

bool BaseGame::IsKeyPressed(int keycode)
{
    return input->IsKeyPressed(keycode, window);
}

bool BaseGame::IsKeyDown(int keycode)
{
    return input->IsKeyDown(keycode, window);
}

glm::vec2 BaseGame::GetMousePosition()
{
    return input->GetMousePosition();
}

glm::vec2 BaseGame::GetDeltaMousePosition()
{
    return input->GetDeltaMousePosition();
}

double BaseGame::GetCurrentTime()
{
    return glfwGetTime();
}