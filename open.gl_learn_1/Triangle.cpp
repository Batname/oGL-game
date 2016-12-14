#include "Triangle.hpp"

Triangle::Triangle(int verticesSize, float * vertices) :
    _shader(ShaderLoader("resources/shaders/core.vs", "resources/shaders/core.frag")),
    _verticesSize(verticesSize),
    _vertices(vertices)
{
    glGenVertexArrays(1, &vao); // generate Vertex Array Objects
    glGenBuffers(1, &vbo); // Generate 1 buffer(Vertex Buffer Object)
    
    glBindVertexArray(vao);
    glBindBuffer(GL_ARRAY_BUFFER, vbo); // active vbo object

    glBufferData(GL_ARRAY_BUFFER, _verticesSize, _vertices, GL_STATIC_DRAW); // copy the vertex data to array buffer

    GLint posAttrib = glGetAttribLocation(_shader.getProgram(), "position"); // etrieve a reference to the position input in the vertex shader
    glVertexAttribPointer(posAttrib, 2, GL_FLOAT, GL_FALSE, 0, 0); // how the data for that input is retrieved from the array, 2 because it use 2 demention
    glEnableVertexAttribArray(posAttrib);
}

void Triangle::render()
{
    _shader.use();
    glDrawArrays(GL_TRIANGLES, 0, 3); // draw primitive from the 3 vertices
}


void Triangle::clear()
{
    glDeleteProgram(_shader.getProgram());    
    glDeleteBuffers(1, &vbo);
    glDeleteVertexArrays(1, &vao);
}
