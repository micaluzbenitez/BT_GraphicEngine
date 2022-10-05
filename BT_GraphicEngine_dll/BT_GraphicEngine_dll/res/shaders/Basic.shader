#shader vertex
#version 330 core

layout(location = 0) in vec3 position;
layout(location = 1) in vec3 inColor;

out vec3 outColor;

uniform mat4 projection;
uniform mat4 view;
uniform mat4 model;
void main()
{
	gl_Position = projection * view * model * vec4(position, 1.0);
   outColor = inColor;
};

#shader fragment
#version 330 core

uniform vec3 color;
out vec4 fragColor;
in vec3 outColor;

void main()
{
   fragColor = vec4(color * outColor, 1.0);
};