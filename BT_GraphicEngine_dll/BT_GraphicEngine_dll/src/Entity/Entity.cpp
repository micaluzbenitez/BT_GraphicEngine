#include "Entity.h"

Entity::Entity()
{
	renderer = nullptr;
}

Entity::~Entity()
{
    if (renderer != nullptr) {
        renderer = nullptr;
        delete renderer;
    }
}