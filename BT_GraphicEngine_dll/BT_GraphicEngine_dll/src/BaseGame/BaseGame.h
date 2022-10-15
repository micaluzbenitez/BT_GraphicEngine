#ifndef BASEGAME_H
#define BASEGAME_H

#include <glew.h>
#include <glfw3.h>
#include <iostream>
#include "Window/Window.h"
#include "Renderer/Renderer.h"
#include "Input/Input.h"
#include "CollisionManager/CollisionManager.h"
#include "Shape/Shape.h" // --> esto despues no iria, se llamaria desde el .exe
#include "Export.h"
using namespace std;

class DllApi BaseGame
{
private:
	Window* window;
	Input* input;
	CollisionManager* collisionManager;

protected:
	Renderer* renderer;

public:
	BaseGame();
	~BaseGame();
	int Run();

	virtual void Begin() = 0;
	virtual void Update() = 0;
	virtual void End() = 0;

	bool IsKeyPressed(int keycode);
	bool IsKeyDown(int keycode);
	glm::vec2 GetMousePosition();
	glm::vec2 GetDeltaMousePosition();
	double GetCurrentTime();
};

#endif