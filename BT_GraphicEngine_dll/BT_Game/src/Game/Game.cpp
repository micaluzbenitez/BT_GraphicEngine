#include "Game.h"
#include "Timer/Timer.h"

Game::Game()
{
	triangle = nullptr;
    square = nullptr;
    square2 = nullptr;
    sprite = nullptr;
    spritesheet = nullptr;
    time = 0;
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

    if (square2 != nullptr) {
        square2 = nullptr;
        delete square2;
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
    //triangle = new Shape(renderer);
    //triangle->CreateTriangle();
    //triangle->SetColor(glm::vec3(1, 1, 0));
    //triangle->SetPosition(1.5, 1, -1);
    
    square = new Shape(renderer);
    square->CreateSquare();
    square->SetColor(glm::vec3(1, 0, 0));
    square->SetPosition(-1.5, 0, -1);
    square->SetCollider(true);
    square->SetMoveable(true);

    square2 = new Shape(renderer);
    square2->CreateSquare();
    square2->SetColor(glm::vec3(1, 1, 0));
    square2->SetPosition(1.5, 0, -1);
    square2->SetCollider(true);
    square2->SetMoveable(true);

    //sprite = new Sprite(renderer, "res/Silver.png");
    //sprite->SetColor(glm::vec3(1, 1, 1));
    //sprite->SetPosition(1.5, -1, -1);
    
    //spritesheet = new Sprite(renderer, "res/anim.png");
    //spritesheet->SetColor(glm::vec3(1, 1, 1));
    //spritesheet->SetPosition(-1.5, -1, -1);
    //spritesheet->CreateAnimation(1, 4, 1);
}

void Game::Update()
{
    // Input
    if (IsKeyPressed(KEY_W)) square->Translate(0,  0.1f, 0);
    if (IsKeyPressed(KEY_S)) square->Translate(0, -0.1f, 0);
    if (IsKeyPressed(KEY_A)) square->Translate(-0.1f, 0, 0);
    if (IsKeyPressed(KEY_D)) square->Translate( 0.1f, 0, 0);

    //triangle->Rotate(0, 0, Timer::GetDeltaTime());
    //square->Rotate(0, 0, Timer::GetDeltaTime());

    CollisionManager::CollisionUpdate(square, square2);
    square->Draw();
    square2->Draw();

    //triangle->Draw();
    //sprite->Draw();
    
    //spritesheet->UpdateAnimation();
    //spritesheet->Draw();
}

void Game::End()
{
}