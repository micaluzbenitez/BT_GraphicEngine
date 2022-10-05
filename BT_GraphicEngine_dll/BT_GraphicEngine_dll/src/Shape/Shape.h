#ifndef SHAPE_H
#define SHAPE_H

#include <glew.h>
#include <glfw3.h>
#include "Entity2D/Entity2D.h"
#include "Export.h"
using namespace std;

class DllApi Shape : public Entity2D
{
private:
	const int TRIANGLE_POSITIONS_ARRAY_COUNT = 18;
	const int TRIANGLE_INDEX_ARRAY_COUNT = 3;
	const int SQUARE_POSITIONS_ARRAY_COUNT = 8;
	const int SQUARE_INDEX_ARRAY_COUNT = 6;

	const int VERTEX_SIZE = 6;

public:
	Shape();
	~Shape();
	void AttachMaterial();
	void DetachMaterial();
	void Draw(GLsizei vertices);
	void DrawWithIndexBuffer(GLsizei indices);

	void CreateTriangle();
	void DrawTriangle();

	void CreateSquare();
	void DrawSquare();
};

#endif   