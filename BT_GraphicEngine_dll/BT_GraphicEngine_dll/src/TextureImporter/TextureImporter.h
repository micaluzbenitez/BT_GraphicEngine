#ifndef TEXTUREIMPORTER_H
#define TEXTUREIMPORTER_H

#include <glew.h>
#include <glfw3.h>
#include <iostream>
#include "Export.h"
using namespace std;

struct Texture
{
	unsigned int ID;
	float width;
	float height;
};

static class DllApi TextureImporter
{
private:

public:
	static Texture LoadTexture(string path, bool invertImage);
};

#endif 