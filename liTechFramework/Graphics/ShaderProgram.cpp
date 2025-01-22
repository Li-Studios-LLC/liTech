#include "ShaderProgram.h"

liShaderProgram::liShaderProgram() {
    Initialize();
}

liShaderProgram::~liShaderProgram() {
    Delete();
}

void liShaderProgram::Initialize() {
    this->handles[0] = glCreateProgram();
    this->vertex = nullptr;
    this->pixel = nullptr;
    this->compute = nullptr;
}

void liShaderProgram::Delete() {
    glDeleteProgram(handles[0]);
}

void liShaderProgram::CalculateHash() {
    this->hash = (vertex ? vertex->Hash() : 0) + (pixel ? pixel->Hash() : 0) + (compute ? compute->Hash() : 0);
}

int liShaderProgram::Link(shaderType_t type) {
    glLinkProgram(handles[0]);
    int status;
    glGetProgramiv(handles[0], GL_LINK_STATUS, &status);
    if(!status) {
        return LITECH_BAD;
    }
    glBindAttribLocation(handles[0], 0, "position");
    glBindAttribLocation(handles[0], 1, "texCoords");

    switch (type) {
    case shaderType_t::MAIN:
        glBindAttribLocation(handles[0], 2, "normals");
        break;
    case shaderType_t::UI:
    case shaderType_t::CANVAS:
    default:
        break;
    }

    return LITECH_OK;
}

void liShaderProgram::SetVertex(liShader* vertex) {
    this->vertex = vertex;
    _Attach(vertex);
}

void liShaderProgram::SetPixel(liShader* pixel) {
    this->pixel = pixel;
    _Attach(pixel);
}

void liShaderProgram::SetCompute(liShader* compute) {
    this->compute = compute;
    _Attach(compute);
}

void liShaderProgram::Bind() const {
    glUseProgram(handles[0]);
}

void liShaderProgram::Unbind() {
    glUseProgram(0);
}

void liShaderProgram::_Attach(liShader* shader) { 
    glUseProgram(handles[0]);
    glAttachShader(handles[0], vertex->GetHandle());
    glUseProgram(0);
}