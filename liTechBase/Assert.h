#ifndef LITECHBASE_ASSERT_H
#define LITECHBASE_ASSERT_H
#include "Typedefs.h"

class liAssert {
public:
    static void Break();
    static void Assert(bool expr, const char* message);
};

#ifdef LITECH_DEBUG
#define LITECH_ASSERT(expr, message) liAssert::Assert(expr, message)
#else
#define LITECH_ASSERT(expr, message)
#endif

#endif