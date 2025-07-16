#include "pch.h"
#include "Transform.h"

liTransform::liTransform(liVec3 position, liVec3 rotation, liVec3 scale) {
    this->position = position;
    this->rotation = rotation;
    this->scale = scale;
}

liMat4 liTransform::CalculateMatrix() const {
    return liMat4::Translate(scale) * (liMat4::RotateX(rotation.X()) * liMat4::RotateX(rotation.Y()) * liMat4::RotateX(rotation.Z())) * liMat4::Scale(scale);
}