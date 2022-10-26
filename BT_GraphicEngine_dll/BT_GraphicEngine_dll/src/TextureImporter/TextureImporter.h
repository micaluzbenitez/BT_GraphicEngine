#ifndef TEXTUREIMPORTER_H
#define TEXTUREIMPORTER_H

#include <glew.h>
#include <glfw3.h>
#include <iostream>
#define STB_IMAGE_IMPLEMENTATION
#include "stb_image.h"
#include "Export.h"
using namespace std;

struct Texture
{
	unsigned int ID;
	float width;
	float height;
};


class DllApi TextureImporter
{
private:

public:
	TextureImporter();
	~TextureImporter();

	static Texture LoadTexture(const char* path, bool invertImage);
};

#endif 