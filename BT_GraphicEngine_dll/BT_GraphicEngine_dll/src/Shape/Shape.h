#ifndef SHAPE_H
#define SHAPE_H

#include <glew.h>
#include <glfw3.h>
#include "Export.h"
#include "Entity2D/Entity2D.h"

using namespace std;

class DllImport Shape : Entity2D
{
private:

public:
	Shape();
	~Shape();
	//virtual void Draw() = 0;
};

#endif   