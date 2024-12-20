#ifndef LITECHBASE_LINKEDLIST_H
#define LITECHBASE_LINKEDLIST_H

template <typename T>
class liLinkedList {
public:
	struct element_t {
		T value;
		element_t* next, *last;
	};

	liLinkedList();
	~liLinkedList();

	void Clear();
	void Push(const T& value);
	void Pop();
	T& Alloc();
private:
	element_t* elements, *first, *last;
	ulong_t size;
};

template<typename T>
LITECH_INLINE liLinkedList<T>::liLinkedList() {
	this->elements = nullptr;
	this->first = nullptr;
	this->last = nullptr;
	this->size = 0;
}

template<typename T>
LITECH_INLINE liLinkedList<T>::~liLinkedList() {
	Clear();
}

template<typename T>
LITECH_INLINE void liLinkedList<T>::Clear() {
	if (elements) {
		element_t* e = first;
		while (e) {
			element_t* next = e->next;
			liDelete(next);
			e = next;
		}
	}
	
	this->elements = nullptr;
	this->first = nullptr;
	this->last = nullptr;
	this->size = 0;
}

template<typename T>
LITECH_INLINE void liLinkedList<T>::Push(const T& value) {
}

template<typename T>
LITECH_INLINE void liLinkedList<T>::Pop() {
}

template<typename T>
LITECH_INLINE T& liLinkedList<T>::Alloc() {
}

#endif