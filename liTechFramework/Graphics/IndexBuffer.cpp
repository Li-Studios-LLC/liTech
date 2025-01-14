#include "IndexBuffer.h"

liIndexBuffer::liIndexBuffer(liIntBuffer* data) {
    this->data = data;
    this->size = data ? data->size() : 0;
    Initialize();
}

liIndexBuffer::~liIndexBuffer() {
    Delete();
}

void liIndexBuffer::Initialize() {
    glGenBuffers(1, &handle);

    glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, handle);
    glBufferData(GL_ELEMENT_ARRAY_BUFFER, size * sizeof(int), data->data(), GL_STATIC_DRAW);
    glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, 0);
}

void liIndexBuffer::Delete() {
    glDeleteBuffers(1, &handle);
}

void liIndexBuffer::CalculateHash() {
    this->hash = 0;
}

void liIndexBuffer::Bind() {
    glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, handle);
}

void liIndexBuffer::Unbind() {
    glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, 0);
}