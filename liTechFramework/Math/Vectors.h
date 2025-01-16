#ifndef LITECHFRAMEWORK_VECTORS_H
#define LITECHFRAMEWORK_VECTORS_H
#include "Typedefs.h"

struct liVector2f {
    float x, y;

    liVector2f(float x = 0, float y = 0);

    float Length() const;
};

struct liVector3f {
    float x, y, z;

    liVector3f(float x = 0, float y = 0, float z = 0);

    float Length() const;
};

struct liVector4f {
    float x, y, z, w;

    liVector4f(float x = 0, float y = 0, float z = 0, float w = 0);

    float Length() const;
};

#endif