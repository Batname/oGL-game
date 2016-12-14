
#ifndef Triangle_hpp
#define Triangle_hpp

#include <iostream>
#include <GL/glew.h>

#include "ShaderLoader.hpp"

class Triangle
{
public:
    Triangle(ShaderLoader *_shader);
    
    // getters
    
    // public member
    void render();
private:
    ShaderLoader *_shader;
    GLuint vbo, vao;
};

#endif /* Triangle_hpp */
