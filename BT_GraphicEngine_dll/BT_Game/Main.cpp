#include "BaseGame.h"

void main()
{
	BaseGame* baseGame = new BaseGame();
	baseGame->Init();
	delete baseGame;
}