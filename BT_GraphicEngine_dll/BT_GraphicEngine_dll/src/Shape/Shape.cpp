#include "Shape.h"

Shape::Shape()
{
    shader = NULL;
}

Shape::~Shape()
{
}

void Shape::AttachMaterial()
{
    // Create shader
    ShaderProgramSource source = material->ParseShader("shaders/Basic.shader");
    shader = material->CreateMaterial(source.VertexSource, source.FragmentSource);
    material->UseMaterial(shader);
}

void Shape::DetachMaterial()
{
    material->DeleteMaterial(shader);
}

void Shape::Draw(GLsizei vertices)
{
    renderer->DrawWithoutIndexBuffer(GL_TRIANGLES, 0, vertices);
}

void Shape::DrawWithIndexBuffer(GLsizei indices)
{
    renderer->DrawWithIndexBuffer(GL_TRIANGLES, indices, GL_UNSIGNED_INT, nullptr);
}