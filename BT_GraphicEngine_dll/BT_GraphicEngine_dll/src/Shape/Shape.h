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
	const int SQUARE_POSITIONS_ARRAY_COUNT = 24;
	const int SQUARE_INDEX_ARRAY_COUNT = 6;

	const int VERTEX_SIZE = 6;

	glm::vec3 colorVector;

public:
	Shape(Renderer* newRenderer);
	~Shape();
	
	void SetColor(glm::vec3);
	glm::vec3 GetColor();
	
	void AttachMaterial();
	void DetachMaterial();

	void CreateTriangle();
	void CreateSquare();
	
	void Draw();
};

#endif   