#include "pch.h"
#include "Mesh.h"

liMesh::liMesh(ulong_t vertexCount, ulong_t drawCount) {
    this->vertexCount = vertexCount;
    this->drawCount = drawCount;
    glGenVertexArrays(1, &vao);
    glGenBuffers(2, &vbo);

    glBindVertexArray(vao);
    
    glBindBuffer(GL_ARRAY_BUFFER, vbo);
    glBufferData(GL_ARRAY_BUFFER, vertexCount * sizeof(liVertex), nullptr, GL_STATIC_DRAW);

    glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, sizeof(liVertex), (void*)0);
    glVertexAttribPointer(1, 2, GL_FLOAT, GL_FALSE, sizeof(liVertex), (void*)offsetof(liVertex, texCoord));
    glVertexAttribPointer(2, 3, GL_FLOAT, GL_FALSE, sizeof(liVertex), (void*)offsetof(liVertex, normal));
    
    glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, ibo);
    glBufferData(GL_ELEMENT_ARRAY_BUFFER, drawCount * sizeof(uint_t), nullptr, GL_STATIC_DRAW);

    glBindVertexArray(0);
}

liMesh::~liMesh() {
    glDeleteBuffers(2, &vbo);
    glDeleteVertexArrays(1, &vao);
}

void liMesh::UploadVertices(liVertexList* vertices) {
    glBindVertexArray(vao);
    
    glBindBuffer(GL_ARRAY_BUFFER, vbo);
    glBufferSubData(GL_ARRAY_BUFFER, 0, vertices->size() * sizeof(liVertex), vertices->data());

    glBindVertexArray(0);
}

void liMesh::UploadIndices(liUIntBuffer* indices) {
    glBindVertexArray(vao);
    
    glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, ibo);
    glBufferSubData(GL_ELEMENT_ARRAY_BUFFER, 0, indices->size() * sizeof(uint_t), indices->data());

    glBindVertexArray(0);
}

void liMesh::Draw(cullMode_t cull, topology_t topology, ulong_t start, long_t count) {
    ulong_t c = count;
    if(count < 0) {
        c = drawCount;
    }
    glCullFace((GLenum)cull);
    glBindVertexArray(vao);
    glEnableVertexAttribArray(0);
    glEnableVertexAttribArray(1);
    glEnableVertexAttribArray(2);
    glDrawElements((GLenum)topology, drawCount, GL_UNSIGNED_INT, (void*)(start * sizeof(uint_t)));
    glBindVertexArray(0);
}