#include "BaseGame.h"

#include <fstream>
#include <string>
#include <sstream>

struct ShaderProgramSource
{
    string VertexSource;
    string FragmentSource;
};

static ShaderProgramSource ParseShader(const string& filepath)
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

BaseGame::BaseGame()
{
    _renderer = nullptr;
    _window = nullptr;
}

BaseGame::~BaseGame()
{
    if (_window != nullptr) {
        _window = nullptr;
        delete _window;
    }
    
    if (_renderer != nullptr) {
        _renderer = nullptr;
        delete _renderer;
    }
}

void BaseGame::RunBaseGame()
{    
    if (Init())
    {
        while (!_window->WindowShouldClose())
        {
            Update();
            Draw();
        }
        Deinit();
    }
    else cout << "Error creating the window";
}

bool BaseGame::Init()
{
    _window = new Window();
    _renderer = new Renderer();
    _material = new Material();

    /* Initialize the library */
    _window->InitLibrary();                              

    /* Create a windowed mode window and its OpenGL context */
    _window->CreateWindow();

    /* Make the window's context current */
    _window->MakeWindowContextCurrent();

    /* GLEW init */
    _renderer->InitGLEW();

    /* GLEW buffer */
    float positions[6] =
    {
        -0.5f, -0.5f,
         0.0f,  0.5f,
         0.5f, -0.5f
    };
    
    unsigned int buffer;
    _renderer->AssignVertexBuffer(1, buffer);
    _renderer->SetVertexBufferTarget(GL_ARRAY_BUFFER, buffer);
    _renderer->SetVertexBufferData(GL_ARRAY_BUFFER, 6 * sizeof(float), positions, GL_STATIC_DRAW);

    /* GLEW enabled vertex attrib */
    _renderer->EnableVertexAttribArray(0);
    _renderer->DefineVertexAttribPointer(0, 2, GL_FLOAT, GL_FALSE, sizeof(float) * 2, 0);
    
    /* Create shader */
    ShaderProgramSource source = ParseShader("shaders/Basic.shader");
    cout << "VERTEX" << endl;
    cout << source.VertexSource << endl;
    cout << "FRAGMENT" << endl;
    cout << source.FragmentSource << endl;
    unsigned int shader = _material->CreateMaterial(source.VertexSource, source.FragmentSource);
    glUseProgram(shader);
    /* ------------- */

    return _window != nullptr;
}

void BaseGame::Update()
{
    /* Poll for and process events */
    _window->PollEvents();
}

void BaseGame::Draw()
{
    _renderer->ClearScreen();
    //_renderer->ClearScreenWithColor(1, 0, 0, 1);

    /* GLEW draw mode */
    _renderer->DrawWithoutIndexBuffer(GL_TRIANGLES, 0, 3);

    /* Swap front and back buffers */
    _renderer->SwapBuffers(_window->GetWindow());
}

void BaseGame::Deinit()
{
    //glDeleteProgram(shader);
    _window->TerminateLibrary();
}
 