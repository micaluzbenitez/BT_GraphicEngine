#include "Shape.h"

Shape::Shape()
{
}

Shape::~Shape()
{
    renderer->UnBindVertex(VAO, VBO, EBO);
}

void Shape::AttachMaterial()
{
    // Create shader
    ShaderProgramSource source = material->ParseShader("shaders/Basic.shader");
    material->CreateMaterial(source.VertexSource, source.FragmentSource);
    material->UseMaterial();
    material->ModifyMaterial(Renderer::GetProjectionMatrix(), Renderer::GetViewMatrix(), GetModelMatrix());
}

void Shape::DetachMaterial()
{
    material->DeleteMaterial();
}

void Shape::Draw(GLsizei vertices)
{
    renderer->DrawWithoutIndexBuffer(GL_TRIANGLES, 0, vertices);
}

void Shape::DrawWithIndexBuffer(GLsizei indices)
{
    renderer->DrawWithIndexBuffer(GL_TRIANGLES, indices, GL_UNSIGNED_INT, nullptr);
}

// ----------------------------------------- TRIANGLE -----------------------------------------
void Shape::CreateTriangle()
{
    /* GLEW buffer */
    float positions[] =
    {
        -0.5f, -0.5f,  // 0
         0.0f,  0.5f,  // 1
         0.5f, -0.5f,  // 2
    }; 

    unsigned int indices[] =
    {
        0, 1, 2
    };

    renderer->BindBuffer(TRIANGLE_POSITIONS_ARRAY_COUNT * sizeof(float), TRIANGLE_INDEX_ARRAY_COUNT * sizeof(unsigned int), positions, indices, VAO, VBO, EBO);
    renderer->EnableVertexAttributes(0, 2, GL_FLOAT, GL_FALSE, sizeof(float) * 2, 0);
}

void Shape::DrawTriangle()
{
    DrawWithIndexBuffer(TRIANGLE_INDEX_ARRAY_COUNT);
}

// ------------------------------------------ SQUARE ------------------------------------------
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

    renderer->BindBuffer(SQUARE_POSITIONS_ARRAY_COUNT * sizeof(float), SQUARE_INDEX_ARRAY_COUNT * sizeof(unsigned int), positions, indices, VAO, VBO, EBO);
    renderer->EnableVertexAttributes(0, 2, GL_FLOAT, GL_FALSE, sizeof(float) * 2, 0);
}

void Shape::DrawSquare()
{
    DrawWithIndexBuffer(SQUARE_INDEX_ARRAY_COUNT);
}