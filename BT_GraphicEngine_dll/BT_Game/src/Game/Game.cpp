#include "Game.h"

Game::Game()
{
	triangle = nullptr;
    square = nullptr;
}

Game::~Game()
{
    if (triangle != nullptr) {
        triangle = nullptr;
        delete triangle;
    }

    if (square != nullptr) {
        square = nullptr;
        delete square;
    }
}

void Game::Begin()
{
    triangle = new Shape(renderer);
    triangle->CreateTriangle();
    triangle->SetColor(glm::vec3(1, 1, 0));
    triangle->SetPosition(1, 0, -2);
    triangle->AttachMaterial(); // Shader    

    square = new Shape(renderer);
    square->CreateSquare();
    square->SetColor(glm::vec3(1, 0, 0));
    square->SetPosition(-1, 0, -2);
    square->AttachMaterial(); // Shader
}

void Game::Update()
{
    // Input
    //if (IsKeyPressed(KEY_W)) shape->Translate(0,  0.1f, 0);
    //if (IsKeyPressed(KEY_S)) shape->Translate(0, -0.1f, 0);
    //if (IsKeyPressed(KEY_A)) shape->Translate(-0.1f, 0, 0);
    //if (IsKeyPressed(KEY_D)) shape->Translate( 0.1f, 0, 0);

    square->DrawSquare();
    triangle->DrawTriangle();
}

void Game::End()
{
}