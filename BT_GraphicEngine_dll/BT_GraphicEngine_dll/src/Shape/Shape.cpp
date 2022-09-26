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

void Shape::CreateTriangle()
{
    /* GLEW buffer */
    float positions[6] =
    {
        -0.5f, -0.5f,  // 0
         0.0f,  0.5f,  // 1
         0.5f, -0.5f,  // 2
    };
}

void Shape::DrawTriangle()
{
    Draw(3);
}

void Shape::CreateSquare()
{
    /* GLEW buffer */
    float positions[] =
    {
        -0.5f, -0.5f,  // 0
         0.5f, -0.5f,  // 1
         0.5f,  0.5f,  // 2
        -0.5f,  0.5f   // 3
    };

    /* Index buffer */
    unsigned int indices[] =
    {
        0, 1, 2,
        2, 3, 0
    };

    unsigned int buffer; // Vertex buffer
    renderer->BindBuffer(1, buffer, GL_ARRAY_BUFFER, 6 * 2 * sizeof(float), positions, GL_STATIC_DRAW);
    renderer->EnableVertexAttributes(0, 2, GL_FLOAT, GL_FALSE, sizeof(float) * 2, 0);

    unsigned int ibo; // Index buffer
    renderer->BindBuffer(1, ibo, GL_ELEMENT_ARRAY_BUFFER, 6 * sizeof(unsigned int), indices, GL_STATIC_DRAW);
}

void Shape::DrawSquare()
{
    DrawWithIndexBuffer(6);
}
