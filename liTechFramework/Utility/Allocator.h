#ifndef LITECHFRAMEWORK_ALLOCATOR_H
#define LITECHFRAMEWORK_ALLOCATOR_H
#include "Typedefs.h"

struct allocatorStats_t {
    ulong_t allocs, frees, current; // Allocation counters
    ulong_t usage;
};

class liAllocator {
public:
    liAllocator();
    virtual ~liAllocator() { }

    virtual void* Allocate(ulong_t size, ulong_t align) = 0;
    virtual void Deallocate(void* memory) = 0;
    virtual void Reallocate(void* memory, ulong_t newSize) = 0;
protected:
    void _ResetStats();

    allocatorStats_t stats;
};

#endif