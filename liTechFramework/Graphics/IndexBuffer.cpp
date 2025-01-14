#include "IndexBuffer.h"

liIndexBuffer::liIndexBuffer(liIntBuffer* data) {
    this->data = data;
    this->size = data ? data->size() : 0;
}

liIndexBuffer::~liIndexBuffer() {
}

void liIndexBuffer::Initialize() {
    glGenBuffers(1, &handle);
}

void liIndexBuffer::Delete() {
    glDeleteBuffers(1, &handle);
}

void liIndexBuffer::CalculateHash() {
    this->hash = 0;
}