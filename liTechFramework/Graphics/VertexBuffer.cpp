#include "VertexBuffer.h"

liVertexBuffer::liVertexBuffer(void** data, ulong_t size) {
    this->data = data;
    this->size = size;
}

liVertexBuffer::~liVertexBuffer() {
}

void liVertexBuffer::Initialize() {
    glGenBuffers(1, &handle);
}

void liVertexBuffer::Delete() {
    glDeleteBuffers(1, &handle);
}

void liVertexBuffer::CalculateHash() {
    this->hash = 0;
}