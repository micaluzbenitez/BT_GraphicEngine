#include "Game.h"

Game::Game()
{
	shape = nullptr;
}

Game::~Game()
{
    if (shape != nullptr) {
        shape = nullptr;
        delete shape;
    }
}

void Game::Begin()
{
    shape = new Shape(renderer);
    
    shape->CreateTriangle();
    //_shape->CreateSquare();   
    shape->SetColor(glm::vec3(1, 1, 0)); //Amarillo listo
    shape->SetPosition(-1, 1, 0);
    shape->AttachMaterial(); // Shader

    deltaTime = GetCurrentTime();
    speed = 0.1f;
    speedScale = 0.005f;
    scale = shape->GetScale().x;
}

void Game::Update()
{
    //_shape->Scale(2 * time, 2 * time, 2 * time);
    //_shape->Rotate(time, time, time);
    //cout << _shape->GetPosition().x << endl;

    if (shape->GetPosition().x < 4)
    {
        shape->Translate(deltaTime * speed, 0, 0);
        
        shape->Scale(scale - speedScale, scale - speedScale, scale - speedScale);
        
        //cout << _shape->GetScale().x << endl;
    }
    else
    {
        shape->SetPosition(-1,1,0);
        shape->SetScale(1, 1, 1);
        scale = 1;
    }

    //triangulo amarillo arriba izquierda a arriba a la derecha achicandose

    //_shape->SetColor(glm::vec3(time, 0, 0));

    shape->DrawTriangle();
    //_shape->DrawSquare();
}

void Game::End()
{
}