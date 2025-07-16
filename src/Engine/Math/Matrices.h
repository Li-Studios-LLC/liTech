#ifndef MATRICES_H
#define MATRICS_H
#pragma once
#include "Vectors.h"

class liMat4 {
public:
    liMat4();

    void SetIdentity();
    void Transpose();
    void Invert();
    
    static liMat4 Translate(liVec3 vec);
    static liMat4 Scale(liVec3 vec);
    static liMat4 RotateX(float angle);
    static liMat4 RotateY(float angle);
    static liMat4 RotateZ(float angle);
    static liMat4 Perspective(float fov, float aspectRatio, float nearPlane, float farPlane);

    liMat4 operator*(liMat4 with);
    liMat4& operator*=(liMat4 with);
    float& operator()(int x, int y);
    const float& operator()(int x, int y) const;
private:
    liMat4 _Multiply(liMat4 with);

    mat4s mat;
};

#endif