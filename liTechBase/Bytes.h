#ifndef LITECHBASE_BYTES_H
#define LITECHBASE_BYTES_H
#include "Typedefs.h"

enum class endianness_t {
    LITTLE,
    BIG
};

class liBytes {
public:
    static endianness_t GetEndianness();
    static ushort_t SwapShort(ushort_t s);
    static uint_t SwapInt(uint_t u);
    static ulong_t SwapLong(ulong_t l);
};

#endif