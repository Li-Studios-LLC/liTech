#include "Mesh.h"

#define VAO_HANDLE 0
#define VBO_HANDLE 1
#define IBO_HANDLE 2

liMesh::liMesh() {
	this->geometry = liNew<liGeometry<>>();
	LITECH_ADD_RESOURCE(geometry);
	Initialize();
}

liMesh::liMesh(liGeometry<>* geometry) {
	this->geometry = geometry;
	Initialize();
}

liMesh::~liMesh() {
	Delete();
}

void liMesh::Initialize() {
	glGenVertexArrays(1, &handles[VAO_HANDLE]);
	glBindVertexArray(handles[VAO_HANDLE]);
	glGenBuffers(1, &handles[VBO_HANDLE]);

	glBindBuffer(GL_ARRAY_BUFFER, handles[VBO_HANDLE]);
	glBufferData(GL_ARRAY_BUFFER, geometry->VertexCount() * sizeof(liVertex3D), geometry->Vertices(), GL_STATIC_DRAW);

    glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, sizeof(liVertex3D), (void*)0);
    glEnableVertexAttribArray(0);

    glVertexAttribPointer(1, 2, GL_FLOAT, GL_FALSE, sizeof(liVertex3D), (void*)offsetof(liVertex3D, texCoord));
    glEnableVertexAttribArray(1);

    glVertexAttribPointer(2, 3, GL_FLOAT, GL_FALSE, sizeof(liVertex3D), (void*)offsetof(liVertex3D, normal));
    glEnableVertexAttribArray(2);

	glGenBuffers(1, &handles[IBO_HANDLE]);
	glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, handles[IBO_HANDLE]);
	glBufferData(GL_ELEMENT_ARRAY_BUFFER, geometry->IndexCount() * sizeof(uint_t), geometry->Indices(), GL_STATIC_DRAW);

	glBindVertexArray(0);
	CalculateHash();
}

void liMesh::Delete() {
	glDeleteBuffers(2, &handles[VBO_HANDLE]);
	glDeleteVertexArrays(1, &handles[VAO_HANDLE]);
}

void liMesh::CalculateHash() {
	this->hash = geometry->Hash();
}

void liMesh::Draw(drawRange_t range, meshTopology_t topology) {
	glBindVertexArray(handles[VAO_HANDLE]);
    uint_t type;
	uint_t count = range.count;
	if(range.count == -1) {
		count = geometry->IndexCount();
	}
    switch(topology) {
    case meshTopology_t::LINES:
        type = GL_LINES;
        break;
    case meshTopology_t::POINTS:
        type = GL_POINTS;
        break;
    case meshTopology_t::TRIANGLES:
        type = GL_TRIANGLES;
        break;
    }
    glDrawElements(type, count, GL_UNSIGNED_INT, (void*)(range.start * sizeof(uint_t)));
    glBindVertexArray(0);
}