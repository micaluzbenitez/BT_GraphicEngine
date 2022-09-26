#ifndef ENTITY2D_H
#define ENTITY2D_H

#include <glew.h>
#include <glfw3.h>
#include "Entity/Entity.h"
#include "Material/Material.h"
#include "Export.h"
using namespace std;

class DllApi Entity2D : public Entity
{
protected:
	Material* material;
public:
	Entity2D();
	~Entity2D();
	virtual void AttachMaterial() = 0;
	virtual void DetachMaterial() = 0;
};

#endif 