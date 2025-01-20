#ifndef LITECHFRAMEWORK_HASH_H
#define LITECHFRAMEWORK_HASH_H
#include "Typedefs.h"

template <typename T>
ulong_t liTechHash(const T& ptr) {
    ulong_t hash = 5381;
    byte_t* block = (byte_t*)&ptr;
    for(ulong_t i = 0; i < sizeof(T); i++) {
        hash = ((hash << 5) + hash) + block[i];
    }
    return hash;
}

template <>
ulong_t liTechHash<liBoolBuffer>(const liBoolBuffer& ptr);
template <>
ulong_t liTechHash<liIntBuffer>(const liIntBuffer& ptr);
template <>
ulong_t liTechHash<liUIntBuffer>(const liUIntBuffer& ptr);
template <>
ulong_t liTechHash<liFloatBuffer>(const liFloatBuffer& ptr);
template <>
ulong_t liTechHash<liCharBuffer>(const liCharBuffer& ptr);

#endif