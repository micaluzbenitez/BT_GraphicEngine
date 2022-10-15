#ifndef GAME_H
#define GAME_H

#include "BaseGame/BaseGame.h"
using namespace std;

class Game : public BaseGame
{
private:
	Shape* shape;

	float deltaTime = 0;
	float speed = 0;
	float speedScale = 0;
	float scale = 0;

public:
	Game();
	~Game();

	void Begin()override;
	void Update()override;
	void End()override;
};

#endif