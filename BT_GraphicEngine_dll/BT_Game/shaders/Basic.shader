#shader vertex
#version 330 core

layout(location = 0) in vec3 position;
layout(location = 1) in vec3 inColor;

out vec3 outColor;

uniform mat4 projection = mat4(1.0f);
uniform mat4 view = mat4(1.0f);
uniform mat4 model = mat4(1.0f);

void main()
{
   gl_Position = projection * view * model * vec4(position, 1.0);
   outColor = inColor;
};

#shader fragment
#version 330 core

out vec4 fragColor;
in vec3 outColor;

void main()
{
	fragColor = vec4(outColor, 1.0);
};