#ifndef LITECHFRAMEWORK_MATRICES_H
#define LITECHFRAMEWORK_MATRICES_H
#include "Vectors.h"

typedef liVector4f liMatrix1f;

struct liMatrix2f {
    liVector4f vecs[2];
};

struct liMatrix3f {
    liVector4f vecs[3];
};

struct liMatrix4f {
    liVector4f vecs[4];

    liMatrix4f();

    void SetIdentity();
    void SetZero();
};

#endif