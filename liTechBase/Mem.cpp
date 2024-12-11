#include "Mem.h"

liMemory::liMemory() {
    ResetStats();
}

liMemory::~liMemory() {
#ifdef LITECH_VERBOSE_MEMORY
    _DebugPrint();
#endif
}

void liMemory::ResetStats() {
    memset((void*)&stats, 0, sizeof(memoryStats_t));
}

#ifdef LITECH_VERBOSE_MEMORY
void* liMemory::_Allocate(ulong_t size, const char* filename, ulong_t line) {
    memoryHeader_t* mem = (memoryHeader_t*)malloc(size + sizeof(memoryHeader_t));
    memoryHeader_t header;
    strcpy(header.filename, filename);
    header.line = line;
    header.size = size;
    header.ptr = (void*)(&mem[1]);
    mem[0] = header;
    stats.usage += size;
    stats.allocs++;
    stats.totalAllocs++;
    stats.totalUsage += size;
    return header.ptr;
}

void* liMemory::_Reallocate(void* block, ulong_t newSize, const char* filename, ulong_t line) {
    void* newMemory = _Allocate(newSize, filename, line);
    memcpy(newMemory, block, newSize);
    _Free(block);
    return newMemory;
}

void liMemory::_Free(void* block) {
    if(!block) {
        return;
    }

    memoryHeader_t* mem = (memoryHeader_t*)block;
    memoryHeader_t header = mem[-1];
    stats.allocs--;
    stats.usage -= header.size;
    void* ptr = (void*)(&mem[-1]);
    free(ptr);
}

void liMemory::_DebugPrint() {
    printf("liTech: allocated a total of %0.2f KB and %lld allocations\n", LITECH_KB(stats.totalUsage), stats.totalAllocs);
    float percentage = stats.allocs == 0 ? 0.0f : (float)stats.allocs / (float)stats.totalAllocs;
    printf("liTech: %0.2f KB (%lld allocations, %0.1f%%) were never unallocated\n", LITECH_KB(stats.usage), stats.allocs, percentage);
}
#endif