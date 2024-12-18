#include "Assert.h"

#ifdef LITECH_WIN32

void liAssert::Break() {
	DebugBreak();
}

#endif

void liAssert::Assert(bool expr, const char* message) {
	if (!expr) {
		printf("liAssert failed: %s\n", message);
		Break();
	}
}