#include "BaseGame/BaseGame.h"

void main()
{
	BaseGame* baseGame = new BaseGame();
	baseGame->Init();
	delete baseGame;
}