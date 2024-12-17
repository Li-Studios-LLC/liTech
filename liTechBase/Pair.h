#ifndef LITECHBASE_PAIR_H
#define LITECHBASE_PAIR_H

template <typename F, typename S>
class liPair {
public:
	liPair() { }
	
	liPair(F first, S second) {
		this->first = first;
		this->second = second;
	}

	void DeleteBoth() {
		liDelete(first);
		liDelete(second);
	}

	union {
		struct {
			F first;
			S second;
		};

		struct {
			F key;
			S value;
		};
	};
};

#endif