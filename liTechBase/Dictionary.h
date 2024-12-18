#ifndef LITECHBASE_DICTIONARY_H
#define LITECHBASE_DICTIONARY_H
#include "Pair.h"

#define LIDICTIONARY_START_SIZE 0x1

template <typename K, typename V>
class liDictionary {
public:
	typedef liPair<K, V> element_t;

	liDictionary();
	liDictionary(const liDictionary& right);
	~liDictionary();

	void Clear();
	void Resize(ulong_t newSize);
	void Reserve(ulong_t newSize);
	void SetSize(ulong_t newSize);
	V& Search(const K& key);
	const V& Search(const K& key) const;
	long_t Find(const K& key);
	void Emplace(const K& key, const V& value);
	void Pop();
	void Erase(const K& key);

	element_t& Front() { return elements[0]; }
	const element_t& Front() const { return elements[0]; }
	element_t& Back() { return elements[size - 1]; }
	const element_t& Back() const { return elements[size - 1]; }
	element_t& At(ulong_t index) { return elements[index]; }
	const element_t& At(ulong_t index) const { return elements[index]; }
	ulong_t Size() const { return size; }
	ulong_t Capacity() const { return capacity; }
	element_t* Data() { return elements; }

	V& operator[](const K& key) { return Search(key); }
	const V& operator[](const K& key) const { return Search(key); }

	liDictionary& operator=(const liDictionary& right);
private:
	element_t* elements;
	ulong_t size, capacity;
};

template <typename K, typename V>
LITECH_INLINE liDictionary<K, V>::liDictionary() {
	this->elements = nullptr;
	this->size = 0;
	this->capacity = 0;
}

template <typename K, typename V>
LITECH_INLINE liDictionary<K, V>::~liDictionary() {
	Clear();
}

template <typename K, typename V>
LITECH_INLINE liDictionary<K, V>::liDictionary(const liDictionary& right) {
	this->elements = nullptr;
	*this = right;
}

template<typename K, typename V>
LITECH_INLINE void liDictionary<K, V>::Clear() {
	if (elements) {
		liDeleteArray(elements);
	}

	this->elements = nullptr;
	this->size = 0;
	this->capacity = 0;
}

template<typename K, typename V>
LITECH_INLINE void liDictionary<K, V>::Resize(ulong_t newSize) {
	element_t* newElements = liNewArray<element_t>(newSize);
	for (ulong_t i = 0; i < capacity; i++) {
		newElements[i] = elements[i];
	}
	liDeleteArray(elements);
	this->capacity = newSize;
	this->size = newSize;
	this->elements = newElements;
}

template<typename K, typename V>
LITECH_INLINE void liDictionary<K, V>::Reserve(ulong_t newSize) {
	element_t* newElements = liNewArray<element_t>(newSize);
	for (ulong_t i = 0; i < capacity; i++) {
		newElements[i] = elements[i];
	}
	liDeleteArray(elements);
	this->capacity = newSize;
	this->elements = newElements;
}

template<typename K, typename V>
LITECH_INLINE void liDictionary<K, V>::SetSize(ulong_t newSize) {
	LITECH_ASSERT(capacity <= newSize, "New array size cannot be bigger than capacity!");
	this->size = newSize;
}

template<typename K, typename V>
LITECH_INLINE V& liDictionary<K, V>::Search(const K& key) {
	for (ulong_t i = 0; i < size; i++) {
		if (elements[i].first == key) {
			return elements[i]->second;
		}
	}
}

template<typename K, typename V>
LITECH_INLINE const V& liDictionary<K, V>::Search(const K& key) const {
	for (ulong_t i = 0; i < size; i++) {
		if (elements[i].first == key) {
			return elements[i]->second;
		}
	}
}

template<typename K, typename V>
LITECH_INLINE long_t liDictionary<K, V>::Find(const K& key) {
	for (ulong_t i = 0; i < size; i++) {
		if (elements[i].first == key) {
			return i;
		}
	}
	return -1;
}

template<typename K, typename V>
LITECH_INLINE void liDictionary<K, V>::Emplace(const K& key, const V& value) {
	if (size == capacity) {
		Reserve(capacity == 0 ? LIDICTIONARY_START_SIZE : capacity * 2);
	}
	elements[size++] = element_t(key, value);
}

template<typename K, typename V>
LITECH_INLINE void liDictionary<K, V>::Pop() {
	LITECH_ASSERT(size > 0, "Array size cannot be 0!");
	this->size--;
}

template<typename K, typename V>
LITECH_INLINE void liDictionary<K, V>::Erase(const K& key) {
	long_t index = Find(key);
	LITECH_ASSERT(index != -1, "Failed to find liDictionary pair!");
	for (ulong_t i = index; i < size - 1; ++i) {
		elements[i] = elements[i + 1];
	}
	this->size--;
}

template<typename K, typename V>
LITECH_INLINE liDictionary<K, V>& liDictionary<K, V>::operator=(const liDictionary& right) {
	Clear();
	this->elements = liNewArray<element_t>(right.size);
	for (ulong_t i = 0; i < right.size; i++) {
		elements[i] = right.elements[i];
	}
	this->size = right.size;
	this->capacity = right.capacity;
	return *this;
}

#endif