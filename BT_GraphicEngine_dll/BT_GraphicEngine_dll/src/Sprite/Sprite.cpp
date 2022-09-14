#include "Sprite.h"

Sprite::Sprite()
{
    animation = nullptr;
}

Sprite::~Sprite()
{
    if (animation != nullptr) {
        animation = nullptr;
        delete animation;
    }
}