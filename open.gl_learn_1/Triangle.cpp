#include "Triangle.hpp"


Triangle::Triangle(float * vertices) :
    _vertices(vertices)
{
    glGenBuffers(1, &vbo);
    glBindBuffer(GL_ARRAY_BUFFER, vbo);
    glBufferData(GL_ARRAY_BUFFER, sizeof(_vertices), _vertices, GL_STATIC_COPY);
}

float * Triangle::getVertices()
{
    return _vertices;
}

void Triangle::render()
{

}
