#ifndef ENTITY_H
#define ENTITY_H

#include <glew.h>
#include <glfw3.h>
#include "Renderer/Renderer.h"
#include "Export.h"
using namespace std;

class DllApi Entity //Quizas sea abstracta
{
protected:
	Renderer* renderer;

	unsigned int VBO; //Vertex Buffer Object
	unsigned int VAO; //Vertex Array Object
	unsigned int EBO; //Elements Buffer Object
	
	glm::mat4 transform;
	glm::vec3 translate;
	glm::vec3 rotation;
	glm::vec3 scale;

public: 
	Entity();
	~Entity();

	void SetPosition(float x, float y, float z);
	void SetRotation(float x, float y, float z);
	void SetScale(float x, float y, float z);

	glm::vec3 GetPosition();
	glm::vec3 GetRotation();
	glm::vec3 GetScale();

	virtual void Draw(GLsizei vertices) = 0;
	virtual void DrawWithIndexBuffer(GLsizei indices) = 0;
};

#endif