#ifndef LITECHFRAMEWORK_HEAP_H
#define LITECHFRAMEWORK_HEAP_H
#include "Typedefs.h"
#include "Allocator.h"
#include "Alloc.h"

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
#define liAlloc(size) liHeap::Instance()->Allocate(size)
#define liRealloc(block, newSize) liHeap::Instance()->Reallocate(block, newSize)
#define liFree(block) liHeap::Instance()->Deallocate(block)
#else
#define liAlloc(size) liTechMalloc(size)
#define liRealloc(block, newSize) liTechRealloc(block, newSize)
#define liFree(block) liTechFree(block)
#endif

template <typename T, typename ... Args>
LITECH_INLINE T* liNew(Args&& ... args) {
    void* rawMemory = liAlloc(sizeof(T));
    T* obj = new (rawMemory) T(std::forward<Args>(args)...);
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