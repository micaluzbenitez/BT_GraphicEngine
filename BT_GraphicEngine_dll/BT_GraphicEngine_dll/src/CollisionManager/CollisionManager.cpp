#include "CollisionManager.h"

CollisionManager::CollisionManager()
{
    entity2D = nullptr;
}

CollisionManager::~CollisionManager()
{
    if (entity2D != nullptr) {
        entity2D = nullptr;
        delete entity2D;
    }
}