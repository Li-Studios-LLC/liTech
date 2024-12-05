#include "Assert.h"

#ifdef _WIN32
#include <Windows.h>

void liAssert::Break() {
    DebugBreak();
}

#endif

void liAssert::Assert(bool expr, const char* message) {
    if(!expr) {
        printf("liAssert failed: %s\n", message);
        Break();
    }
}