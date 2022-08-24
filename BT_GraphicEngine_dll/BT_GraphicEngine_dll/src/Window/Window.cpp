#include "Window.h"

Window::Window()
{
	window = nullptr;
}

Window::~Window()
{
	if (window != nullptr)
	{
		window = nullptr;
		delete window;
	}
}

int Window::InitLibrary()
{
	if (!glfwInit()) return -1;
}

int Window::CreateWindow()
{
	window = glfwCreateWindow(640, 480, "Hello World", NULL, NULL);
	if (!window)
	{
		TerminateLibrary();
		return -1;
	}
}

void Window::MakeWindowContextCurrent()
{

	glfwMakeContextCurrent(window);
}

bool Window::WindowShouldClose()
{
	return glfwWindowShouldClose(window);
}

void Window::PollEvents()
{
	glfwPollEvents();
}

void Window::TerminateLibrary()
{
	glfwTerminate();
}

GLFWwindow* Window::GetWindow()
{
	return window;
}
