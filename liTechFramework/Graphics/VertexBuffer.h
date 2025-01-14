#ifndef LITECHFRAMEWORK_VERTEXBUFFER_H
#define LITECHFRAMEWORK_VERTEXBUFFER_H
#include "GraphicsObject.h"

class liVertexBuffer : public liGraphicsObject {
public:
    liVertexBuffer(void** data, ulong_t size);
    ~liVertexBuffer();

    virtual void Initialize() override;
    virtual void Delete() override;
    virtual void CalculateHash() override;
private:
    void** data;
    ulong_t size;
};

#endif