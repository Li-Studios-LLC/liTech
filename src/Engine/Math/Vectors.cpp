#include "pch.h"
#include "Vectors.h"

// Vector2
liVec2::liVec2(float x, float y) {
    this->vec = { x, y };
}

liVec2::liVec2(float all) {
    this->vec = { all, all };
}

// Vector3
liVec3::liVec3(float x, float y, float z) {
    this->vec = { x, y, z };
}

liVec3::liVec3(float all) {
    this->vec = { all, all, all };
}

// Vector4
liVec4::liVec4(float x, float y, float z, float w) {
    this->vec = { x, y, z, w };
}

liVec4::liVec4(float all) {
    this->vec = { all, all, all, all };
}