#include "VertexArray.h"

liVertexArray::liVertexArray() {
    this->vbo = nullptr;
    this->ibo = nullptr;
    this->usesIndexBuffer = false;
}

liVertexArray::~liVertexArray() {
}

void liVertexArray::Initialize() {
    glGenVertexArrays(1, &handle);
}

void liVertexArray::Delete() {
    glDeleteVertexArrays(1, &handle);
}

void liVertexArray::CalculateHash() {
    this->hash = 0;
}

void liVertexArray::SetVertexBuffer(liVertexBuffer* vbo) {
    this->vbo = vbo;
}

void liVertexArray::SetIndexBuffer(liIndexBuffer* ibo) {
    this->ibo = ibo;
    this->usesIndexBuffer = ibo ? true : false;
}

void liVertexArray::Bind() {
    glBindVertexArray(handle);
}

void liVertexArray::Unbind() {
    glBindVertexArray(0);
}