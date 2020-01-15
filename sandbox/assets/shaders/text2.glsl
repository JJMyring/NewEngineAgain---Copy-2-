#region Vertex

#version 440 core
			
layout(location = 0) in vec2 a_vertexPosition;
layout(location = 1) in vec2 a_texCoord;
layout(location = 2) in vec3 a_colour;

out vec2 texCoord;
out vec3 charColour;

layout (std140) uniform Matrices
{
	uniform mat4 u_projection;
	uniform mat4 u_view;
};

void main()
{
	texCoord = a_texCoord;
	charColour = a_colour;
	gl_Position =  u_projection * u_view * vec4(a_vertexPosition, 0, 1);
}

#region Fragment

#version 440 core
			
layout(location = 0) out vec4 colour;

in vec2 texCoord;
in vec3 charColour;

uniform sampler2D u_texData;

void main()
{
	colour = vec4(1.0, 1.0, 1.0, texture(u_texData, texCoord).r) * vec4(charColour, 1.0);
	//colour = vec4(1.0, 1.0, 1.0, 1.0);
}