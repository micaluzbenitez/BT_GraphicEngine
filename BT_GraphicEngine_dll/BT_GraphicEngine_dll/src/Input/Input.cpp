#include "Input.h"
#include "Window/Window.h"


list<int> Input::currentKeysDown = list<int>();
glm::vec2 Input::mousePosition = glm::vec2(0.f);
bool Input::firstMouse = true;

Input::Input(Window* window)
{
	mousePosition.x = window->GetWidth() / 2;
	mousePosition.y = window->GetHeight() / 2;

	glfwSetKeyCallback(window->GetWindow(), KeyCallback);
	glfwSetCursorPosCallback(window->GetWindow(), MouseCallback);
	glfwSetInputMode(window->GetWindow(), GLFW_CURSOR, GLFW_CURSOR_DISABLED);
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
}