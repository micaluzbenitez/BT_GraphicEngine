#include "Shape.h"

Shape::Shape(Renderer* newRenderer)
{
    renderer = newRenderer;
}

Shape::~Shape()
{
    renderer->UnBindVertex(VAO, VBO, EBO);
}

void Shape::SetColor(glm::vec3 newColor)
{
    colorVector = newColor;
}

glm::vec3 Shape::GetColor()
{
    return colorVector;
}

void Shape::AttachMaterial()
{
    // Create shader
    ShaderProgramSource source = material->ParseShader("shaders/Basic.shader");
    material->CreateMaterial(source.VertexSource, source.FragmentSource);
    cout << "VERTEX:" << endl;
    cout << source.VertexSource << endl;
    cout << "FRAGMENT:" << endl;
    cout << source.FragmentSource << endl;
    material->UseMaterial();
    material->ModifyMaterial(renderer->GetProjectionMatrix(), renderer->GetViewMatrix(), GetModelMatrix(), colorVector);
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
    material->ModifyMaterial(renderer->GetProjectionMatrix(), renderer->GetViewMatrix(), GetModelMatrix(), colorVector);
    material->UseMaterial();
    renderer->DrawWithIndexBuffer(GL_TRIANGLES, 6, GL_UNSIGNED_INT, nullptr, VAO);
}

// ----------------------------------------- TRIANGLE -----------------------------------------
void Shape::CreateTriangle()
{
    /* GLEW buffer */
    float positions[] =
    {
        -0.5f, -0.5f, 0.0f, 1.0f, 1.0f, 1.0f, // 0
         0.0f,  0.5f, 0.0f, 1.0f, 1.0f, 1.0f, // 1
         0.5f, -0.5f, 0.0f, 1.0f, 1.0f, 1.0f  // 2
    }; 

    unsigned int indices[] =
    {
        0, 1, 2
    };

    renderer->BindBuffer(TRIANGLE_POSITIONS_ARRAY_COUNT * sizeof(float), TRIANGLE_INDEX_ARRAY_COUNT * sizeof(unsigned int), positions, indices, VAO, VBO, EBO);
    renderer->EnableVertexAttributes(0, 3, GL_FLOAT, GL_FALSE, sizeof(float) * VERTEX_SIZE, 0); //pos
    renderer->EnableVertexAttributes(1, 3, GL_FLOAT, GL_FALSE, sizeof(float) * VERTEX_SIZE, (void*)(sizeof(float)*3)); //color
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
        1.5f,  -0.5f, 0.0f,  1.0f, 1.0f, 1.0f, // 0
        2.5f,  -0.5f, 0.0f,  1.0f, 1.0f, 1.0f, // 1
        2.5f,   0.5f, 0.0f,  1.0f, 1.0f, 1.0f, // 2
        1.5f,   0.5f, 0.0f,  1.0f, 1.0f, 1.0f, // 2
    };

    /* Index buffer */
    unsigned int indices[] =
    {
        0, 1, 2,
        2, 3, 0
    };

    renderer->BindBuffer(SQUARE_POSITIONS_ARRAY_COUNT * sizeof(float), SQUARE_INDEX_ARRAY_COUNT * sizeof(unsigned int), positions, indices, VAO, VBO, EBO);
    renderer->EnableVertexAttributes(0, 3, GL_FLOAT, GL_FALSE, sizeof(float) * VERTEX_SIZE, 0); //pos
    renderer->EnableVertexAttributes(1, 3, GL_FLOAT, GL_FALSE, sizeof(float) * VERTEX_SIZE, (void*)(sizeof(float) * 3)); //color
}

void Shape::DrawSquare()
{
    DrawWithIndexBuffer(SQUARE_INDEX_ARRAY_COUNT);
}