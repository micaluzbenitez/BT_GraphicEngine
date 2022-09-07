#ifndef TRIANGLE_H
#define TRIANGLE_H

#include <glfw3.h>
#include "Export.h"
#include "Shape/Shape.h"

using namespace std;

class DllImport Triangle : Shape
{
private:

public:
	Triangle();
	~Triangle();
	void Draw();
};

#endif 