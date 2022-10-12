#include "Input.h"
#include "Window/Window.h"

Input::Input(Window* window)
{
	glfwSetKeyCallback(window->GetWindow(), KeyCallback);
	glfwSetCursorPosCallback(window->GetWindow(), MouseCallback);
	mousePosition.x = window->GetWidth() / 2;
	mousePosition.y = window->GetHeight() / 2;
}

Input::~Input()
{
}

bool Input::IsKeyPressed(int keycode, Window* window)
{
	int aux = glfwGetKey(window->GetWindow(), keycode);
	return aux == GLFW_PRESS;
}

bool Input::IsKeyDown(int keycode, Window* window)
{
	list<int>::iterator it = find(keysDown.begin(), keysDown.end(), keycode);
	if (it != keysDown.end())
	{
		keysDown.remove(keycode);
		return true;
	}
	return false;
}

glm::vec2 Input::GetMousePosition()
{
	return mousePosition;
}

void Input::KeyCallback(GLFWwindow* window, int key, int scancode, int action, int mods)
{
	if (action == GLFW_PRESS) keysDown.push_front(key);
	else if(action == GLFW_RELEASE) keysDown.remove(key);
}

void Input::MouseCallback(GLFWwindow* window, double posX, double posY)
{
	if (firstMouse)
	{
		mousePosition.x = posX;
		mousePosition.y = posY;
		firstMouse = false; 
	}

	float offsetPosX = posX - mousePosition.x;
	float offsetPosY = mousePosition.y - posY;   // Coordenadas en Y estan invertidas
	mousePosition.x = posX;
	mousePosition.y = posY;

	offsetPosX *= SENSITIVY;
	offsetPosY *= SENSITIVY;
}