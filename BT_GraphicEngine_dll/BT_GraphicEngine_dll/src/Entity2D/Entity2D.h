#ifndef ENTITY2D_H
#define ENTITY2D_H

#include <glew.h>
#include <glfw3.h>
#include "Export.h"
#include "Entity/Entity.h"
#include "Material/Material.h"

using namespace std;

class DllImport Entity2D : Entity
{
private:
	Material* material;
public:
	Entity2D();
	~Entity2D();
	void AttachMaterial(Material* newMaterial);
	void DetachMaterial();
	//virtual void Draw() = 0;
};

#endif 