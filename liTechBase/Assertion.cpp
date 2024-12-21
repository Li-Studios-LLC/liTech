#include "Assertion.h"

#ifdef LITECH_DEBUG

#ifdef LITECH_WIN32
void liAssert::Break() {
	DebugBreak();
}
#else
#include <signal.h>

void liAssert::Break() {
	raise(SIGTRAP);
}
#endif

void liAssert::Assert(bool expr, const char* message) {
	if (!expr) {
		printf("liAssert failed: %s\n", message);
		Break();
	}
}

#endif