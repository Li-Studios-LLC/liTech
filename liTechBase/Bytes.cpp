#include "Bytes.h"

endianness_t liBytes::GetEndianness() {
    unsigned int num = 23;
    char* byte = (char*)&num;
    return byte[0] == 23 ? endianness_t::LITTLE : endianness_t::BIG;
}

ushort_t liBytes::SwapShort(ushort_t s) {
    return (s << 8) | (s >> 8);
}

uint_t liBytes::SwapInt(uint_t u) {
    return ((u << 24) & 0xFF000000) |
           ((u << 8) & 0x00FF0000) |
           ((u >> 8) & 0x0000FF00) |
           ((u >> 24) & 0x000000FF);
}

ulong_t liBytes::SwapLong(ulong_t l) {
    return ((l << 56) & 0xFF00000000000000UL) |
           ((l << 40) & 0x00FF000000000000UL) |
           ((l << 24) & 0x0000FF0000000000UL) |
           ((l << 8)  & 0x000000FF00000000UL) |
           ((l >> 8)  & 0x00000000FF000000UL) |
           ((l >> 24) & 0x0000000000FF0000UL) |
           ((l >> 40) & 0x000000000000FF00UL) |
           ((l >> 56) & 0x00000000000000FFUL);
}