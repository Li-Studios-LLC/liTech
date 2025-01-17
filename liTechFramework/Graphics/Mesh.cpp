#include "Mesh.h"

#define VAO_HANDLE 0
#define VBO_HANDLE 1
#define IBO_HANDLE 2

liMesh::liMesh() {
}

liMesh::liMesh(liGeometry<>* geometry) {
	this->geometry = geometry;
}

liMesh::~liMesh() {
}

void liMesh::Initialize() {
}

void liMesh::Delete() {
}

void liMesh::CalculateHash() {
	this->hash = 0;
}

void liMesh::Draw() {
}