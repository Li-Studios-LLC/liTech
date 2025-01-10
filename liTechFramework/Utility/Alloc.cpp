#include "Alloc.h"

void* liTechMalloc(ulong_t size) {
    return malloc(size);
}

void liTechFree(void* memory) {
    free(memory);
}

void* liTechRealloc(void* memory, ulong_t newSize) {
    return realloc(memory, newSize);
}