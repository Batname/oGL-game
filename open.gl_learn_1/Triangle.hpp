
#ifndef Triangle_hpp
#define Triangle_hpp

#include <iostream>
#include <GL/glew.h>
#include <math.h>

#include "ShaderLoader.hpp"

static float ver[] = {
    0.0f,  0.5f, 1.0f, 0.0f, 0.0f, // Vertex 1: Red
    0.5f, -0.5f, 0.0f, 1.0f, 0.0f, // Vertex 2: Green
    -0.5f, -0.5f, 0.0f, 0.0f, 1.0f  // Vertex 3: Blue
};

class Triangle
{
public:
    Triangle(int verticesSize = sizeof(ver), float * vertices = ver);

    // public member
    void alterAttributes();
    void render();
    void clear();
private:
    ShaderLoader _shader;

    int _verticesSize;
    float * _vertices;

    GLuint vbo, vao;

    GLint posAttrib;
    GLint colAttrib;
};

#endif /* Triangle_hpp */
