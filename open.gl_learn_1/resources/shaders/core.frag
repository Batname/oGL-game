#version 330 core

uniform vec3 triangleColor;
out vec4 ourColor;

void main()
{
    ourColor = vec4(triangleColor, 1.0); // set color for our veticis
}
