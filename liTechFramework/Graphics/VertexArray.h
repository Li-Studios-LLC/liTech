#ifndef LITECHFRAMEWORK_VERTEX_ARRAY_H
#define LITECHFRAMEWORK_VERTEX_ARRAY_H
#include "GraphicsObject.h"
#include "Typedefs.h"

class liVertexArray : public liGraphicsObject {
public:
    liVertexArray();
    ~liVertexArray();

    virtual void CalculateHash() override;
private:
    ghandle_t ID;
};

#endif