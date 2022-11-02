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
    material->UseMaterial();
    material->ModifyMaterial(renderer->GetProjectionMatrix(), renderer->GetViewMatrix(), GetModelMatrix(), colorVector);

    cout << "VERTEX:" << endl;
    cout << source.VertexSource << endl;
    cout << "FRAGMENT:" << endl;
    cout << source.FragmentSource << endl;
}

void Shape::DetachMaterial()
{
    material->DeleteMaterial();
}

void Shape::Draw()
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
        // Positions         // Colors
        -0.5f, -0.5f, 0.0f,  1.0f, 1.0f, 1.0f, // Lower-left corner  
         0.0f,  0.5f, 0.0f,  1.0f, 1.0f, 1.0f, // Lower-right corner
         0.5f, -0.5f, 0.0f,  1.0f, 1.0f, 1.0f  // Top-center corner

         /* 
         Si quisiera todos los bordes de diferente color:
        -0.5f, -0.5f, 0.0f,  0.0f, 1.0f, 0.0f,
         0.0f,  0.5f, 0.0f,  1.0f, 0.0f, 0.0f,
         0.5f, -0.5f, 0.0f,  0.0f, 0.0f, 1.0f 
         */
    }; 

    unsigned int indices[] =
    {
        0, 1, 2
    };

    renderer->BindBuffer(TRIANGLE_POSITIONS_ARRAY_COUNT * sizeof(float), TRIANGLE_INDEX_ARRAY_COUNT * sizeof(unsigned int), positions, indices, VAO, VBO, EBO);
    renderer->EnableVertexAttributes(0, 3, GL_FLOAT, GL_FALSE, sizeof(float) * VERTEX_SIZE, 0); //pos
    renderer->EnableVertexAttributes(1, 3, GL_FLOAT, GL_FALSE, sizeof(float) * VERTEX_SIZE, (void*)(sizeof(float)*3)); //color
}

// ------------------------------------------ SQUARE ------------------------------------------
void Shape::CreateSquare()
{
    /* GLEW buffer */
    float positions[] =
    {
        // Positions         // Colors
         0.5f,  0.5f, 0.0f,  1.0f, 1.0f, 1.0f, // Top right
         0.5f, -0.5f, 0.0f,  1.0f, 1.0f, 1.0f, // Bottom right
        -0.5f, -0.5f, 0.0f,  1.0f, 1.0f, 1.0f, // Bottom left
        -0.5f,  0.5f, 0.0f,  1.0f, 1.0f, 1.0f  // Top left
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