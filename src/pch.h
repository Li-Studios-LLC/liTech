#ifndef PCH_H
#define PCH_H
#pragma once

#define LI_ARRAYSIZE(arr) (sizeof(arr) / sizeof(*arr))
#define LI_STRINGIFY(x) #x
#define LI_BIT(x) (1 << x)
#define LI_TIMESTAMP() (ulong_t)(time(NULL))
#define LI_PLATFORM_NAME() (SDL_GetPlatform())
#define LI_CPU_COUNT() (SDL_GetNumLogicalCPUCores())
#define LI_MAIN_THREAD() (SDL_IsMainThread())
#define LI_PI 3.14159265359f
#define LI_RADIANS(degrees) ((degrees) * LI_PI / 180)
#define LI_DEGREES(radians) ((radians) * 180 / LI_PI)

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
#include <vector>
#include <bitset>
#include <chrono>
#include <algorithm>
#include <functional>
#include <fstream>
#include <limits>
#include <bitset>
#include <map>
#include <array>
#include <variant>
#include <assert.h>
#include <string.h>
#include <math.h>

// External libraries
#include <SDL3/SDL.h>
#include <AL/al.h>
#include <tinyxml2.h>
#include <cglm/struct.h>
#include <glad/gl.h>

typedef std::vector<bool> liBoolBuffer;
typedef std::vector<int> liIntBuffer;
typedef std::vector<uint_t> liUIntBuffer;
typedef std::vector<float32_t> liFloatBuffer;
typedef std::vector<byte_t> liCharBuffer;

#define LI_GUID_LENGTH 0x10
union guid_t {
    struct {
        byte_t id[LI_GUID_LENGTH];
        ubyte_t null;
    };
};

struct IRunnable {
    virtual ~IRunnable() { }

    virtual void Setup() = 0;
    virtual void Render() = 0;
    virtual void Update(float deltaTime) = 0;
};

struct rawBuffer_t {
    void* buffer;
    ulong_t size;
};

#endif