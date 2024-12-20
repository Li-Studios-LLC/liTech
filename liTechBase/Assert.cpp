#include "Assert.h"

void liAssert::Break() {
#ifdef LITECH_WIN32
	DebugBreak();
#else
#endif
}


void liAssert::Assert(bool expr, const char* message) {
	if (!expr) {
		printf("liAssert failed: %s\n", message);
		Break();
	}
}