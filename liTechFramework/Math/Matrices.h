#ifndef LITECHFRAMEWORK_MATRICES_H
#define LITECHFRAMEWORK_MATRICES_H
#include "Vectors.h"

typedef liVector4f liMatrix1f;

struct liMatrix2f {
    liVector2f vecs[2];

    liMatrix2f();

    void SetIdentity();
    void SetZero();

    LITECH_INLINE liVector2f& operator[](int index) { return vecs[index]; }
    LITECH_INLINE const liVector2f& operator[](int index) const { return vecs[index]; }
};

struct liMatrix3f {
    liVector3f vecs[3];

    liMatrix3f();

    void SetIdentity();
    void SetZero();

    LITECH_INLINE liVector3f& operator[](int index) { return vecs[index]; }
    LITECH_INLINE const liVector3f& operator[](int index) const { return vecs[index]; }
};

struct liMatrix4f {
    liVector4f vecs[4];

    liMatrix4f();

    void SetIdentity();
    void SetZero();
    void Translate(liVector3f position);
    void Scale(liVector3f scale);
    void Rotate(liVector3f axis, float angle);
    static liMatrix4f Perspective(float fov, float aspect, float nearPlane, float farPlane);

    liMatrix4f operator*(liMatrix4f mat);
    liMatrix4f& operator*=(liMatrix4f mat);
    LITECH_INLINE liVector4f& operator[](int index) { return vecs[index]; }
    LITECH_INLINE const liVector4f& operator[](int index) const { return vecs[index]; }
private:
    void _Multiply(liMatrix4f mat);
};

#endif