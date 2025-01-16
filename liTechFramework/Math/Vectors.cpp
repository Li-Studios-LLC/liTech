#include "Vectors.h"

liVector2f::liVector2f(float x, float y) {
    this->x = x;
    this->y = y;
}

float liVector2f::Length() const {
    return sqrtf(x * x + y * y);
}

liVector3f::liVector3f(float x, float y, float z) {
    this->x = x;
    this->y = y;
    this->z = z;
}

float liVector3f::Length() const {
    return sqrtf(x * x + y * y + z * z);
}

liVector4f::liVector4f(float x, float y, float z, float w) {
    this->x = x;
    this->y = y;
    this->z = z;
    this->w = w;
}

float liVector4f::Length() const {
    return sqrtf(x * x + y * y + z * z + w * w);
}