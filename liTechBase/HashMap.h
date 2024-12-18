#ifndef LITECHBASE_HASHMAP_H
#define LITECHBASE_HASHMAP_H

template <typename K, typename V>
class liHashMap {
public:
	typedef liPair<K, V> element_t;

	liHashMap();
	~liHashMap();

	void Clear();
	void DeleteKeys();
	void DeleteValues();
	void Emplace(const K& key, const V& value);
	const V& Search(const K& key) const;
	V& Search(const K& key);

	V& operator[](const K& key) { return Search(key); }
	const V& operator[](const K& key) const { return Search(key); }
private:

	liList<element_t> elements;
};

template<typename K, typename V>
LITECH_INLINE liHashMap<K, V>::liHashMap() {
}

template<typename K, typename V>
LITECH_INLINE liHashMap<K, V>::~liHashMap() {
}

template<typename K, typename V>
LITECH_INLINE void liHashMap<K, V>::Clear() {
	elements.Clear();
}

template<typename K, typename V>
LITECH_INLINE void liHashMap<K, V>::DeleteKeys() {
	for (ulong_t i = 0; i < elements.Size(); i++) {
		liDelete(elements[i].first);
	}
}

template<typename K, typename V>
LITECH_INLINE void liHashMap<K, V>::DeleteValues() {
	for (ulong_t i = 0; i < elements.Size(); i++) {
		liDelete(elements[i].second);
	}
}

template<typename K, typename V>
LITECH_INLINE void liHashMap<K, V>::Emplace(const K& key, const V& value) {
}

template<typename K, typename V>
inline V& liHashMap<K, V>::Search(const K& key) {
	for (ulong_t i = 0; i < elements.Size(); i++) {
		if (elements[i].first == key) {
			return elements[i].second;
		}
	}
}

template<typename K, typename V>
inline const V& liHashMap<K, V>::Search(const K& key) const {
	for (ulong_t i = 0; i < elements.Size(); i++) {
		if (elements[i].first == key) {
			return elements[i].second;
		}
	}
}

#endif