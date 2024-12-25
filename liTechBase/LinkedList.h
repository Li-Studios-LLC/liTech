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

	T& First() { return first->value; }
	const T& First() const { return first->value; }
	T& Last() { return first->value; }
	const T& Last() const { return first->value; }

	element_t* FirstElement() { return first; }
	element_t* LastElement() { return last; }

	ulong_t Size() const { return size;  }
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
	if (first == nullptr) {

	} else if (first == last) {

	} else {

	}
}

template<typename T>
LITECH_INLINE void liLinkedList<T>::Pop() {
	if (first == last) {

	} else {
		element_t* newLast = last->last;
	}
	this->size--;
}

template<typename T>
LITECH_INLINE T& liLinkedList<T>::Alloc() {
}

#endif