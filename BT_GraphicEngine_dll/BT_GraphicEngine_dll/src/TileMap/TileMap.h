#ifndef TILEMAP_H
#define TILEMAP_H

#include <glew.h>
#include <glfw3.h>
#include "Entity2D/Entity2D.h"
#include "Export.h"
using namespace std;

class DllApi TileMap : public Entity2D
{
private:

public:
	TileMap();
	~TileMap();
};

#endif 