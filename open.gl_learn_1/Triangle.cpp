#include "Triangle.hpp"

using namespace std;

Triangle::Triangle(GLint verticesSize, GLfloat * vertices, GLint elementsSize, GLuint * elements) :
    _shader(ShaderLoader("resources/shaders/core.vs", "resources/shaders/core.frag")),
    _verticesSize(verticesSize),
    _vertices(vertices),
    _elementsSize(elementsSize),
    _elements(elements)
{
    glGenBuffers(1, &ebo);
    glGenVertexArrays(1, &vao);
    glGenBuffers(1, &vbo);
    
    glBindVertexArray(vao);
    
    glBindBuffer(GL_ARRAY_BUFFER, vbo);
    glBufferData(GL_ARRAY_BUFFER, _verticesSize, _vertices, GL_STATIC_DRAW);
    
    glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, ebo);
    glBufferData(GL_ELEMENT_ARRAY_BUFFER, _elementsSize, _elements, GL_STATIC_DRAW);

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
    
    glDrawElements(GL_TRIANGLES, 6, GL_UNSIGNED_INT, 0);
}


void Triangle::clear()
{
    glDeleteProgram(_shader.getProgram());    
    glDeleteBuffers(1, &vbo);
    glDeleteVertexArrays(1, &vao);
}
