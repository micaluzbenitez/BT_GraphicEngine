#ifndef SQUARE_H
#define SQUARE_H

#include <glew.h>
#include <glfw3.h>
#include "Shape/Shape.h"
#include "Export.h"
using namespace std;

class DllImport Square : Shape
{
private:

public:
	Square();
	~Square();
	void Draw();
};

#endif 