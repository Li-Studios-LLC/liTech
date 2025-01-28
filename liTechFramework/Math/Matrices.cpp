#include "Matrices.h"

liMatrix4f::liMatrix4f() {
    SetIdentity();
}

void liMatrix4f::SetIdentity() {
    SetZero();
    vecs[0][0] = 1.0f;
    vecs[1][1] = 1.0f;
    vecs[2][2] = 1.0f;
    vecs[3][3] = 1.0f;
}

void liMatrix4f::SetZero() {
    memset(vecs, 0, sizeof(liVector4f[4]));
}