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

class DllImport Material
{
private:
    GLuint ID;

public:
	Material();
	~Material();
    static ShaderProgramSource ParseShader(const string& filepath);
    static unsigned int CompilerShader(unsigned int type, const string& source);
    void CreateMaterial(const string& vertexShader, const string& fragmentShader);
    void UseMaterial();
    void DeleteMaterial();
};

#endif   