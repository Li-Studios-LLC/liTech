#ifndef LITECHFRAMEWORK_INDEXBUFFER_H
#define LITECHFRAMEWORK_INDEXBUFFER_H
#include "GraphicsObject.h"

class liIndexBuffer : public liGraphicsObject {
public:
    liIndexBuffer(liIntBuffer* data);
    ~liIndexBuffer();

    virtual void Initialize() override;
    virtual void Delete() override;
    virtual void CalculateHash() override;

    void Bind();
    static void Unbind();

    LITECH_INLINE ulong_t Size() const { return size; }
private:
    liIntBuffer* data;
    ulong_t size;
};

#endif