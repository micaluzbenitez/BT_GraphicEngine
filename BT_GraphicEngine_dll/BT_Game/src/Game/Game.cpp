#include "Game.h"

Game::Game()
{
	triangle = nullptr;
    square = nullptr;
    sprite = nullptr;
    spritesheet = nullptr;
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

    if (spritesheet != nullptr) {
        spritesheet = nullptr;
        delete spritesheet;
    }
}

void Game::Begin()
{
    triangle = new Shape(renderer);
    triangle->CreateTriangle();
    triangle->SetColor(glm::vec3(1, 1, 0));
    triangle->SetPosition(1.5, 1, -1);
    
    square = new Shape(renderer);
    square->CreateSquare();
    square->SetColor(glm::vec3(1, 0, 0));
    square->SetPosition(-1.5, 1, -1);

    sprite = new Sprite(renderer, "res/Silver.png");
    sprite->SetColor(glm::vec3(1, 1, 1));
    sprite->SetPosition(1.5, -1, -1);

    spritesheet = new Sprite(renderer, "res/anim.png");
    spritesheet->SetColor(glm::vec3(1, 1, 1));
    spritesheet->SetPosition(-1.5, -1, -1);
    spritesheet->CreateAnimation(1, 4, 1);
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

    spritesheet->UpdateAnimation();
    spritesheet->Draw();
}

void Game::End()
{
}