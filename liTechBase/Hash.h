#ifndef LITECHBASE_HASH_H
#define LITECHBASE_HASH_H
#include "Typedefs.h"

class liHash {
public:
	static ulong_t HashDJB2(byte_t* bytes, ulong_t size);
};

#endif