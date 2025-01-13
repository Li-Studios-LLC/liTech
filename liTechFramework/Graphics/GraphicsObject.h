#ifndef LITECHFRAMEWORK_GRAPHICS_OBJECT_H
#define LITECHFRAMEWORK_GRAPHICS_OBJECT_H
#include "Utility/Resource.h"

class liGraphicsObject : public liResource {
public:
    virtual ~liGraphicsObject() { }

    virtual void CalculateHash() = 0;

    LITECH_INLINE ulong_t Hash() const { return hash; }
protected:
    ghandle_t handle;
    ulong_t hash;
};

#endif