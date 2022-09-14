#ifndef MATERIAL_H
#define MATERIAL_H

#include <glew.h>
#include <glfw3.h>
#include <iostream>
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

public:
	Material();
	~Material();
    static ShaderProgramSource ParseShader(const string& filepath);
    static unsigned int CompilerShader(unsigned int type, const string& source);
    static unsigned int CreateMaterial(const string& vertexShader, const string& fragmentShader);
    void UseMaterial(GLuint program);
    void DeleteMaterial(GLuint program);
};

#endif   