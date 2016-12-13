
#ifndef Triangle_hpp
#define Triangle_hpp

#include <stdio.h>
#include <GL/glew.h>

#include "ShaderLoader.hpp"

static float ver[] = {
    0.0f,  0.5f,
    0.5f, -0.5f,
    -0.5f, -0.5f,
};


class Triangle
{
public:
    Triangle(ShaderLoader *_shader, float * vertices = ver);
    
    // getters
    float * getVertices();
    
    // public member
    void render();
private:
    ShaderLoader *_shader;
    float * _vertices;
    GLuint vbo, vao;
};

#endif /* Triangle_hpp */
