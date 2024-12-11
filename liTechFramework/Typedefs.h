#ifndef LITECHFRAMEWORK_TYPEDEFS_H
#define LITECHFRAMEWORK_TYPEDEFS_H

#include <liTechBase/Lib.h>
#include <SDL3/SDL.h>
#include <glad/gles2.h>

#define LITECH_DELETE_INSTANCE(class) (liDelete(class::Instance()))
#define LITECH_CPU_COUNT (SDL_GetCPUCount())
#define LITECH_PLATFORM (SDL_GetPlatform())
#define LITECH_RAM_MB (SDL_GetSystemRAM())

#endif