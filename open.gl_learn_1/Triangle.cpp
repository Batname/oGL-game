#include "Triangle.hpp"


Triangle::Triangle(ShaderLoader * shader, float * vertices) :
    _vertices(vertices),
    _shader(shader)
{
    glGenVertexArrays(1, &vao);
    glGenBuffers(1, &vbo);
    
    glBindVertexArray(vao);
    
    glBindBuffer(GL_ARRAY_BUFFER, vbo);
    glBufferData(GL_ARRAY_BUFFER, sizeof(_vertices), _vertices, GL_STATIC_COPY);

    GLint posAttrib = glGetAttribLocation(shader->getProgram(), "position");
    glVertexAttribPointer(posAttrib, 2, GL_FLOAT, GL_FALSE, 0, 0);
    glEnableVertexAttribArray(posAttrib);
}

float * Triangle::getVertices()
{
    return _vertices;
}

void Triangle::render()
{
    _shader->use();
    glBindVertexArray(vao);
    glDrawArrays(GL_TRIANGLES, 0, 3);
    glBindVertexArray(0);
}
