#include "Renderer.h"

Renderer::Renderer()
{
}

Renderer::~Renderer()
{
}

void Renderer::ClearScreen()
{
	glClear(GL_COLOR_BUFFER_BIT); /* Clears the context window */
}

void Renderer::ClearScreenWithColor(GLfloat r, GLfloat g, GLfloat b, GLfloat a)
{
	glClearColor(r, g, b, a); /* Sets the color to clear the screen */ 
	ClearScreen();
}

void Renderer::SwapBuffers(GLFWwindow* window)
{
	/* Swap front and back buffers */
	glfwSwapBuffers(window);
}
