#include "Entity2D.h"

Entity2D::Entity2D()
{
}

Entity2D::~Entity2D()
{
}

void Entity2D::AttachMaterial(Material* newMaterial)
{
	material = newMaterial;
}

void Entity2D::DetachMaterial()
{
	material = nullptr;
}

