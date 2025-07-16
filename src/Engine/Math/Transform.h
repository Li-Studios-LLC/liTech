#ifndef TRANSFORM_H
#define TRANSFORM_H
#pragma once
#include "Matrices.h"

class liTransform {
public:
    liTransform(liVec3 position = liVec3(0), liVec3 rotation = liVec3(0), liVec3 scale = liVec3(1));

    liMat4 CalculateMatrix() const;

    liVec3 position, rotation, scale;
};

#endif