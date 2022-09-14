#ifndef COLLISIONMANAGER_H
#define COLLISIONMANAGER_H

#include <glew.h>
#include <glfw3.h>
#include "Entity2D/Entity2D.h"
#include "Export.h"
using namespace std;

class DllApi CollisionManager
{
private:
	Entity2D* entity2D;

public:
	CollisionManager();
	~CollisionManager();
};

#endif 