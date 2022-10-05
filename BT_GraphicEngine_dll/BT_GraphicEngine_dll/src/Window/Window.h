#ifndef WINDOW_H
#define WINDOW_H

#include <glew.h>
#include <glfw3.h>
#include "Export.h"
using namespace std;

class DllApi Window
{
private:
	GLFWwindow* window;
	int height;
	int width;

public:
	Window(int newWidth, int newHeight);
	~Window();
	int InitLibrary();
	int CreateWindow();
	void MakeWindowContextCurrent();
	bool WindowShouldClose();
	void PollEvents();
	void TerminateLibrary();
	GLFWwindow* GetWindow();
	int GetWidth();
	int GetHeight();
};

#endif   