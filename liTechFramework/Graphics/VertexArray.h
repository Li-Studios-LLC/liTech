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

    void SetVertexBuffer(liVertexBuffer* vbo);
    void SetIndexBuffer(liIndexBuffer* ibo);
    void Bind();
    static void Unbind();

    LITECH_INLINE bool UsesIndexBuffer() const { return usesIndexBuffer; }
    LITECH_INLINE liVertexBuffer* VertexBuffer() { return vbo; }
    LITECH_INLINE liIndexBuffer* IndexBuffer() { return ibo; }
private:
    liVertexBuffer* vbo;
    liIndexBuffer* ibo;
    bool usesIndexBuffer;
};

#endif