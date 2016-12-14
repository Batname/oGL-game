#include "Triangle.hpp"

using namespace std;

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

    alterAttributes();    
    _shader.use();
}

void Triangle::alterAttributes()
{
    // Position attribute
    posAttrib = glGetAttribLocation(_shader.getProgram(), "position");
    glVertexAttribPointer(posAttrib, 2, GL_FLOAT, GL_FALSE, (5 * sizeof(GLfloat)), (GLvoid*)0);
    glEnableVertexAttribArray(posAttrib);
    
    // Color attribute
    colAttrib = glGetAttribLocation(_shader.getProgram(), "color");
    glVertexAttribPointer(colAttrib, 3, GL_FLOAT, GL_FALSE, (5 * sizeof(GLfloat)), (GLvoid*)(2 * sizeof(GLfloat)));
    glEnableVertexAttribArray(colAttrib);
}

void Triangle::render()
{
    
    glUniform3f(posAttrib, 0.5f, 0.0f, 0.0f);
    glDrawArrays(GL_TRIANGLES, 0, 3); // draw primitive from the 3 vertices
}


void Triangle::clear()
{
    glDeleteProgram(_shader.getProgram());    
    glDeleteBuffers(1, &vbo);
    glDeleteVertexArrays(1, &vao);
}
