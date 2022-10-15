#ifndef INPUT_H
#define INPUT_H

#include <glew.h>
#include <glfw3.h>
#include <list>
#include "glm/glm.hpp"
#include "glm/gtc/matrix_transform.hpp"
#include "glm/gtc/type_ptr.hpp"
#include "Export.h"
#include "Keycodes.h"

using namespace std;

class Window;

class DllApi Input
{
private:

public:
	Input(Window* window);
	~Input();

	static bool IsKeyPressed(int keycode, Window* window);
	static bool IsKeyDown(int keycode, Window* window);

	static glm::vec2 GetMousePosition();

	static void KeyCallback(GLFWwindow* window, int key, int scancode, int action, int mods);
	static void MouseCallback(GLFWwindow* window, double xpos, double ypos);
};

#endif 