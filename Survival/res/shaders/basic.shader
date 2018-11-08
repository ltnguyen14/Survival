#shader vertex
#version 330 core

layout(location = 0) in vec3 position;
layout(location = 1) in vec2 texCoord;

out vec2 v_TexCoord;

uniform mat4 u_VP;
uniform mat4 u_M;

void main()
{
	gl_Position = u_VP * u_M * vec4(position, 1.0f);
	v_TexCoord = texCoord;
};


#shader fragment
#version 330 core

out vec4 color;

in vec2 v_TexCoord;
uniform sampler2D u_Texture;

void main()
{
	vec4 texColor = texture(u_Texture, v_TexCoord);
	color = texColor;
};