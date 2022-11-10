#include "Game.h"

Game::Game()
{
	triangle = nullptr;
    square = nullptr;
    sprite = nullptr;
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

    if (sprite != nullptr) {
        sprite = nullptr;
        delete sprite;
    }
}

void Game::Begin()
{
    triangle = new Shape(renderer);
    triangle->CreateTriangle();
    triangle->SetColor(glm::vec3(1, 1, 0));
    triangle->SetPosition(2, 0, -2);
    
    square = new Shape(renderer);
    square->CreateSquare();
    square->SetColor(glm::vec3(1, 0, 0));
    square->SetPosition(-2, 0, -2);

    sprite = new Sprite(renderer, "res/Silver.png");
    sprite->SetColor(glm::vec3(1, 1, 1));
    sprite->SetPosition(0, 0, -2);
}

void Game::Update()
{
    // Input
    //if (IsKeyPressed(KEY_W)) shape->Translate(0,  0.1f, 0);
    //if (IsKeyPressed(KEY_S)) shape->Translate(0, -0.1f, 0);
    //if (IsKeyPressed(KEY_A)) shape->Translate(-0.1f, 0, 0);
    //if (IsKeyPressed(KEY_D)) shape->Translate( 0.1f, 0, 0);

    square->Draw();   
    triangle->Draw();
    sprite->Draw();
}

void Game::End()
{
}