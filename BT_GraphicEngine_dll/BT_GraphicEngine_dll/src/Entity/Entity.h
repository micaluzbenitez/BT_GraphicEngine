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
	glm::vec3 rotationVector;
	glm::quat rotationQuaternion;
	glm::vec3 scaleVector;
	
	glm::quat EulerToQuat(glm::vec3 euler);
	glm::mat4 EulerToMat4(glm::vec3 euler);
	glm::vec3 QuaternionToEuler(glm::quat quat);
	glm::vec3 QuatToVec(glm::quat quat, glm::vec3 euler);
	glm::quat QuaternionLookRotation(glm::vec3 forward, glm::vec3 upwards);	
	
public: 
	Entity();
	~Entity();

	void UpdateModelMatrix();
	glm::mat4 GetModelMatrix();

	void SetPosition(float x, float y, float z);
	void SetRotation(float x, float y, float z);
	void SetScale(float x, float y, float z);

	glm::vec3 GetPosition();
	glm::vec3 GetRotation();
	glm::vec3 GetScale();
	
	void Translate(float x, float y, float z);
	void Rotate(float x, float y, float z);
	void Scale(float x, float y, float z);

	virtual void Draw() = 0;
};

#endif