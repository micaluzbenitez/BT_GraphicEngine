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
	GLuint ID;
public:
	Material();
	~Material();
    void LoadShaders(const char* vertexPath, const char* fragmentPath);
    static unsigned int CompilerShader(unsigned int type, const string& source);
    void CreateMaterial(const string& vertexShader, const string& fragmentShader);
    void UseMaterial();
};

#endif   