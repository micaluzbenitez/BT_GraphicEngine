#ifndef BASEGAME_H
#define BASEGAME_H

#include <glew.h>
#include <glfw3.h>
#include <iostream>
#include "Window/Window.h"
#include "Renderer/Renderer.h"
#include "Export.h"
using namespace std;

class DllImport BaseGame
{
private:
	Window* _window;
	Renderer* _renderer;
	Material* _material;

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