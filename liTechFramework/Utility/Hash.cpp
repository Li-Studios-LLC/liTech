#include "Hash.h"

ulong_t liTechHashBuffer(void* ptr, ulong_t size) {
    ulong_t hash = 5381;
    byte_t* block = (byte_t*)&ptr;
    for(ulong_t i = 0; i < size; i++) {
        hash = ((hash << 5) + hash) + block[i];
    }
    return hash;
}

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

template <>
ulong_t liTechHash(const std::string& ptr) {
    return liTechHashBuffer((void*)ptr.data(), ptr.length());
}