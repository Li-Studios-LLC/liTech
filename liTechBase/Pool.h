#ifndef LITECHBASE_POOL_H
#define LITECHBASE_POOL_H

#define LITECH_INITIAL_POOL_SIZE 32

template <typename T>
class LITECH_EXPORT liPool {
public:
    liPool(ulong_t initialSize = LITECH_INITIAL_POOL_SIZE);
    liPool(const liPool&) = delete;
    ~liPool();
    
    T* Alloc();
    void Dealloc(T* object);
    void Reset();

    ulong_t InitialSize() const { return initialSize; }
    ulong_t PoolSize() const { return elements.Size(); }
    bool IsOccupied(ulong_t index) const { return freeList[index]; }
    T* operator[](ulong_t index) { return elements[index]; }
    T* operator[](ulong_t index) const { return elements[index]; }
private:
    liList<T*> elements;
    liList<bool> freeList;
    ulong_t initialSize;
};

template <typename T>
LITECH_INLINE liPool<T>::liPool(ulong_t initialSize) {
    this->initialSize = initialSize;
    elements.Resize(initialSize);
    freeList.Resize(initialSize);
    for (ulong_t i = 0; i < initialSize; i++) {
        this->elements[i] = liNew<T>();
    }
    Reset();
}

template <typename T>
LITECH_INLINE liPool<T>::~liPool() {
    for (ulong_t i = 0; i < elements.Size(); i++) {
        liDelete(elements[i]);
    }
}

template <typename T>
LITECH_INLINE T *liPool<T>::Alloc() {
    for (ulong_t i = 0; i < elements.Size(); i++) {
        if (!freeList[i]) {
            freeList[i] = true;
            return elements[i];
        }
    }

    elements.Push(liNew<T>());
    freeList.Push(true);
    return elements.Back();
}

template <typename T>
LITECH_INLINE void liPool<T>::Dealloc(T* object) {
    for (ulong_t i = 0; i < elements.Size(); i++) {
        if (elements[i] == object) {
            freeList[i] = false;
            return;
        }
    }
}

template <typename T>
LITECH_INLINE void liPool<T>::Reset() {
    freeList.SetAll(false);
}

#endif