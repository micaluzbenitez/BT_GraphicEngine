#include "BaseGame/BaseGame.h"

void main()
{
	BaseGame* baseGame = new BaseGame();
	baseGame->RunBaseGame();
	delete baseGame;
}