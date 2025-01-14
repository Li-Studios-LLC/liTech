#ifndef LITECHFRAMEWORK_VERTEX_ARRAY_H
#define LITECHFRAMEWORK_VERTEX_ARRAY_H
#include "GraphicsObject.h"
#include "VertexBuffer.h"
#include "IndexBuffer.h"

class liVertexArray : public liGraphicsObject {
public:
    liVertexArray();
    ~liVertexArray();

    virtual void Initialize() override;
    virtual void Delete() override;
    virtual void CalculateHash() override;
private:
    ghandle_t ID;
    liVertexBuffer* vbo;
    liIndexBuffer* ibo;
};

#endif