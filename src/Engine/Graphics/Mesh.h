#ifndef MESH_H
#define MESH_H
#pragma once
#include "Engine/Math/Vertex.h"
#include "Engine/Framework/Asset.h"

enum class topology_t {
    POINTS = 0x0,
    LINES = 0x1,
    TRIANGLES = 0x4
};

enum class cullMode_t {
    BACK_FACE = GL_BACK,
    FRONT_FACE = GL_FRONT,
    BACK_AND_FRONT_FACE = GL_FRONT_AND_BACK
};

class liMesh : public liAsset {
    friend class liVertex;
public:
    liMesh(ulong_t vertexCount, ulong_t drawCount);
    liMesh(const liMesh&) = delete;
    ~liMesh();

    void UploadVertices(liVertexList* vertices);
    void UploadIndices(liUIntBuffer* indices);
    void Draw(cullMode_t cull, topology_t topology, ulong_t start, long_t count);
private:
    ghandle_t vao, vbo, ibo;
    ulong_t vertexCount, drawCount;
};

#endif