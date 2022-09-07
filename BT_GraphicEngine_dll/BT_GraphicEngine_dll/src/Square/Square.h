#ifndef SQUARE_H
#define SQUARE_H

#include <glfw3.h>
#include "Export.h"
#include "Shape/Shape.h"

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