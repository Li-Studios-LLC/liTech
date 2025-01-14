#include "VertexBuffer.h"

liVertexBuffer::liVertexBuffer(void** data, ulong_t size) {
    this->data = data;
    this->size = size;
    Initialize();
}

liVertexBuffer::~liVertexBuffer() {
    Delete();
}

void liVertexBuffer::Initialize() {
    glGenBuffers(1, &handle);

    glBindBuffer(GL_ARRAY_BUFFER, handle);
    glBufferData(GL_ARRAY_BUFFER, size * sizeof(float), *data, GL_STATIC_DRAW);
    glBindBuffer(GL_ARRAY_BUFFER, 0);
}

void liVertexBuffer::Delete() {
    glDeleteBuffers(1, &handle);
}

void liVertexBuffer::CalculateHash() {
    this->hash = 0;
}

void liVertexBuffer::Bind() {
    glBindBuffer(GL_ARRAY_BUFFER, handle);
}

void liVertexBuffer::Unbind() {
    glBindBuffer(GL_ARRAY_BUFFER, 0);
}