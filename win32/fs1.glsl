#version 330 

in vec2 TexCoords;
uniform vec2 test;
out vec4 color;

uniform sampler2D texture_diffuse1;

void main()
{    
    color = vec4(texture(texture_diffuse1, TexCoords));
}