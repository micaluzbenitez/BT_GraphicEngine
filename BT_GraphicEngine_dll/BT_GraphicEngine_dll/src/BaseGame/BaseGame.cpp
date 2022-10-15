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

int BaseGame::Run()
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
    _shape->SetColor(glm::vec3(1,1,0)); //Amarillo listo
    _shape->SetPosition(-1, 1, 0);
    _shape->AttachMaterial(); // Shader

    //float deltaTime = GetCurrentTime();
    //float speed = 0.1f;
    //float speedScale = 0.005f;
    //float scale = _shape->GetScale().x;

    Begin();

    while (!_window->WindowShouldClose())
    {
        _renderer->ClearScreen();
        
        
        //_shape->Scale(2 * time, 2 * time, 2 * time);
        //_shape->Rotate(time, time, time);
        //cout << _shape->GetPosition().x << endl;
        
        //if (_shape->GetPosition().x < 4)
        //{
        //    _shape->Translate(deltaTime * speed, 0, 0);
        //    
        //    _shape->Scale(scale - speedScale, scale - speedScale, scale - speedScale);
        //    
        //    //cout << _shape->GetScale().x << endl;
        //}
        //else
        //{
        //    _shape->SetPosition(-1,1,0);
        //    _shape->SetScale(1, 1, 1);
        //    scale = 1;
        //}


        //triangulo amarillo arriba izquierda a arriba a la derecha achicandose

        //_shape->SetColor(glm::vec3(time, 0, 0));

        _shape->DrawTriangle();

        //_shape->DrawSquare();
        _renderer->SwapBuffers(_window->GetWindow());

        _window->PollEvents();

        Update();
    }

    End();

    _window->TerminateLibrary();
    return 0;
}

double BaseGame::GetCurrentTime()
{
    return glfwGetTime();
}