#include "ShaderProgram.h"
#include "Math/Matrices.h"

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
    CalculateHash();

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

void liShaderProgram::ClearUniforms() {
    uniforms.clear();
}

void liShaderProgram::Load(std::string name, int v) {
    glUniform1i(_GetUniformLocation(name), v);
}

void liShaderProgram::Load(std::string name, float v) {
    glUniform1f(_GetUniformLocation(name), v);
}

void liShaderProgram::Load(std::string name, liVector2f vec) {
    glUniform2f(_GetUniformLocation(name), vec.x, vec.y);
}

void liShaderProgram::Load(std::string name, liVector3f vec) {
    glUniform3f(_GetUniformLocation(name), vec.x, vec.y, vec.z);
}

void liShaderProgram::Load(std::string name, liVector4f vec) {
    glUniform4f(_GetUniformLocation(name), vec.x, vec.y, vec.z, vec.w);
}

void liShaderProgram::Load(std::string name, liMatrix4f mat) {
    glUniformMatrix4fv(_GetUniformLocation(name), 1, false, (float*)mat.vecs);
}

void liShaderProgram::_Attach(liShader* shader) { 
    glUseProgram(handles[0]);
    glAttachShader(handles[0], vertex->GetHandle());
    glUseProgram(0);
}

int liShaderProgram::_GetUniformLocation(std::string name) {
    if(uniforms.find(name) != uniforms.end()) {
        return uniforms[name];
    } else {
        int location = glGetUniformLocation(handles[0], name.c_str());
        uniforms.emplace(name, location);
        return location;
    }
}