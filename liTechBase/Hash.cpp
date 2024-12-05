#include "Hash.h"

ulong_t liHash::HashDJB2(byte_t* bytes, ulong_t size) {
    ulong_t hash = 5831;
    for(ulong_t i = 0; i < size; i++) {
        byte_t c = bytes[i];
        hash = ((hash << 5) + hash) + c;
    }
    return hash;
}