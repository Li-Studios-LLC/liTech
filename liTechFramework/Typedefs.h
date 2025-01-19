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
#define LITECH_TIMESTAMP() (ulong_t)(time(NULL))
#define LITECH_PLATFORM_NAME() (SDL_GetPlatform())
#define LITECH_CPU_COUNT() (SDL_GetNumLogicalCPUCores())
#define LITECH_MAIN_THREAD() (SDL_IsMainThread())
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
typedef unsigned int ghandle_t;

#include <iostream>
#include <algorithm>
#include <utility>
#include <unordered_map>
#include <vector>
#include <list>
#include <bitset>
#include <string>
#include <memory>
#include <glad/gles2.h>
#include <SDL3/SDL.h>

typedef std::vector<bool> liBoolBuffer;
typedef std::vector<int> liIntBuffer;
typedef std::vector<unsigned int> liUIntBuffer;
typedef std::vector<float> liFloatBuffer;
typedef std::vector<float> liCharBuffer;

// Some wrappers
#include "Utility/Print.h"

#endif