#include "Shape.h"

Shape::Shape()
{
}

Shape::~Shape()
{
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

void Entity::Draw(GLsizei vertices)
{
    renderer->DrawWithoutIndexBuffer(GL_TRIANGLES, 0, vertices);
}

void Entity::DrawWithIndexBuffer(GLsizei indices)
{
    renderer->DrawWithIndexBuffer(GL_TRIANGLES, indices, GL_UNSIGNED_INT, nullptr);
}