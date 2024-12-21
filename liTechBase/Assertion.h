#ifndef LITECHBASE_ASSERTION_H
#define LITECHBASE_ASSERTION_H
#include "Typedefs.h"

#ifdef LITECH_DEBUG

class liAssert {
public:
	static void Break();
	static void Assert(bool expr, const char* message);
};

#define LITECH_ASSERT(expr, message) liAssert::Assert(expr, message)
#else
#define LITECH_ASSERT(expr, message)
#endif

#endif