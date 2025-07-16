#include "pch.h"
#include "RenderShader.h"
#include "ShaderProgram.h"

liRenderShader::liRenderShader() {
    this->vertex = glCreateShader(GL_VERTEX_SHADER);
    this->pixel = glCreateShader(GL_FRAGMENT_SHADER);
}

liRenderShader::~liRenderShader() {
    glDeleteShader(pixel);
    glDeleteShader(vertex);
}

bool liRenderShader::CompileVertex(std::string_view source) {
    int length = source.length();
    const char* src = source.data();
    glShaderSource(vertex, 1, &src, &length);
    glCompileShader(vertex);
    int compiled;
    glGetShaderiv(vertex, GL_COMPILE_STATUS, &compiled);
    if(!compiled) {
        int length = 0;
        char message[1024];
        glGetShaderInfoLog(vertex, 1024, &length, message);
        std::cerr << "Shader compilation error: " << message;
        return false;
    }
    return true;
}

bool liRenderShader::CompilePixel(std::string_view source) {
    int length = source.length();
    const char* src = source.data();
    glShaderSource(pixel, 1, &src, &length);
    glCompileShader(pixel);
    int compiled;
    glGetShaderiv(vertex, GL_COMPILE_STATUS, &compiled);
    if(!compiled) {
        int length = 0;
        char message[1024];
        glGetShaderInfoLog(vertex, 1024, &length, message);
        std::cerr << "Shader compilation error: " << message;
        return false;
    }
    return true;
}

void liRenderShader::Attach(liShaderProgram* program) {
    program->renderShader = this;
    glAttachShader(program->program, vertex);
    glAttachShader(program->program, pixel);
}