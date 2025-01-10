#include "Heap.h"

liHeap::~liHeap() {
#ifdef LITECH_VERBOSE_MEMORY
    DebugPrint();
#endif
}

void* liHeap::Allocate(ulong_t size) {
    heapAllocation_t* memory = (heapAllocation_t*)liTechMalloc(size + sizeof(heapAllocation_t));
    void* actual = (void*)&memory[1];
    heapAllocation_t alloc;
    alloc.ptr = actual;
    alloc.size = size;
    memory[0] = alloc;
    _AddAllocation(actual, alloc);
    stats.allocs++;
    stats.current++;
    stats.usage += size;
    return actual;
}

void liHeap::Deallocate(void* memory) {
    if(!memory) {
        return;
    }

    heapAllocation_t* block = (heapAllocation_t*)memory;
    heapAllocation_t alloc = block[-1];

    stats.current--;
    stats.frees++;
    stats.usage -= alloc.size;
    _RemoveAllocation(alloc.ptr);
    void* ptr = (void*)(&block[-1]);
    liTechFree(ptr);
}

void* liHeap::Reallocate(void* memory, ulong_t newSize) {
    void* newMemory = Allocate(newSize);
    memcpy(newMemory, memory, newSize);
    Deallocate(memory);
    return newMemory;
}

void liHeap::DebugPrint() {
    for(liAllocationMap::iterator it = allocs.begin(); it != allocs.end(); it++) {
        memory_t ptr = it->first;
        heapAllocation_t alloc = it->second;
        liTechPrint("Unallocated memory at %p of size %lld", ptr, alloc.size);
    }
}

void liHeap::_AddAllocation(memory_t ptr, heapAllocation_t alloc) {
    allocs.emplace(ptr, alloc);
}

void liHeap::_RemoveAllocation(memory_t ptr) {
    allocs.erase(ptr);
}