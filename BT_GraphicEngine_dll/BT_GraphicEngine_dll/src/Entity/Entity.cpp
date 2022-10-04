#include "Entity.h"

Entity::Entity()
{
    transform = glm::mat4(1.0f);

    translate = glm::vec3(0.0f);
    rotation = glm::vec3(0.0f);
    scale = glm::vec3(1.0f);
    
    VBO = 0;
    VAO = 0;
    EBO = 0;
	
    renderer = nullptr;
}

Entity::~Entity()
{
    if (renderer != nullptr) {
        renderer = nullptr;
        delete renderer;
    }
}

void Entity::SetPosition(float x, float y, float z)
{
    translate = glm::vec3(x, y, z);
}

void Entity::SetRotation(float x, float y, float z)
{
    rotation = glm::vec3(x, y, z);
}

void Entity::SetScale(float x, float y, float z)
{
    scale = glm::vec3(x, y, z);
}

glm::vec3 Entity::GetPosition()
{
    return translate;
}

glm::vec3 Entity::GetRotation()
{
    return rotation;
}

glm::vec3 Entity::GetScale()
{
    return scale;
}