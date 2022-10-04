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
	
	glm::mat4 model;

	glm::mat4 translateMatrix;
	glm::mat4 rotationMatrix;
	glm::mat4 scaleMatrix;

	glm::vec3 translateVector;
	//glm::quat rotationQuaternion;
	glm::vec3 rotationVector;
	glm::vec3 scaleVector;
	/*
	glm::quat EulerToQuat(glm::vec3 euler);
	glm::vec3 QuatToVec(glm::quat quat, glm::vec3 euler);
	glm::quat QuaternionLookRotation(glm::vec3 forward, glm::vec3 upwards);
	*/
public: 
	Entity();
	~Entity();

	void SetPosition(float x, float y, float z);
	void SetRotation(float x, float y, float z);
	void SetScale(float x, float y, float z);

	glm::vec3 GetPosition();
	//glm::quat GetRotation();
	glm::vec3 GetRotation();
	glm::vec3 GetScale();
	/*
	void Translate(float x, float y, float z);
	void Rotate(float x, float y, float z);
	void Scale(float x, float y, float z);
	*/

	virtual void Draw(GLsizei vertices) = 0;
	virtual void DrawWithIndexBuffer(GLsizei indices) = 0;
};

#endif