
#ifndef Triangle_hpp
#define Triangle_hpp

#include <iostream>
#include <GL/glew.h>
#include <math.h>

#include "ShaderLoader.hpp"

static GLfloat ver[] = {
    -0.5f,  0.5f, 1.0f, 0.0f, 0.0f, // Top-left
    0.5f,  0.5f, 0.0f, 1.0f, 0.0f, // Top-right
    0.5f, -0.5f, 0.0f, 0.0f, 1.0f, // Bottom-right
    -0.5f, -0.5f, 1.0f, 1.0f, 1.0f  // Bottom-left
};

static GLuint elems[] = {
    0, 1, 2,
    2, 3, 0
};

class Triangle
{
public:
    Triangle(GLint verticesSize = sizeof(ver), GLfloat * vertices = ver, GLint elementsSize = sizeof(elems), GLuint * elements = elems);

    // public member
    void alterAttributes();
    void render();
    void clear();
private:
    ShaderLoader _shader;

    GLint _verticesSize;
    GLfloat * _vertices;
    
    GLint _elementsSize;
    GLuint * _elements;
    

    GLuint vbo, vao, ebo;

    GLint posAttrib;
    GLint colAttrib;
};

#endif /* Triangle_hpp */
