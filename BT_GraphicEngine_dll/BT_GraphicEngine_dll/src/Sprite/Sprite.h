#ifndef SPRITE_H
#define SPRITE_H

#include <glew.h>
#include <glfw3.h>
#include "Entity2D/Entity2D.h"
#include "Animation/Animation.h"
#include "TextureImporter/TextureImporter.h"
#include "Export.h"
using namespace std;

class DllApi Sprite : public Entity2D
{
private:
	const int POSITIONS_ARRAY_COUNT = 32;
	const int INDEX_ARRAY_COUNT = 6;
	const int VERTEX_SIZE = 8;

	glm::vec3 colorVector;

	Animation* animation;
	Texture texture;

public:
	Sprite(Renderer* newRenderer, string path);
	~Sprite();

	int heightTexture;
	int widthTexture;

	void AttachMaterial();
	void DetachMaterial();
	void Draw(GLsizei vertices);
	void DrawWithIndexBuffer(GLsizei indices);

	void SetColor(glm::vec3);
	glm::vec3 GetColor();

	void DrawSprite();
};

#endif 