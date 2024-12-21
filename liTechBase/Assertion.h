#ifndef LITECHBASE_ASSERTION_H
#define LITECHBASE_ASSERTION_H
#include "Typedefs.h"

#ifdef LITECH_DEBUG

class liAssert {
public:
	static liAssert& Instance() {
		static liAssert instance;
		return instance;
	}

	void Break();
	void Assert(bool expr, const char* message);
};

#define LITECH_ASSERT(expr, message) liAssert::Instance().Assert(expr, message)
#else
#define LITECH_ASSERT(expr, message)
#endif

#endif