#ifndef LITECHFRAMEWORK_GRAPHICS_OBJECT_H
#define LITECHFRAMEWORK_GRAPHICS_OBJECT_H
#include "Utility/Resource.h"

class liGraphicsObject : public liResource {
public:
    virtual ~liGraphicsObject() { }

    virtual void Initialize() = 0;
    virtual void Delete() = 0;
    virtual void CalculateHash() = 0;

    LITECH_INLINE ulong_t Hash() const { return hash; }
protected:
    ghandle_t handle;
    ulong_t hash;
};

#endif