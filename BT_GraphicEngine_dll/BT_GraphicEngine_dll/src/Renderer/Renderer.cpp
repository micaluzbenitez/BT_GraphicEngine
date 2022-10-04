#include "Renderer.h"

Renderer::Renderer()
{
	window = nullptr;
}

glm::mat4 Renderer::view = glm::mat4(1.0f);
glm::mat4 Renderer::projection = glm::mat4(1.0f);

Renderer::~Renderer()
{
	if (window != nullptr) {
		window = nullptr;
		delete window;
	}
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
	// Init GLEW
	if (glewInit() != GLEW_OK) return -1;
}

void Renderer::BindBuffer(GLsizei buffersQuantity, GLuint& buffer, GLenum target, GLsizeiptr size, const GLvoid* data, GLenum usage)
{
	// Assing out GLEW buffer
	glGenBuffers(buffersQuantity, &buffer); // Assign vertex buffer
	glBindBuffer(target, buffer); // Set vertex buffer target
	glBufferData(target, size, data, usage); // Set vertex buffer data
}

void Renderer::EnableVertexAttributes(GLuint index, GLint size, GLenum type, GLboolean normalized, GLsizei stride, const GLvoid* offset)
{
	// GLEW enabled vertex attrib
	glEnableVertexAttribArray(index); // Enable vertex attrib array
	glVertexAttribPointer(index, size, type, normalized, stride, offset); // Define vertex attrib pointer
}

void Renderer::DrawWithoutIndexBuffer(GLenum primitive, GLint offset, GLsizei count)
{
	// Draw vertices
	glDrawArrays(primitive, offset, count);
}

void Renderer::DrawWithIndexBuffer(GLenum primitive, GLsizei count, GLenum type, const GLvoid* indices)
{
	// Draw indices
	glDrawElements(primitive, count, type, indices);
}

glm::mat4 Renderer::GetViewMatrix()
{
	return view;
}

glm::mat4 Renderer::GetProjectionMatrix()
{
	return projection;
}