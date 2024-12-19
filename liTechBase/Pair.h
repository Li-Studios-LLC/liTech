#ifndef LITECHBASE_PAIR_H
#define LITECHBASE_PAIR_H

template <typename F, typename S>
struct liPair {
	liPair() {
		this->first = F();
		this->second = S();
	}

 	liPair(F first, S second) {
		this->first = first;
		this->second = second;
	}

	liPair(const liPair& right) {
		*this = right;
	}

	~liPair() {}

	void DeleteBoth() {
		liDelete(first);
		liDelete(second);
	}

	liPair& operator=(const liPair& right) {
		this->first = right.first;
		this->second = right.second;
		return *this;
	}

	bool operator==(const liPair& right) const {
		return (first == right.first) && (second == right.second);
	}

	bool operator!=(const liPair& right) const {
		return !(*this == right);
	}

	F first;
	S second;
};

template <typename F, typename S>
LITECH_INLINE const liPair<F, S>& liMakePair(const F& first, const S& second) {
	return liPair<F, S>(first, second);
}

#endif