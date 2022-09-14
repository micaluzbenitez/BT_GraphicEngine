#ifndef TRIANGLE_H
#define TRIANGLE_H

#include <glew.h>
#include <glfw3.h>
#include "Shape/Shape.h"
#include "Export.h"
using namespace std;

class DllApi Triangle : Shape
{
private:


public:
	Triangle();
	~Triangle();
	void Draw();
};

#endif 