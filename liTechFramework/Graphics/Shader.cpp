#include "Shader.h"
#include "Utility/Hash.h"

liShader::liShader(shaderDesignation_t designation) {
    this->designation = designation;
    Initialize();
}

liShader::~liShader() {
    Delete();
}

void liShader::Initialize() {
    this->handles[0] = glCreateShader(_GetShaderDesignation(designation));
}

void liShader::Delete() {
    glDeleteShader(handles[0]);
}

int liShader::Compile(const std::string& src) {
    this->hash = liTechHash(src);

    const char* str = src.c_str();
    glShaderSource(handles[0], 1, &str, nullptr);
    glCompileShader(handles[0]);

    GLint compiled;
    glGetShaderiv(handles[0], GL_COMPILE_STATUS, &compiled);
    if (!compiled) {
        int log_length = 0;
        char message[1024];
        glGetShaderInfoLog(handles[0], 1024, &log_length, message);
        liTechPrint("Shader compilation error: %s", message);
        return LITECH_BAD;
    }
    return LITECH_OK;
}

uint_t liShader::_GetShaderDesignation(shaderDesignation_t designation) {
    switch (designation) {
    case shaderDesignation_t::VERTEX:
        return GL_VERTEX_SHADER;
    case shaderDesignation_t::PIXEL:
        return GL_FRAGMENT_SHADER;
    case shaderDesignation_t::COMPUTE:
    default:
        return GL_COMPUTE_SHADER;
    }
}