
#ifndef Triangle_hpp
#define Triangle_hpp

#include <iostream>
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
    Triangle(int verticesSize = sizeof(ver), float * vertices = ver);
    
    // getters
    
    // public member
    void render();
    void clear();
private:
    ShaderLoader _shader;
    int _verticesSize;
    float * _vertices;
    GLuint vbo, vao;
};

#endif /* Triangle_hpp */
