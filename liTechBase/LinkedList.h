#ifndef LITECHBASE_LINKEDLIST_H
#define LITECHBASE_LINKEDLIST_H


template <typename T>
class liLinkedList {
public:
	struct node_t {
		T value;
		node_t* next, *last;
	};

	liLinkedList();
	~liLinkedList();
	liLinkedList(const liLinkedList& right);

	void Clear();
	void Push(const T& value);
	void Pop();
	void Insert(const T& value, ulong_t index);
	void Erase(ulong_t index);
	
	T& Find(const T& value);
	const T& Find(const T& value) const;

	T& First() { return first->value; }
	const T& First() const { return first->value; }
	T& Last() { return first->value; }
	const T& Last() const { return first->value; }

	node_t* FirstNode() { return first; }
	node_t* LastNode() { return last; }

	ulong_t Size() const { return size;  }
	bool IsEmpty() const { return (first == nullptr && last == nullptr); }

	liLinkedList& operator=(const liLinkedList& right);
	T& operator[](ulong_t index) { return _GetNode(index)->value; }
	const T& operator[](ulong_t index) const { return _GetNode(index)->value; }
private:
	node_t* _GetNode(ulong_t index);

	node_t* first, *last;
	ulong_t size;
};

template<typename T>
LITECH_INLINE liLinkedList<T>::liLinkedList() {
	this->first = nullptr;
	this->last = nullptr;
	this->size = 0;
}

template<typename T>
LITECH_INLINE liLinkedList<T>::~liLinkedList() {
	Clear();
}

template<typename T>
LITECH_INLINE liLinkedList<T>::liLinkedList(const liLinkedList& right) {
	this->first = nullptr;
	this->last = nullptr;
	this->size = 0;
	*this = right;
}

template<typename T>
LITECH_INLINE void liLinkedList<T>::Clear() {
	if (!IsEmpty()) {
		node_t* node = first;
		while (node) {
			node_t* next = node->next;
			liDelete(node);
			node = next;
		}
	}
	
	this->first = nullptr;
	this->last = nullptr;
	this->size = 0;
}

template<typename T>
LITECH_INLINE void liLinkedList<T>::Push(const T& value) {
	node_t* node = liNew<node_t>(value);
	if (first == nullptr) {
		// The linked list is empty
		this->first = node;
		this->last = node;
	} else if (first == last) {
		// The linked list has one element
		node->last = first;
		this->first->next = node;
		this->last = node;
	} else {
		// The linked list has multiple elements
		this->last->next = node;
		node->last = last;
		this->last = node;
	}
	this->size++;
}

template<typename T>
LITECH_INLINE void liLinkedList<T>::Pop() {
	LITECH_ASSERT(!IsEmpty(), "liLinkedList is empty!");
	if (first == last) {
		// The linked list has one element
		liDelete(first);
		this->first = nullptr;
		this->last = nullptr;
	} else {
		// The linked list has multiple elements
		node_t* newLast = last->last;
		liDelete(last);
		newLast->next = nullptr;
		this->last = newLast;
	}
	this->size--;
}

template<typename T>
LITECH_INLINE void liLinkedList<T>::Insert(const T& value, ulong_t index) {
	if (index >= size) {
		Push(value);
	} else if(index == 0) {
		node_t* node = liNew<node_t>(value);
		first->last = node;
		node->next = first;
		this->first = node;
		this->size++;
	} else {
		node_t* node = liNew<node_t>(value);
		node_t* before = _GetNode(index - 1);
		node_t* after = _GetNode(index);
		before->next = node;
		node->last = before;
		after->last = node;
		node->next = after;
		this->size++;
	}
}

template<typename T>
LITECH_INLINE void liLinkedList<T>::Erase(ulong_t index) {
}

template<typename T>
LITECH_INLINE T& liLinkedList<T>::Find(const T& value) {
	LITECH_ASSERT(!IsEmpty(), "liLinkedList is empty!");
	node_t* node = first;
	while (node) {
		if (node->value == value) {
			return node->value;
		}
		node = node->next;
	}
}

template<typename T>
LITECH_INLINE const T& liLinkedList<T>::Find(const T& value) const {
	LITECH_ASSERT(!IsEmpty(), "liLinkedList is empty!");
	node_t* node = first;
	while (node) {
		if (node->value == value) {
			return node->value;
		}
		node = node->next;
	}
}

template<typename T>
LITECH_INLINE liLinkedList<T>& liLinkedList<T>::operator=(const liLinkedList& right) {
	Clear();
	if (!right.IsEmpty()) {
		node_t* node = right.first;
		while (node) {
			Push(node->value);
			node = node->next;
		}
	}
	return *this;
}

template<typename T>
LITECH_INLINE liLinkedList<T>::node_t* liLinkedList<T>::_GetNode(ulong_t index) {
	LITECH_ASSERT(!IsEmpty(), "liLinkedList is empty!");
	node_t* node = first;
	for (ulong_t i = 0; i < index; i++) {
		node = node->next;
	}
	return node;
}

#endif