#version 330 core

in vec2 position;

void main()
{
    gl_Position = vec4(position, 0.0, 1.0); // positions from 0 to 1(ass screen)
}
