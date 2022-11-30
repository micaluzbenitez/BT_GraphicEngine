#include "Game.h"
#include "Timer/Timer.h"

Game::Game()
{
	triangle = nullptr;
    square = nullptr;
    square2 = nullptr;
    sprite = nullptr;
    spritesheet = nullptr;
    spritesheet2 = nullptr;
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

    if (spritesheet2 != nullptr) {
        spritesheet2 = nullptr;
        delete spritesheet2;
    }
}

void Game::Begin()
{
    //triangle = new Shape(renderer);
    //triangle->CreateTriangle();
    //triangle->SetColor(glm::vec3(1, 1, 0));
    //triangle->SetPosition(1.5, 1, -1);
    
    square = new Sprite(renderer, "res/Silver.png");
    square->SetColor(glm::vec3(1, 1, 1));
    square->SetPosition(-15, 0, -1);//fixear el movimiento a pixeles
    square->SetScale(10, 10, 10);
    square->SetCollider(true);
    square->SetMoveable(false);
    
    //square2 = new Shape(renderer);
    //square2->CreateSquare();
    //square2->SetColor(glm::vec3(1, 1, 0));
    //square2->SetPosition(1.5, 0, -1);
    //square2->SetScale(4, 4, 4);
    //square2->SetCollider(true);
    //square2->SetMoveable(false);

    sprite = new Sprite(renderer, "res/anim3.png");
    sprite->CreateAnimation(1, 5, 1);
    
    sprite->SetColor(glm::vec3(1, 1, 1));
    sprite->SetPosition(1.5, -1, -1);
    sprite->SetScale(5, 5, 5);
    sprite->SetCollider(true);
    sprite->SetMoveable(false);
    
    //spritesheet = new Sprite(renderer, "res/anim.png");
    //spritesheet->SetColor(glm::vec3(1, 1, 1));
    //spritesheet->SetPosition(-1.5, -1, 13);
    //spritesheet->CreateAnimation(1, 4, 1);
    //spritesheet->SetCollider(true);
    //spritesheet->SetMoveable(false);
    
    //spritesheet2 = new Sprite(renderer, "res/anim2.png");
    //spritesheet2->SetColor(glm::vec3(1, 1, 1));
    //spritesheet2->SetPosition(1.5, -1, 13);
    //spritesheet2->CreateAnimation(1, 14, 1);
}

void Game::Update()
{
    // Input
    if (IsKeyPressed(KEY_W)) sprite->Translate(0,  0.1f, 0);
    if (IsKeyPressed(KEY_S)) sprite->Translate(0, -0.1f, 0);
    if (IsKeyPressed(KEY_A)) sprite->Translate(-0.1f, 0, 0);
    if (IsKeyPressed(KEY_D)) sprite->Translate( 0.1f, 0, 0);

    //triangle->Rotate(0, 0, Timer::GetDeltaTime());
    //square->Rotate(0, 0, Timer::GetDeltaTime());

    CollisionManager::CollisionUpdate(sprite, square );
    square->Draw();
    //square2->Draw();

    //triangle->Draw();
    //sprite->Draw();
    
    sprite->UpdateAnimation();
    sprite->Draw();
    
    //spritesheet2->UpdateAnimation();
    //spritesheet2->Draw();
}

void Game::End()
{
}