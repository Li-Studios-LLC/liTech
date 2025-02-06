#ifndef LITECHFRAMEWORK_GRAPHICS_OBJECT_H
#define LITECHFRAMEWORK_GRAPHICS_OBJECT_H
#include "Utility/Resource.h"

class liGraphicsObject : public liResource {
public:
    liGraphicsObject();
    virtual ~liGraphicsObject() { }

    virtual void Initialize() = 0;
    virtual void Delete() = 0;
    virtual void CalculateHash() override;

    void Reinitialize() {
        Delete();
        Initialize();
    }
    
    LITECH_INLINE ulong_t GetHandle(ghandle_t index = 0) const { return handles[index]; }
protected:
    ghandle_t handles[0x10];
};

#endif