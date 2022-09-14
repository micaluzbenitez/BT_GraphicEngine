#ifndef SPRITE_H
#define SPRITE_H

#include <glew.h>
#include <glfw3.h>
#include "Entity2D/Entity2D.h"
#include "Animation/Animation.h"
#include "Export.h"
using namespace std;

class DllImport Sprite : public Entity2D
{
private:
	Animation* animation;

public:
	Sprite();
	~Sprite();
};

#endif 