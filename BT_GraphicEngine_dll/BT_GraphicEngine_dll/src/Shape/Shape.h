#ifndef SHAPE_H
#define SHAPE_H

#include <glew.h>
#include <glfw3.h>
#include "Entity2D/Entity2D.h"
#include "Export.h"
using namespace std;

class DllImport Shape : public Entity2D
{
private:
	unsigned int shader;

public:
	Shape();
	~Shape();
	void AttachMaterial();
	void DetachMaterial();
	void Draw(GLsizei vertices);
	void DrawWithIndexBuffer(GLsizei indices);
};

#endif   