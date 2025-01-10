#ifndef LITECHFRAMEWORK_ALLOC_H
#define LITECHFRAMEWORK_ALLOC_H
#include "Typedefs.h"

void* liTechMalloc(ulong_t size);
void liTechFree(void* memory);
void* liTechRealloc(void* memory, ulong_t newSize);

#endif