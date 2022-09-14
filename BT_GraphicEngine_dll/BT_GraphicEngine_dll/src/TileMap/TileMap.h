#ifndef TILEMAP_H
#define TILEMAP_H

#include <glfw3.h>
#include "Entity2D/Entity2D.h"
#include "Export.h"
using namespace std;

class DllImport TileMap : Entity2D
{
private:

public:
	TileMap();
	~TileMap();
	void Draw();
};

#endif 