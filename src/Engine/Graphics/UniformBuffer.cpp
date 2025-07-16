#include "pch.h"
#include "UniformBuffer.h"

liUniformBuffer::liUniformBuffer(ulong_t size) {
    this->size = size;
    glGenBuffers(1, &handle);
    glBindBuffer(GL_UNIFORM_BUFFER, handle);
    glBufferData(GL_UNIFORM_BUFFER, size, nullptr, GL_STATIC_DRAW);
    glBindBuffer(GL_UNIFORM_BUFFER, 0);
}

liUniformBuffer::~liUniformBuffer() {
    glDeleteBuffers(1, &handle);
}

void liUniformBuffer::Upload(void* data) {
    glBindBuffer(GL_UNIFORM_BUFFER, handle);
    glBufferSubData(GL_UNIFORM_BUFFER, 0, size, data);
    glBindBuffer(GL_UNIFORM_BUFFER, 0);
}

void liUniformBuffer::Bind(ghandle_t program, std::string name, int binding) {
    uint_t blockIndex = glGetUniformBlockIndex(program, name.c_str());
    glUniformBlockBinding(program, blockIndex, binding);
    glBindBufferBase(GL_UNIFORM_BUFFER, binding, handle);
}