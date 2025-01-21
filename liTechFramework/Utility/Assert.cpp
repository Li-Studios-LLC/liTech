#include "Assert.h"

#ifdef LITECH_DEBUG
void liTechAssert(bool condition, std::string msg) {   
    if(!condition) {
        liTechPrint("Assertion failed: %s", msg);
        SDL_TriggerBreakpoint();
    }
}
#else
void liTechAssert(bool condition, std::string msg) {
}
#endif