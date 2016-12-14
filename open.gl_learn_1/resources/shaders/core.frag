#version 330 core

in vec3 Color; // from .vs
out vec4 ourColor;

void main()
{
    ourColor = vec4(Color, 1.0); // set color for our veticis
}
