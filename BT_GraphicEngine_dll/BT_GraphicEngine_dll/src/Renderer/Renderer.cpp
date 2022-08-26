#include "Renderer.h"

Renderer::Renderer()
{
}

Renderer::~Renderer()
{
}

void Renderer::ClearScreen()
{
	// Clears the context window
	glClear(GL_COLOR_BUFFER_BIT);
}

void Renderer::ClearScreenWithColor(GLfloat r, GLfloat g, GLfloat b, GLfloat a)
{
	// Sets the color to clear the screen and clears the context window
	glClearColor(r, g, b, a);
	ClearScreen();
}

void Renderer::SwapBuffers(GLFWwindow* window)
{
	// Swap front and back buffers
	glfwSwapBuffers(window);
}
