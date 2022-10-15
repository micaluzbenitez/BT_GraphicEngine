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
    shape = new Shape(renderer);

    window->InitLibrary();                              
    window->CreateWindow();
    window->MakeWindowContextCurrent();

    renderer->InitGLEW();

    shape->CreateTriangle();
    //_shape->CreateSquare();   
    shape->SetColor(glm::vec3(1,1,0)); //Amarillo listo
    shape->SetPosition(-1, 1, 0);
    shape->AttachMaterial(); // Shader

    //float deltaTime = GetCurrentTime();
    //float speed = 0.1f;
    //float speedScale = 0.005f;
    //float scale = _shape->GetScale().x;

    Begin();

    while (!window->WindowShouldClose())
    {
        renderer->ClearScreen();
        
        
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

        shape->DrawTriangle();

        //_shape->DrawSquare();
        renderer->SwapBuffers(window->GetWindow());

        window->PollEvents();

        Update();
    }

    End();

    window->TerminateLibrary();
    return 0;
}

double BaseGame::GetCurrentTime()
{
    return glfwGetTime();
}