#include "Triangle.hpp"

using namespace std;

typedef std::chrono::high_resolution_clock Time;
using float_sec = std::chrono::duration<float>;

static auto t_start = Time::now();

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

    posAttrib = glGetAttribLocation(_shader.getProgram(), "position");
    glVertexAttribPointer(posAttrib, 2, GL_FLOAT, GL_FALSE, 0, 0);
    glEnableVertexAttribArray(posAttrib);
    
    uniColor = glGetUniformLocation(_shader.getProgram(), "triangleColor");
    
    _shader.use();
}

void Triangle::render()
{
    auto t_now = Time::now();
    float time = chrono::duration_cast<float_sec>(t_now - t_start).count();
    
    glUniform3f(uniColor, (sin(time * 4.0f) + 1.0f) / 2.0f, 0.0f, 0.0f);
    glDrawArrays(GL_TRIANGLES, 0, 3); // draw primitive from the 3 vertices
}


void Triangle::clear()
{
    glDeleteProgram(_shader.getProgram());    
    glDeleteBuffers(1, &vbo);
    glDeleteVertexArrays(1, &vao);
}
