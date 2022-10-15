#ifndef GAME_H
#define GAME_H

#include "BaseGame/BaseGame.h"
using namespace std;

class Game : public BaseGame
{
private:
	Shape* shape;

public:
	void Begin()override;
	void Update()override;
	void End()override;
};

#endif