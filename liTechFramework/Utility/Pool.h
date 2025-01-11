#ifndef LITECHFRAMEWORK_POOL_H
#define LITECHFRAMEWORK_POOL_H
#include "Heap.h"

#define LITECH_POOL_SIZE 0x10

template <typename T>
class liPool {
public:
    liPool(ulong_t initialSize = LITECH_POOL_SIZE) {
        this->initialSize = initialSize;
        objects.resize(initialSize);
        freeList.resize(initialSize, false);
        for(ulong_t i = 0; i < initialSize; i++) {
            objects[i] = liNew<T>();
        }
    }

    liPool(const liPool&) = delete;

    ~liPool() {
        for(ulong_t i = 0; i < objects.size(); i++) {
            liDelete(objects[i]);
        }
    }

    T* Allocate() {
        for(size_t i = 0; i < objects.size(); i++) {
            if(!freeList[i]) {
                freeList[i] = true;
                return objects[i];
            }
        }

        objects.push_back(liNew<T>());
        freeList.push_back(true);
        return objects.back();
    }

    void Deallocate(T* object) {
        for(size_t i = 0; i < objects.size(); i++) {
            if(objects[i] == object) {
                freeList[i] = false;
                return;
            }
        }
    }

    void Reset() {
        std::replace(freeList.begin(), freeList.end(), false, true);
    }

    LITECH_INLINE size_t PoolSize() const { return objects.size(); }
    LITECH_INLINE bool IsOccupied(size_t index) const { return freeList[index]; }
    LITECH_INLINE T* operator[](size_t index) { return objects[index]; }
    LITECH_INLINE T* operator[](size_t index) const { return objects[index]; }
private:
    ulong_t initialSize;
    std::vector<T*> objects;
    liBoolBuffer freeList;
};

#endif