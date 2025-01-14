#include "Mesh.h"
#include "Utility/Heap.h"

liMesh::liMesh() {
    Initialize();
}

liMesh::~liMesh() {
    Delete();
}

void liMesh::Initialize() {
    this->vao = liNew<liVertexArray>();
}

void liMesh::Delete() {
    liDelete(vao);
}

void liMesh::CalculateHash() {
    this->hash = 0;
}

void liMesh::Draw() {
    vao->Bind();

    if(vao->UsesIndexBuffer()) {
    } else {
    }
    vao->Unbind();
}