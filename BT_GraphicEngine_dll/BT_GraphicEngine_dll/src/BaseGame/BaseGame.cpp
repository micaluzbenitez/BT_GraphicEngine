#include "BaseGame.h"

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

/* Create shader */
static unsigned int CompilerShader(unsigned int type, const string& source)
{
    unsigned int id = glCreateShader(GL_VERTEX_SHADER);
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

static unsigned int CreateShader(const string& vertexShader, const string& fragmentShader)
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
/* ------------- */

void BaseGame::RunBaseGame()
{    
    if (Init())
    {
        /* Loop until the user closes the window */
        while (!_window->WindowShouldClose())
        {
            Update();
            Draw();
        }

        Deinit();
    }
    else
    {
        cout << "Error creating the window";
    }
}

bool BaseGame::Init()
{
    _window = new Window();
    _renderer = new Renderer();

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
    string vertexShader = 
        "#version 330 core\n"
        "\n"
        "layout(location = 0) in vec4 position;"
        "\n"
        "void main()\n"
        "{\n"
        "   gl_Position = position;\n"
        "}\n";

    string fragmentShader =
        "#version 330 core\n"
        "\n"
        "layout(location = 0) out vec4 color;"
        "\n"
        "void main()\n"
        "{\n"
        "   color = vec4(1.0, 0.0, 0.0, 1.0);\n"
        "}\n";

    unsigned int shader = CreateShader(vertexShader, fragmentShader);
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
 