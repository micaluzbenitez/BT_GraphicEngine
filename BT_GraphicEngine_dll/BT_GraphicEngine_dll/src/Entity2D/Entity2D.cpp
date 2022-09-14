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

void Entity2D::AttachMaterial()
{
    ShaderProgramSource source = material->ParseShader("shaders/Basic.shader");
    material->CreateMaterial(source.VertexSource, source.FragmentSource);
    material->UseMaterial();
}

void Entity2D::DetachMaterial()
{
    material->DeleteMaterial();
}