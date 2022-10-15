#include "Input.h"
#include "Window/Window.h"


std::list<int> currentKeysDown;
glm::vec2 mousePosition;
glm::vec2 deltaMousePosition;
bool firstMouse = false;
const float sensitivity = 0.1f;


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
	std::list<int>::iterator it = find(currentKeysDown.begin(), currentKeysDown.end(), keycode);
	if (it != currentKeysDown.end())
	{
		currentKeysDown.remove(keycode);
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
	if (action == GLFW_PRESS)
	{
		currentKeysDown.push_front(key);
	}
	else if (action == GLFW_RELEASE)
	{
		currentKeysDown.remove(key);
	}
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
	float offsetPosY = mousePosition.y - posY; //Coordenadas en Y estan invertidas
	mousePosition.x = posX;
	mousePosition.y = posY;

	offsetPosX *= sensitivity;
	offsetPosY *= sensitivity;
	deltaMousePosition.x = offsetPosX;
	deltaMousePosition.y = offsetPosY;
}