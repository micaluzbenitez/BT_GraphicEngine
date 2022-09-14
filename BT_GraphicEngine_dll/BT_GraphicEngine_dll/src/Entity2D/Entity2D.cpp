#include "Entity2D.h"

Entity2D::Entity2D()
{
    material = nullptr;
}

Entity2D::~Entity2D()
{
    if (material != nullptr) {
        material = nullptr;
        delete material;
    }
}

void Entity2D::AttachMaterial(Material* newMaterial)
{
	material = newMaterial;
}

void Entity2D::DetachMaterial()
{
	material = nullptr;
}

