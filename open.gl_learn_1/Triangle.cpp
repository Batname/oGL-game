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
    glGenTextures(1, &tex);
    
    glBindVertexArray(vao);
    
    glBindBuffer(GL_ARRAY_BUFFER, vbo);
    glBufferData(GL_ARRAY_BUFFER, _verticesSize, _vertices, GL_STATIC_DRAW);
    
    glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, ebo);
    glBufferData(GL_ELEMENT_ARRAY_BUFFER, _elementsSize, _elements, GL_STATIC_DRAW);
    
    glBindTexture(GL_TEXTURE_2D, tex);

    loadTexture("resources/images/sample.png");
    alterAttributes();    
    _shader.use();
}

void Triangle::loadTexture(char * path)
{
    int width, height;
    unsigned char* image = SOIL_load_image(path, &width, &height, 0, SOIL_LOAD_RGB);
    glTexImage2D(GL_TEXTURE_2D, 0, GL_RGB, width, height, 0, GL_RGB, GL_UNSIGNED_BYTE, image);
    SOIL_free_image_data(image);
    
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_CLAMP_TO_EDGE);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_CLAMP_TO_EDGE);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);
}

void Triangle::alterAttributes()
{
    // Position attribute
    posAttrib = glGetAttribLocation(_shader.getProgram(), "position");
    glVertexAttribPointer(posAttrib, 2, GL_FLOAT, GL_FALSE, (7 * sizeof(GLfloat)), (GLvoid*)0);
    glEnableVertexAttribArray(posAttrib);
    
    // Color attribute
    colAttrib = glGetAttribLocation(_shader.getProgram(), "color");
    glVertexAttribPointer(colAttrib, 3, GL_FLOAT, GL_FALSE, (7 * sizeof(GLfloat)), (GLvoid*)(2 * sizeof(GLfloat)));
    glEnableVertexAttribArray(colAttrib);
    
    // Texture attribute
    texAttrib = glGetAttribLocation(_shader.getProgram(), "texcoord");
    glVertexAttribPointer(texAttrib, 2, GL_FLOAT, GL_FALSE,(7 * sizeof(GLfloat)), (GLvoid*)(5 * sizeof(GLfloat)));
    glEnableVertexAttribArray(texAttrib);
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
