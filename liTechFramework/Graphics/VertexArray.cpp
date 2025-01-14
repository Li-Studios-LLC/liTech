#include "VertexArray.h"

liVertexArray::liVertexArray() {
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