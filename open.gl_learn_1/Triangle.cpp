#include "Triangle.hpp"

Triangle::Triangle(int verticesSize, float * vertices) :
    _shader(ShaderLoader("resources/shaders/core.vs", "resources/shaders/core.frag")),
    _verticesSize(verticesSize),
    _vertices(vertices)
{
    glGenVertexArrays(1, &vao);
    glGenBuffers(1, &vbo);
    
    glBindVertexArray(vao);
    
    glBindBuffer(GL_ARRAY_BUFFER, vbo);

    glBufferData(GL_ARRAY_BUFFER, _verticesSize, _vertices, GL_STATIC_DRAW);

    GLint posAttrib = glGetAttribLocation(_shader.getProgram(), "position");
    glVertexAttribPointer(posAttrib, 2, GL_FLOAT, GL_FALSE, 0, 0);
    glEnableVertexAttribArray(posAttrib);
}

void Triangle::render()
{
    _shader.use();
    glBindVertexArray(vao);
    glDrawArrays(GL_TRIANGLES, 0, 3);
    glBindVertexArray(0);
}
