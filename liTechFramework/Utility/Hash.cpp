#include "Hash.h"

template <>
ulong_t liTechHash<liBoolBuffer>(const liBoolBuffer& ptr) {
    ulong_t hash = 0;
    for(uint_t i : ptr) {
        hash += liTechHash<bool>(i);
    }
    return hash;
}

template <>
ulong_t liTechHash<liIntBuffer>(const liIntBuffer& ptr) {
    ulong_t hash = 0;
    for(uint_t i : ptr) {
        hash += liTechHash<int>(i);
    }
    return hash;
}

template <>
ulong_t liTechHash<liUIntBuffer>(const liUIntBuffer& ptr) {
    ulong_t hash = 0;
    for(uint_t i : ptr) {
        hash += liTechHash<uint_t>(i);
    }
    return hash;
}

template <>
ulong_t liTechHash<liFloatBuffer>(const liFloatBuffer& ptr) {
    ulong_t hash = 0;
    for(uint_t i : ptr) {
        hash += liTechHash<float>(i);
    }
    return hash;
}

template <>
ulong_t liTechHash<liCharBuffer>(const liCharBuffer& ptr) {
    ulong_t hash = 0;
    for(uint_t i : ptr) {
        hash += liTechHash<char>(i);
    }
    return hash;
}