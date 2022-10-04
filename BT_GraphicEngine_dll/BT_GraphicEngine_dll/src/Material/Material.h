#ifndef MATERIAL_H
#define MATERIAL_H

#include <glew.h>
#include <glfw3.h>
#include <iostream>
#include "glm/glm.hpp"
#include "glm/gtc/matrix_transform.hpp"
#include "glm/gtc/type_ptr.hpp"
#include "Export.h"
using namespace std;

struct ShaderProgramSource
{
    string VertexSource;
    string FragmentSource;
};

class DllApi Material
{
private:
    unsigned int ID;

public:
	Material();
	~Material();
    ShaderProgramSource ParseShader(const string& filepath);
    unsigned int CompilerShader(unsigned int type, const string& source);
    unsigned int CreateMaterial(const string& vertexShader, const string& fragmentShader);
    void UseMaterial(GLuint program);
    void ModifyMaterial(GLuint program, glm::mat4 projectionMatrix, glm::mat4 viewMatrix, glm::mat4 modelMatrix);
    void DeleteMaterial(GLuint program);
};

#endif   