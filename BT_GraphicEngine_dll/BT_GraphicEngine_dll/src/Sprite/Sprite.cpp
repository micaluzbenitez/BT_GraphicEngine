#include "Sprite.h"

Sprite::Sprite(Renderer* newRenderer, string path)
{
    animation = nullptr;
    renderer = newRenderer;
    texture = TextureImporter::LoadTexture(path, true);

    widthTexture = texture.width;
    heightTexture = texture.height;

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

    renderer->CreateBuffers(VAO, VBO, EBO);
    renderer->BindBuffers(POSITIONS_ARRAY_COUNT * sizeof(float), INDEX_ARRAY_COUNT * sizeof(unsigned int), positions, indices, VAO, VBO, EBO);
    renderer->EnableVertexAttributes(0, 3, GL_FLOAT, GL_FALSE, sizeof(float) * VERTEX_SIZE, 0); //pos
    renderer->EnableVertexAttributes(1, 3, GL_FLOAT, GL_FALSE, sizeof(float) * VERTEX_SIZE, (void*)(sizeof(float) * 3)); //color
    renderer->EnableVertexAttributes(2, 2, GL_FLOAT, GL_FALSE, sizeof(float) * VERTEX_SIZE, (void*)(sizeof(float) * 6)); //texture coords
}

Sprite::~Sprite()
{
    DetachMaterial();

    if (animation != nullptr) 
    {
        animation = nullptr;
        delete animation;
    }
}

void Sprite::AttachMaterial()
{
    // Create shader
    ShaderProgramSource source = material->ParseShader("shaders/Textures.shader");
    material->CreateMaterial(source.VertexSource, source.FragmentSource);
    material->UseMaterial();
    material->ModifyMaterial(renderer->GetProjectionMatrix(), renderer->GetViewMatrix(), GetModelMatrix(), colorVector, texture.ID);
}

void Sprite::DetachMaterial()
{
    material->DeleteMaterial();
}

void Sprite::Draw()
{
    AttachMaterial();
    material->ModifyMaterial(renderer->GetProjectionMatrix(), renderer->GetViewMatrix(), GetModelMatrix(), colorVector, texture.ID);
    material->UseMaterial();
    renderer->BindTexture(GL_TEXTURE_2D, texture.ID);
    renderer->DrawWithIndexBuffer(GL_TRIANGLES, VERTEX_SIZE, GL_UNSIGNED_INT, nullptr, VAO);
}

void Sprite::CreateAnimation(int rows, int cols, float speed)
{
    animation = new Animation();
    animation->SetSpeed(speed);

    for (int x = 0; x < cols; x++)
    {
        for (int y = 0; y < rows; y++)
        {
            animation->AddFrame(x, y, widthTexture / cols, heightTexture / rows, widthTexture, heightTexture, 1);
        }
    }
}

void Sprite::UpdateAnimation()
{
    if (animation != NULL)
    {
        animation->Update();
        SetUVCoords(animation->GetFrames()[animation->GetCurrentFrame()]);
    }
}

void Sprite::SetUVCoords(Frame frame)
{
    float coords[8] =
    {
        frame.GetUVCoords()[0].U, frame.GetUVCoords()[0].V,
        frame.GetUVCoords()[1].U, frame.GetUVCoords()[1].V,
        frame.GetUVCoords()[2].U, frame.GetUVCoords()[2].V,
        frame.GetUVCoords()[3].U, frame.GetUVCoords()[3].V
    };

    float positions[] =
    {
        // Positions         // Colors          // Texture coords
         0.5f,  0.5f, 0.0f,  1.0f, 1.0f, 1.0f, coords[6], coords[7], // Top right
         0.5f, -0.5f, 0.0f,  1.0f, 1.0f, 1.0f, coords[2], coords[3], // Bottom right
        -0.5f, -0.5f, 0.0f,  1.0f, 1.0f, 1.0f, coords[0], coords[1], // Bottom left
        -0.5f,  0.5f, 0.0f,  1.0f, 1.0f, 1.0f, coords[4], coords[5]  // Top left
    };

    /* Index buffer */
    unsigned int indices[] =
    {
        0, 1, 2,
        2, 3, 0
    };

    renderer->BindBuffers(POSITIONS_ARRAY_COUNT * sizeof(float), INDEX_ARRAY_COUNT * sizeof(unsigned int), positions, indices, VAO, VBO, EBO);
}

void Sprite::SetColor(glm::vec3 newColor)
{
    colorVector = newColor;
}

glm::vec3 Sprite::GetColor()
{
    return colorVector;
}