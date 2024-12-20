#ifndef LITECHBASE_HASHMAP_H
#define LITECHBASE_HASHMAP_H

template <typename K, typename V>
class liHashMap {
public:
	typedef liPair<K, V> element_t;
	typedef liLinkedList<element_t> bucket_t;
private:
	liList<bucket_t> buckets;
};

#endif