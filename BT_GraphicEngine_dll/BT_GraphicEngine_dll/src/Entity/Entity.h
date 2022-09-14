#ifndef ENTITY_H
#define ENTITY_H

#include <glew.h>
#include <glfw3.h>
#include "Renderer/Renderer.h"
#include "Export.h"
using namespace std;

class DllImport Entity //Quizas sea abstracta
{
private:
	Renderer* renderer;
	/*
	5 matrices
		rotacion x
		rotacion y
		rotacion z
		posicion
		escala
	*/
public:
	Entity();
	~Entity();
	/*
	setters de todo
	getters de todo
	*/
	virtual void Draw(Renderer* renderer, GLsizei vertices) = 0;
	virtual void DrawWithIndexBuffer(Renderer* renderer, GLsizei indices) = 0;
};

#endif