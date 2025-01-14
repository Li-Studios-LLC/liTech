#include "VertexBuffer.h"

liVertexBuffer::liVertexBuffer() {
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