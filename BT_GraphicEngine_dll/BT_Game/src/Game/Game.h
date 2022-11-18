#ifndef GAME_H
#define GAME_H

#include "BaseGame/BaseGame.h"
using namespace std;

class Game : public BaseGame
{
private:
	Shape* triangle;
	Shape* square;
	Shape* square2;
	Sprite* sprite;
	Sprite* spritesheet; 
	float time;

public:
	Game();
	~Game();

	void Begin()override;
	void Update()override;
	void End()override;
};

#endif