#include "Material.h"
#include <fstream>
#include <string>
#include <sstream>

Material::Material()
{
}

Material::~Material()
{
}

ShaderProgramSource Material::ParseShader(const string& filepath)
{
    ifstream stream(filepath);

    enum class ShaderType
    {
        NONE = -1, VERTEX = 0, FRAGMENT = 1
    };

    string line;
    stringstream ss[2];
    ShaderType type = ShaderType::NONE;
    while (getline(stream, line))
    {
        if (line.find("#shader") != string::npos)
        {
            if (line.find("vertex") != string::npos)
                type = ShaderType::VERTEX;
            else if (line.find("fragment") != string::npos)
                type = ShaderType::FRAGMENT;
        }
        else
        {
            ss[(int)type] << line << "\n";
        }
    }

    return { ss[0].str(), ss[1].str() };
}

unsigned int Material::CompilerShader(unsigned int type, const string& source)
{
    unsigned int id = glCreateShader(type);
    const char* src = source.c_str();
    glShaderSource(id, 1, &src, nullptr);
    glCompileShader(id);

    int result;
    glGetShaderiv(id, GL_COMPILE_STATUS, &result);
    if (result == GL_FALSE)
    {
        int length;
        glGetShaderiv(id, GL_INFO_LOG_LENGTH, &length);
        char* message = (char*)alloca(length * sizeof(char));
        glGetShaderInfoLog(id, length, &length, message);
        cout << "Failed to compile shader " << (type == GL_VERTEX_SHADER ? "vertex" : "fragment") << " shader!" << endl;
        cout << message << endl;
        glDeleteShader(id);
        return 0;
    }

    return id;
}

unsigned int Material::CreateMaterial(const string& vertexShader, const string& fragmentShader)
{
    unsigned int program = glCreateProgram();
    unsigned int vs = CompilerShader(GL_VERTEX_SHADER, vertexShader);
    unsigned int fs = CompilerShader(GL_FRAGMENT_SHADER, fragmentShader);

    glAttachShader(program, vs); // Atachea los dos shaders al programa
    glAttachShader(program, fs);
    glLinkProgram(program); // Lo linkea
    glValidateProgram(program); // Valida que este todo bien

    glDeleteShader(vs);
    glDeleteShader(fs);

    return program;
}

 void Material::UseMaterial(GLuint program)
 {
     glUseProgram(program);
 }

 void Material::DeleteMaterial(GLuint program)
 {
     glDeleteProgram(program);
 }