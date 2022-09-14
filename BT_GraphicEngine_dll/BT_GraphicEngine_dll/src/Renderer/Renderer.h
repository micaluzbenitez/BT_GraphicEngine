#ifndef RENDERER_H
#define RENDERER_H

#include <glew.h>
#include <glfw3.h>
#include "Window/Window.h"
#include "Export.h"
using namespace std;

class DllImport Renderer
{
private:
	Window* window;

public:
	Renderer();
	~Renderer();
	void ClearScreen();
	void ClearScreenWithColor(GLfloat r, GLfloat g, GLfloat b, GLfloat a);
	void SwapBuffers(GLFWwindow* window);
	int InitGLEW();
	void AssignVertexBuffer(GLsizei buffersQuantity, GLuint& buffer);
	void SetVertexBufferTarget(GLenum target, GLuint buffer);
	void SetVertexBufferData(GLenum target, GLsizeiptr size, const GLvoid* data, GLenum usage);
	void DrawWithoutIndexBuffer(GLenum primitive, GLint offset, GLsizei count);
	void DrawWithIndexBuffer(GLenum primitive, GLsizei count, GLenum type, const GLvoid* indices);
	void EnableVertexAttribArray(GLuint index);
	void DefineVertexAttribPointer(GLuint index, GLint size, GLenum type, GLboolean normalized, GLsizei stride, const GLvoid* pointer);
};

#endif