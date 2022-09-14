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

class DllImport BaseGame
{
private:
	Window* _window;
	Renderer* _renderer;
	Input* _input;
	CollisionManager* _collisionManager;
	Shape* _shape;

public:
	BaseGame();
	~BaseGame();
	void RunBaseGame();
	bool Init();
	void Update();
	void Draw();
	void Deinit();
};

#endif