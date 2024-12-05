#ifndef LITECHBASE_PRECOMPILED_H
#define LITECHBASE_PRECOMPILED_H

#include <stdio.h>
#include <string.h>
#include <stdarg.h>
#include <stdlib.h>
#include <math.h>

#define LITECH_NAME "liTech"
#define LITECH_MAJOR 1
#define LITECH_MINOR 0
#define LITECH_REVISION 0

#ifdef _WIN32
#define WIN32_LEAN_AND_MEAN
#include <Windows.h>
#define LITECH_WIN32
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
#define LITECH_KB(bytes) (float)(bytes / 1024.0f)
#define LITECH_MB(bytes) (float)(LITECH_KB(bytes) / 1024.0f)
#define LITECH_PI 3.141592f
#define LITECH_RADIANS(degrees) (degrees * LITECH_PI / 180)
#define LITECH_DEGREES(radians) (degrees * 180 / LITECH_PI)

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

#endif