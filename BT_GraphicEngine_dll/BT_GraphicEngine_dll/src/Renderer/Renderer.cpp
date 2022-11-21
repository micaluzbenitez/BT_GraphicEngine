#include "Renderer.h"

Renderer::Renderer(Window* newWindow)
{
	window = newWindow;

	view = glm::lookAt(glm::vec3(0, 0, 15), glm::vec3(0, 0, 0), glm::vec3(0, 1, 0));
	projection = glm::perspective(glm::radians(90.0f), (float)window->GetWidth() / (float)window->GetHeight(), 0.1f, 100.0f);
}

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

void Renderer::CreateBuffers(unsigned int& VAO, unsigned int& VBO, unsigned int& EBO)
{
	glGenVertexArrays(1, &VAO);
	glGenBuffers(1, &VBO);
	glGenBuffers(1, &EBO);
}

void Renderer::BindBuffers(GLsizeiptr sizeVertices, GLsizeiptr sizeIndices, const GLvoid* vertices, const GLvoid* indices, unsigned int& VAO, unsigned int& VBO, unsigned int& EBO)
{
	glBindVertexArray(VAO);

	// Vertex buffer
	glBindBuffer(GL_ARRAY_BUFFER, VBO);
	glBufferData(GL_ARRAY_BUFFER, sizeVertices, vertices, GL_STATIC_DRAW);

	// Index buffer
	glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, EBO);
	glBufferData(GL_ELEMENT_ARRAY_BUFFER, sizeIndices, indices, GL_STATIC_DRAW);
}

void Renderer::UnBindVertex(unsigned int& VAO, unsigned int& VBO, unsigned int& EBO)
{
	glDeleteVertexArrays(1, &VAO);
	glDeleteBuffers(1, &VBO);
	glDeleteBuffers(1, &EBO);
}

void Renderer::EnableVertexAttributes(GLuint index, GLint size, GLenum type, GLboolean normalized, GLsizei stride, const GLvoid* offset)
{
	// GLEW enabled vertex attrib
	glVertexAttribPointer(index, size, type, normalized, stride, offset); // Define vertex attrib pointer
	glEnableVertexAttribArray(index); // Enable vertex attrib array
}

void Renderer::BindTexture(GLenum target, GLuint texture)
{
	glBindTexture(target, texture);
}

void Renderer::DrawWithoutIndexBuffer(GLenum primitive, GLint offset, GLsizei count)
{
	// Draw vertices
	glDrawArrays(primitive, offset, count);
}

void Renderer::DrawWithIndexBuffer(GLenum primitive, GLsizei count, GLenum type, const GLvoid* indices, unsigned int VAO)
{
	glBindVertexArray(VAO);
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