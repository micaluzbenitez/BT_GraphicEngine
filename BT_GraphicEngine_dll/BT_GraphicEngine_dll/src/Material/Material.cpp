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
    ID = glCreateShader(type);
    const char* src = source.c_str();
    glShaderSource(ID, 1, &src, nullptr);
    glCompileShader(ID);

    int result;
    glGetShaderiv(ID, GL_COMPILE_STATUS, &result);
    if (result == GL_FALSE)
    {
        int length;
        glGetShaderiv(ID, GL_INFO_LOG_LENGTH, &length);
        char* message = (char*)alloca(length * sizeof(char));
        glGetShaderInfoLog(ID, length, &length, message);
        cout << "Failed to compile shader " << (type == GL_VERTEX_SHADER ? "vertex" : "fragment") << " shader!" << endl;
        cout << message << endl;
        glDeleteShader(ID);
        return 0;
    }

    return ID;
}

void Material::CreateMaterial(const string& vertexShader, const string& fragmentShader)
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

    ID = program;
}

 void Material::UseMaterial()
 {
     glUseProgram(ID);
 }

 void Material::ModifyMaterial(glm::mat4 projectionMatrix, glm::mat4 viewMatrix, glm::mat4 modelMatrix)
 {
     unsigned int projectionUbication = glGetUniformLocation(ID, "projection");
     glUniformMatrix4fv(projectionUbication, 1, GL_FALSE, glm::value_ptr(projectionMatrix));
     unsigned int viewUbication = glGetUniformLocation(ID, "view");
     glUniformMatrix4fv(viewUbication, 1, GL_FALSE, glm::value_ptr(viewMatrix));
     unsigned int modelUbication = glGetUniformLocation(ID, "model");
     glUniformMatrix4fv(modelUbication, 1, GL_FALSE, glm::value_ptr(modelMatrix));
 }

 void Material::DeleteMaterial()
 {
     glDeleteProgram(ID);
 }