
#ifndef Triangle_hpp
#define Triangle_hpp

#include <stdio.h>
#include <GL/glew.h>

static float ver[] = {
    0.0f,  0.5f,
    0.5f, -0.5f,
    -0.5f, -0.5f,
};


class Triangle
{
public:
    Triangle(float * vertices = ver);
    
    // getters
    float * getVertices();
    
    // public member
    void render();
private:
    float * _vertices;
    GLuint vbo;
};

#endif /* Triangle_hpp */
