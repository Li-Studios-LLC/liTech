#include "pch.h"
#include "ShaderProgram.h"
#include "RenderShader.h"
#include "ComputeShader.h"

liShaderProgram::liShaderProgram() {
    this->program = glCreateProgram();
}

liShaderProgram::~liShaderProgram() {
    glDeleteProgram(program);
}

bool liShaderProgram::Link(std::unordered_map<int, std::string> attribs) {
    glLinkProgram(program);
    int status;
    glGetProgramiv(program, GL_LINK_STATUS, &status);
    if(!status) {
        int length = 0;
        char message[1024];
        glGetProgramInfoLog(program, 1024, &length, message);
        std::cerr << "Shader program link error: " << message;
        return false;
    }
    for(ulong_t i = 0; i < attribs.size(); i++) {
        glBindAttribLocation(program, i, attribs[i].c_str());
    }
    return true;
}

void liShaderProgram::Bind() const {
    glUseProgram(program);
}

void liShaderProgram::LoadTexture(std::string name, ghandle_t handle) {
    int index = glGetUniformLocation(program, name.c_str());
    glUniform1i(index, handle);
}