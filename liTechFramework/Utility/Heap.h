#ifndef LITECHFRAMEWORK_HEAP_H
#define LITECHFRAMEWORK_HEAP_H
#include "Typedefs.h"
#include "Allocator.h"

struct heapAllocation_t {
    memory_t ptr;
    ulong_t size;
    /*char filename[32];
    ulong_t line;*/
};

typedef std::unordered_map<memory_t, heapAllocation_t> liAllocationMap;

class liHeap : public liAllocator {
public:
    static liHeap* Instance() {
        static liHeap* heap;
        if(!heap) {
            heap = new liHeap();
        }
        return heap;
    }

    ~liHeap();

    virtual void* Allocate(ulong_t size) override;
    virtual void Deallocate(void* memory) override;
    virtual void* Reallocate(void* memory, ulong_t newSize) override;
    virtual void DebugPrint() override;
private:
    void _AddAllocation(memory_t ptr, heapAllocation_t alloc);
    void _RemoveAllocation(memory_t ptr);

    liAllocationMap allocs;
};

#ifdef LITECH_VERBOSE_MEMORY
#else
#endif

#endif