#include "Sprite.h"

Sprite::Sprite(Renderer* newRenderer, string path)
{
    animation = nullptr;
    renderer = newRenderer;
    texture = TextureImporter::LoadTexture(path, true);

    float positions[] =
    {
        // Positions         // Colors          // Texture coords
         0.5f,  0.5f, 0.0f,  1.0f, 1.0f, 1.0f,  1.0f, 1.0f, // Top right
         0.5f, -0.5f, 0.0f,  1.0f, 1.0f, 1.0f,  1.0f, 0.0f, // Bottom right
        -0.5f, -0.5f, 0.0f,  1.0f, 1.0f, 1.0f,  0.0f, 0.0f, // Bottom left
        -0.5f,  0.5f, 0.0f,  1.0f, 1.0f, 1.0f,  0.0f, 1.0f  // Top left
    };
    
    /* Index buffer */
    unsigned int indices[] =
    {
        0, 1, 2,
        2, 3, 0
    };
    
    renderer->BindBuffer(POSITIONS_ARRAY_COUNT * sizeof(float), INDEX_ARRAY_COUNT * sizeof(unsigned int), positions, indices, VAO, VBO, EBO);
    renderer->EnableVertexAttributes(0, 3, GL_FLOAT, GL_FALSE, sizeof(float) * VERTEX_SIZE, 0); //pos
    renderer->EnableVertexAttributes(1, 3, GL_FLOAT, GL_FALSE, sizeof(float) * VERTEX_SIZE, (void*)(sizeof(float) * 3)); //color
    renderer->EnableVertexAttributes(2, 2, GL_FLOAT, GL_FALSE, sizeof(float) * VERTEX_SIZE, (void*)(sizeof(float) * 6)); //texture coords

    AttachMaterial();
}

Sprite::~Sprite()
{
    if (animation != nullptr) 
    {
        animation = nullptr;
        delete animation;
    }

    DetachMaterial();
}

void Sprite::AttachMaterial()
{
    // Create shader
    ShaderProgramSource source = material->ParseShader("shaders/Basic.shader");
    material->CreateMaterial(source.VertexSource, source.FragmentSource);
    material->UseMaterial();
    material->ModifyMaterial(renderer->GetProjectionMatrix(), renderer->GetViewMatrix(), GetModelMatrix(), colorVector, texture.ID);

    cout << "VERTEX:" << endl;
    cout << source.VertexSource << endl;
    cout << "FRAGMENT:" << endl;
    cout << source.FragmentSource << endl;
}

void Sprite::DetachMaterial()
{
    material->DeleteMaterial();
}

void Sprite::Draw()
{
    material->ModifyMaterial(renderer->GetProjectionMatrix(), renderer->GetViewMatrix(), GetModelMatrix(), colorVector, texture.ID);
    material->UseMaterial();
    glBindTexture(GL_TEXTURE_2D, texture.ID);
    renderer->DrawWithIndexBuffer(GL_TRIANGLES, VERTEX_SIZE, GL_UNSIGNED_INT, nullptr, VAO);
}

void Sprite::SetColor(glm::vec3 newColor)
{
    colorVector = newColor;
}

glm::vec3 Sprite::GetColor()
{
    return colorVector;
}