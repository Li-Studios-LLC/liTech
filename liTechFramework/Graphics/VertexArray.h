#ifndef LITECHFRAMEWORK_VERTEX_ARRAY_H
#define LITECHFRAMEWORK_VERTEX_ARRAY_H
#include "GraphicsObject.h"

class liVertexBuffer;

class liVertexArray : public liGraphicsObject {
public:
    liVertexArray();
    ~liVertexArray();

    virtual void Initialize() override;
    virtual void Delete() override;
    virtual void CalculateHash() override;
private:
    ghandle_t ID;
    liVertexArray* vbo;
};

#endif