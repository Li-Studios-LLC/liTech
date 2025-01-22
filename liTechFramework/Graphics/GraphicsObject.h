#ifndef LITECHFRAMEWORK_GRAPHICS_OBJECT_H
#define LITECHFRAMEWORK_GRAPHICS_OBJECT_H
#include "Utility/Resource.h"

template <int handleCount = 1>
class liGraphicsObject : public liResource {
public:
    virtual ~liGraphicsObject() { }

    virtual void Initialize() = 0;
    virtual void Delete() = 0;
    virtual void CalculateHash() = 0;

    void Reinitialize() {
        Delete();
        Initialize();
    }
    
    LITECH_INLINE ulong_t GetHandle(ghandle_t index = 0) const { return handles[index]; }
    LITECH_INLINE ulong_t Hash() const { return hash; }
protected:
    ghandle_t handles[handleCount];
    ulong_t hash;
};

#endif