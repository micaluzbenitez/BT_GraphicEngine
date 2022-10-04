#include "Shape.h"

Shape::Shape()
{
}

Shape::~Shape()
{
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

    
    // Vertex buffer
    renderer->BindBuffer(1, VBO, GL_ARRAY_BUFFER, TRIANGLE_POSITIONS_ARRAY_COUNT * sizeof(float), positions, GL_STATIC_DRAW);
    renderer->EnableVertexAttributes(0, 2, GL_FLOAT, GL_FALSE, sizeof(float) * 2, 0);

    // Index buffer
    renderer->BindBuffer(1, EBO, GL_ELEMENT_ARRAY_BUFFER, TRIANGLE_INDEX_ARRAY_COUNT * sizeof(unsigned int), indices, GL_STATIC_DRAW);
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

    // Vertex buffer
    renderer->BindBuffer(1, VBO, GL_ARRAY_BUFFER, SQUARE_POSITIONS_ARRAY_COUNT * sizeof(float), positions, GL_STATIC_DRAW);
    renderer->EnableVertexAttributes(0, 2, GL_FLOAT, GL_FALSE, sizeof(float) * 2, 0);

    // Index buffer
    renderer->BindBuffer(1, EBO, GL_ELEMENT_ARRAY_BUFFER, SQUARE_INDEX_ARRAY_COUNT * sizeof(unsigned int), indices, GL_STATIC_DRAW);

    AttachMaterial();
}

void Shape::DrawSquare()
{
    DrawWithIndexBuffer(SQUARE_INDEX_ARRAY_COUNT);
}