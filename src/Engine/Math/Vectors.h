#ifndef VECTORS_H
#define VECTORS_H
#pragma once

class liVec2 {
public:
    liVec2(float x, float y);
    liVec2(float all = 0.0f);

    inline float* Ptr() { return (float*)&vec.x; }
    inline const float* Ptr() const { return (float*)&vec.x; }
    inline void SetX(float x) { vec.x = x; }
    inline void SetY(float y) { vec.y = y; }
    inline float X() const { return vec.x; }
    inline float Y() const { return vec.y; }
private:
    vec2s vec;
};

class liVec3 {
public:
    liVec3(float x, float y, float z);
    liVec3(float all = 0.0f);

    inline float* Ptr() { return (float*)&vec.x; }
    inline const float* Ptr() const { return (float*)&vec.x; }
    inline void SetX(float x) { vec.x = x; }
    inline void SetY(float y) { vec.y = y; }
    inline void SetZ(float z) { vec.z = z; }
    inline float X() const { return vec.x; }
    inline float Y() const { return vec.y; }
    inline float Z() const { return vec.z; }
private:
    vec3s vec;
};

class liVec4 {
public:
    liVec4(float x, float y, float z, float w);
    liVec4(float all = 0.0f);

    inline float* Ptr() { return (float*)&vec.x; }
    inline const float* Ptr() const { return (float*)&vec.x; }
    inline void SetX(float x) { vec.x = x; }
    inline void SetY(float y) { vec.y = y; }
    inline void SetZ(float z) { vec.z = z; }
    inline void SetW(float w) { vec.w = w; }
    inline float X() const { return vec.x; }
    inline float Y() const { return vec.y; }
    inline float Z() const { return vec.z; }
    inline float W() const { return vec.w; }
private:
    vec4s vec;
};

typedef liVec4 liColor;

#endif