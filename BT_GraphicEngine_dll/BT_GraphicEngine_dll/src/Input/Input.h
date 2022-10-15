#ifndef INPUT_H
#define INPUT_H

#include <glew.h>
#include <glfw3.h>
#include <list>
#include "glm/glm.hpp"
#include "glm/gtc/matrix_transform.hpp"
#include "glm/gtc/type_ptr.hpp"
#include "Export.h"
using namespace std;

class Window;

class DllApi Input
{
private:
	list<int> keysDown;
	glm::vec2 mousePosition;
	bool firstMouse;
	const float SENSITIVY = 0.1f;

public:
	/*
	Input(Window* window);
	~Input();

	bool IsKeyPressed(int keycode, Window* window);
	bool IsKeyDown(int keycode, Window* window);

	glm::vec2 GetMousePosition();

	void KeyCallback(GLFWwindow* window, int key, int scancode, int action, int mods);
	void MouseCallback(GLFWwindow* window, double posX, double posY);
	*/
};

#endif 