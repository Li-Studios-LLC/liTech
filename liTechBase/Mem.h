#ifndef LITECHBASE_MEM_H
#define LITECHBASE_MEM_H
#include "Typedefs.h"
#include <utility>

struct memoryStats_t {
    ulong_t allocs;
    ulong_t usage;
    ulong_t totalAllocs;
    ulong_t totalUsage;
};

struct memoryHeader_t {
    char filename[32];
    ulong_t line, size;
};

class LITECH_EXPORT liMemory {
public:
    static liMemory& Instance() {
        static liMemory instance;
        return instance;
    }

    liMemory();
    ~liMemory();
    void ResetStats();
#ifdef LITECH_VERBOSE_MEMORY
    void* _Allocate(ulong_t size, const char* filename, ulong_t line);
    void* _Reallocate(void* block, ulong_t newSize, const char* filename, ulong_t line);
    void _Free(void* block);
    void _DebugPrint();
#endif
private:
    memoryStats_t stats;
};

#ifdef LITECH_VERBOSE_MEMORY
#define liAlloc(size) liMemory::Instance()._Allocate(size, __FILE__, __LINE__)
#define liRealloc(block, newSize) liMemory::Instance()._Reallocate(block, newSize, __FILE__, __LINE__)
#define liFree(block) liMemory::Instance()._Free(block)
#else
#define liAlloc(size) malloc(size)
#define liRealloc(block, newSize) realloc(block, newSize)
#define liFree(block) free(block)
#endif

template <typename T, typename ... Args>
LITECH_INLINE T* liNew(Args&& ... args) {
    void* rawMemory = liAlloc(sizeof(T));
    T* obj = new (rawMemory) T(static_cast<decltype(args)&&>(args)...);
    return obj;
}

template <typename T>
LITECH_INLINE T* liNewArray(ulong_t count) {
    return (T*)liAlloc(sizeof(T) * count);
}

template <typename T>
LITECH_INLINE void _liDeleteImpl(T* memory, bool destructor) {
    if(!memory) {
        return;
    }

    if(destructor) {
        memory->~T();
    }
    liFree(memory);
}

template <typename T>
LITECH_INLINE void liDelete(T* memory) {
    _liDeleteImpl(memory, true);
}

template <typename T>
LITECH_INLINE void liDeleteArray(T* memory) {
    _liDeleteImpl(memory, false);
}

#endif