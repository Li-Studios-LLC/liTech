#ifndef LITECHFRAMEWORK_TYPEDEFS_H
#define LITECHFRAMEWORK_TYPEDEFS_H

#define LITECH_MAJOR 1
#define LITECH_MINOR 0
#define LITECH_REVISION 0

#ifdef LITECH_WIN32
#define LITECH_INLINE __forceinline
#define LITECH_EXPORT __declspec(dllexport)
#else
#define LITECH_INLINE inline
#define LITECH_EXPORT
#endif

#ifdef _DEBUG
#define LITECH_DEBUG
#define LITECH_VERBOSE_MEMORY
#else
#define LITECH_RELEASE
#endif

#define LITECH_ARRAYSIZE(arr) (sizeof(arr) / sizeof(*arr))
#define LITECH_STRINGIFY(x) #x
#define LITECH_BIT(x) (1 << x)
#define LITECH_OK 1
#define LITECH_BAD -1
#define LITECH_PI 3.141592f
#define LITECH_RADIANS(degrees) (degrees * LILIB_PI / 180)
#define LITECH_DEGREES(radians) (degrees * 180 / LILIB_PI)
#define LITECH_PLATFORM_NAME() (SDL_GetPlatform())
#define LITECH_CPU_COUNT() (SDL_GetCPUCount())
#define LITECH_DELETE_INSTANCE(class) (delete class::Instance())

typedef unsigned char ubyte_t;
typedef char byte_t;
typedef unsigned short ushort_t;
typedef unsigned int uint_t;
typedef long long long_t;
typedef unsigned long long ulong_t;
typedef float float32_t;
typedef double float64_t;
typedef const char* cstring_t;
typedef void* memory_t;

#include <iostream>
#include <algorithm>
#include <utility>
#include <unordered_map>
#include <vector>
#include <list>
#include <string>
#include "Utility/Print.h"
#include <SDL3/SDL.h>

#endif