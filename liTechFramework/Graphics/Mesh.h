#ifndef LITECHFRAMEWORK_MESH_H
#define LITECHFRAMEWORK_MESH_H
#include "VertexArray.h"

enum class topology_t {
    TRIANGLES,
    LINES,
    POINTS
};

class liMesh : public liGraphicsObject {
public:
    liMesh();
    ~liMesh();
    
    virtual void Initialize() override;
    virtual void Delete() override;
    virtual void CalculateHash() override;

    void Draw();

    LITECH_INLINE liVertexArray* VertexArray() { return vao; }
private:
    liVertexArray* vao;
    topology_t topology;
    ulong_t vertexCount, drawOffset;
    long_t drawCount;
};

#endif