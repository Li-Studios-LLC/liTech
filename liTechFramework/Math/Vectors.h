#ifndef LITECHFRAMEWORK_VECTORS_H
#define LITECHFRAMEWORK_VECTORS_H
#include "Typedefs.h"
#include "Utility/Hash.h"

struct liVector2f {
    float x, y;

    liVector2f(float x = 0, float y = 0);
    liVector2f(const liVector2f& vec);

    float Length() const;
    void Normalize();

    LITECH_INLINE ulong_t Hash() const { return liTechHash<liVector2f>(*this); }
    LITECH_INLINE float* ToPtr() { return &x; }
    LITECH_INLINE const float* ToPtr() const { return &x; }
    LITECH_INLINE float& operator[](int index) { return ToPtr()[index]; }
    LITECH_INLINE const float& operator[](int index) const { return ToPtr()[index]; }
};

struct liVector3f {
    float x, y, z;

    liVector3f(float x = 0, float y = 0, float z = 0);
    liVector3f(const liVector3f& vec);

    float Length() const;
    void Normalize();
    
    LITECH_INLINE ulong_t Hash() const { return liTechHash<liVector3f>(*this); }
    LITECH_INLINE float* ToPtr() { return &x; }
    LITECH_INLINE const float* ToPtr() const { return &x; }
    LITECH_INLINE float& operator[](int index) { return ToPtr()[index]; }
    LITECH_INLINE const float& operator[](int index) const { return ToPtr()[index]; }
};

struct liVector4f {
    float x, y, z, w;

    liVector4f(float x = 0, float y = 0, float z = 0, float w = 0);
    liVector4f(const liVector4f& vec);

    float Length() const;
    void Normalize();

    LITECH_INLINE ulong_t Hash() const { return liTechHash<liVector4f>(*this); }
    LITECH_INLINE float* ToPtr() { return &x; }
    LITECH_INLINE const float* ToPtr() const { return &x; }
    LITECH_INLINE float& operator[](int index) { return ToPtr()[index]; }
    LITECH_INLINE const float& operator[](int index) const { return ToPtr()[index]; }
};

#endif