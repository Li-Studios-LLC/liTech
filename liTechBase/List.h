#ifndef LITECHBASE_LIST_H
#define LITECHBASE_LIST_H

#define LILIST_START_SIZE 0x10

template <typename T>
class LITECH_EXPORT liList {
public:
    liList();
    liList(T* buffer, ulong_t size);
    liList(const liList& right);
    ~liList();

    void Clear();
    void Push(const T& value);
    void Pop();
    T& Alloc();
    void Insert(const T& value, ulong_t index);
    void Erase(ulong_t index);
    void Resize(ulong_t newSize);
    void Reserve(ulong_t newCapacity);
    void SetSize(ulong_t newSize);
    void SetAll(const T& value);

    T& Front() { return buffer[0]; }
    const T& Front() const { return buffer[0]; }
    T& Back() { return buffer[size - 1]; }
    const T& Back() const { return buffer[size - 1]; }
    ulong_t Size() const { return size; }
    ulong_t Capacity() const { return capacity; }
    T* Data() { return buffer; }

    liList& operator=(const liList& right);
    T& operator[](int index) { return buffer[index]; }
    const T& operator[](int index) const { return buffer[index]; }
private:
    T* buffer;
    size_t size, capacity;
};

template <typename T>
LITECH_INLINE liList<T>::liList() {
    this->buffer = nullptr;
    this->size = 0;
    this->capacity = 0;
}

template <typename T>
LITECH_INLINE liList<T>::~liList() {
    Clear();
}

template <typename T>
LITECH_INLINE liList<T>::liList(const liList& right) {
    this->buffer = nullptr;
    *this = right;
}

template <typename T>
LITECH_INLINE liList<T>::liList(T* buffer, ulong_t size) {
    this->buffer = liNewArray<T>(size);
    this->size = size;
    this->capacity = size;
    for(ulong_t i = 0; i < size; i++) {
        this->buffer[i] = buffer[i];
    }
}

template <typename T>
LITECH_INLINE void liList<T>::Clear() {
    if(buffer) {
        liDeleteArray(buffer);
    }

    this->buffer = nullptr;
    this->size = 0;
    this->capacity = 0;
}

template <typename T>
LITECH_INLINE void liList<T>::Push(const T& value) {
    if(size == capacity) {
        Reserve(capacity == 0 ? LILIST_START_SIZE : capacity * 2);
    }
    buffer[size++] = value;
}

template <typename T>
LITECH_INLINE void liList<T>::Pop() {
    this->size--;
}

template <typename T>
LITECH_INLINE T& liList<T>::Alloc() {
    if(size == capacity) {
        Reserve(capacity == 0 ? LILIST_START_SIZE : capacity * 2);
    }
    return buffer[size++];
}

template <typename T>
LITECH_INLINE void liList<T>::Insert(const T& value, ulong_t index) {
    LITECH_ASSERT(index < size, "liList index is out of bounds!");

    if (size == capacity) {
        Reserve(capacity == 0 ? 1 : capacity * 2);
    }

    for (ulong_t i = size; i > index; --i) {
        buffer[i] = buffer[i - 1];
    }

    buffer[index] = value;
    this->size++;
}

template <typename T>
LITECH_INLINE void liList<T>::Erase(ulong_t index) {
    LITECH_ASSERT(index < size, "liList index is out of bounds!");

    for (ulong_t i = index; i < size - 1; ++i) {
        buffer[i] = buffer[i + 1];
    }

    this->size--;
}

template <typename T>
LITECH_INLINE void liList<T>::Resize(ulong_t newSize) {
    T* newBuffer = liNewArray<T>(newSize);
    for(ulong_t i = 0; i < capacity; i++) {
        newBuffer[i] = buffer[i];
    }
    liDeleteArray(buffer);
    this->capacity = newSize;
    this->size = newSize;
    this->buffer = newBuffer;
}

template <typename T>
LITECH_INLINE void liList<T>::Reserve(ulong_t newCapacity) {
    T* newBuffer = liNewArray<T>(newCapacity);
    for(ulong_t i = 0; i < capacity; i++) {
        newBuffer[i] = buffer[i];
    }
    liDeleteArray(buffer);
    this->capacity = newCapacity;
    this->buffer = newBuffer;
}

template<typename T>
LITECH_INLINE void liList<T>::SetSize(ulong_t newSize) {
    LITECH_ASSERT(capacity <= newSize, "New array size cannot be bigger than capacity!");
    this->size = newSize;
}

template <typename T>
LITECH_INLINE void liList<T>::SetAll(const T& value) {
    for(ulong_t i = 0; i < size; i++) {
        buffer[i] = value;
    }
}

template <typename T>
LITECH_INLINE liList<T> &liList<T>::operator=(const liList<T> &right) {
    Clear();
    this->buffer = liNewArray<T>(right.size);
    for(ulong_t i = 0; i < right.size; i++) {
        buffer[i] = right.buffer[i];
    }
    this->size = right.size;
    this->capacity = right.capacity;
    return *this;
}

typedef liList<ubyte_t> liByteBuffer;
typedef liList<int> liIntBuffer;
typedef liList <float> liFloatBuffer;
typedef liList<char> liCharBuffer;

#endif