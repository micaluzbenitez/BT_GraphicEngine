#ifndef RENDERER_H
#define RENDERER_H

#include <glew.h>
#include <glfw3.h>
#include "Window/Window.h"
#include "glm/glm.hpp"
#include "glm/gtc/matrix_transform.hpp"
#include "glm/gtc/type_ptr.hpp"
#include "Export.h"
using namespace std;

class DllApi Renderer
{
private:
	Window* window;

	glm::mat4 view;
	glm::mat4 projection;

public:
	Renderer();
	~Renderer();
	void ClearScreen();
	void ClearScreenWithColor(GLfloat r, GLfloat g, GLfloat b, GLfloat a);
	void SwapBuffers(GLFWwindow* window);
	int InitGLEW();
	void BindBuffer(GLsizei buffersQuantity, GLuint& buffer, GLenum target, GLsizeiptr size, const GLvoid* data, GLenum usage);
	void EnableVertexAttributes(GLuint index, GLint size, GLenum type, GLboolean normalized, GLsizei stride, const GLvoid* offset);
	void DrawWithoutIndexBuffer(GLenum primitive, GLint offset, GLsizei count);
	void DrawWithIndexBuffer(GLenum primitive, GLsizei count, GLenum type, const GLvoid* indices);

	glm::mat4 GetViewMatrix();
	glm::mat4 GetProjectionMatrix();
};

#endif