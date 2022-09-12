#ifndef MATERIAL_H
#define MATERIAL_H

#include <glew.h>
#include <glfw3.h>
#include <iostream>
#include "Export.h"
using namespace std;

class DllImport Material
{
private:

public:
	Material();
	~Material();
    void LoadShaders(const char* vertexPath, const char* fragmentPath);
    static unsigned int CompilerShader(unsigned int type, const string& source);
    static unsigned int CreateMaterial(const string& vertexShader, const string& fragmentShader);
    void UseMaterial(GLuint program);
    void DeleteMaterial(GLuint program);
};

#endif   