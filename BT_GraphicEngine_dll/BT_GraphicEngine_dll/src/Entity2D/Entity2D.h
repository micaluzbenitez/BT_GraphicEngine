#ifndef ENTITY2D_H
#define ENTITY2D_H

#include <glew.h>
#include <glfw3.h>
#include "Entity/Entity.h"
#include "Material/Material.h"
#include "Export.h"
using namespace std;

class DllImport Entity2D : Entity
{
private:
	Material* material;
public:
	Entity2D();
	~Entity2D();
	void AttachMaterial();
	void DetachMaterial();
};

#endif 