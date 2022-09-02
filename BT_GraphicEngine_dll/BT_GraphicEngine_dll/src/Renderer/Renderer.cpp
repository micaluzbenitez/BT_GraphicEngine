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

int Renderer::InitGLEW()
{
	if (glewInit() != GLEW_OK) return -1;
}

void Renderer::AssignVertexBuffer(GLsizei buffersQuantity, GLuint& buffer)
{
	glGenBuffers(1, &buffer);
}

void Renderer::SetVertexBufferTarget(GLenum target, GLuint buffer)
{
	glBindBuffer(target, buffer);
}

void Renderer::SetVertexBufferData(GLenum target, GLsizeiptr size, const GLvoid* data, GLenum usage)
{
	glBufferData(target, size, data, usage);
}

void Renderer::DrawWithoutIndexBuffer(GLenum primitive, GLint offset, GLsizei count)
{
	glDrawArrays(primitive, offset, count);
}

void Renderer::DrawWithIndexBuffer(GLenum primitive, GLsizei count, GLenum type, const GLvoid* indices)
{
	glDrawElements(primitive, count, type, indices);
}

void Renderer::EnableVertexAttribArray(GLuint index)
{
	glEnableVertexAttribArray(index);
}

void Renderer::DisableVertexAttribArray(GLuint index)
{
	glDisableVertexAttribArray(index);
}

void Renderer::EnableVertexArrayAttrib(GLuint vertexArrayObject, GLuint index)
{
	glEnableVertexArrayAttrib(vertexArrayObject, index);
}

void Renderer::DisableVertexArrayAttrib(GLuint vertexArrayObject, GLuint index)
{
	glDisableVertexArrayAttrib(vertexArrayObject, index);
}

void Renderer::DefineVertexAttribPointer(GLuint index, GLint size, GLenum type, GLboolean normalized, GLsizei stride, const GLvoid* offset)
{
	glVertexAttribPointer(index, size, type, normalized, stride, offset);
}