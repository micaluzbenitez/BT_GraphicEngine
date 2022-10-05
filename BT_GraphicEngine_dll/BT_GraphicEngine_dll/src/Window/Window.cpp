#include "Window.h"

Window::Window(int newWidth, int newHeight)
{
	window = nullptr;
	width = newWidth;
	height = newHeight;
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
	// Initialize the library
	if (!glfwInit()) return -1;
}

int Window::CreateWindow()
{
	// Create a windowed mode window and its OpenGL context
	window = glfwCreateWindow(width, height, "Hello World", NULL, NULL);
	if (!window)
	{
		TerminateLibrary();
		return -1;
	}
}

void Window::MakeWindowContextCurrent()
{
	// Make the window's context current
	glfwMakeContextCurrent(window);
}

bool Window::WindowShouldClose()
{
	// Check the user closes the window
	return glfwWindowShouldClose(window);
}

void Window::PollEvents()
{
	// Poll for and process events
	glfwPollEvents();
}

void Window::TerminateLibrary()
{
	// Finish the process of running the library
	glfwTerminate();
}

GLFWwindow* Window::GetWindow()
{
	return window;
}

int Window::GetWidth()
{
	return width;
}

int Window::GetHeight()
{
	return height;
}
