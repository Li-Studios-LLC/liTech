#ifndef LITECH_SMART_H
#define LITECH_SMART_H

template <typename T>
class liSmart {
public:
    liSmart();
    liSmart(T* ptr);
    ~liSmart();

    T& operator*();
    const T& operator*() const;
    T* operator->();

    bool Valid() const { return ptr != nullptr; }
    ulong_t RefCount() const { return refCount; }
private:
    T* ptr;
    mutable ulong_t refCount;
};

template <typename T, typename ... Args>
inline liSmart<T> CreateSmart(Args&& ... args) {
    return liSmart<T>(liNew<T>(args...));
}

template <typename T>
inline liSmart<T>::liSmart() {
    this->ptr = nullptr;
    this->refCount = 0;
}

template <typename T>
inline liSmart<T>::liSmart(T* ptr) {
    this->ptr = ptr;
    this->refCount = 0;
}

template <typename T>
inline liSmart<T>::~liSmart() {
    if(ptr) {
        liDelete(ptr);
    }
}

template <typename T>
inline T& liSmart<T>::operator*() {
    this->refCount++;
    return *ptr;
}

template <typename T>
inline const T& liSmart<T>::operator*() const {
    this->refCount++;
    return *ptr;
}

template <typename T>
inline T* liSmart<T>::operator->() {
    this->refCount++;
    return ptr;
}

#endif