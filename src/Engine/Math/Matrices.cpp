#include "pch.h"
#include "Matrices.h"

liMat4::liMat4() {
    SetIdentity();
}

void liMat4::SetIdentity() {
    this->mat = GLMS_MAT4_IDENTITY_INIT;
}

void liMat4::Transpose() {
    this->mat = glms_mat4_transpose(mat);
}

void liMat4::Invert() {
    this->mat = glms_mat4_inv(mat);
}

liMat4 liMat4::Translate(liVec3 vec) {
    liMat4 result;
    result.mat = glms_translate(result.mat, (vec3s&)vec);
    return result;
}

liMat4 liMat4::Scale(liVec3 vec) {
    liMat4 result;
    result.mat = glms_scale(result.mat, (vec3s&)vec);
    return result;
}

liMat4 liMat4::RotateX(float angle){
    liMat4 result;
    result.mat = glms_rotate_x(result.mat, angle);
    return result;
}

liMat4 liMat4::RotateY(float angle) {
    liMat4 result;
    result.mat = glms_rotate_y(result.mat, angle);
    return result;
}

liMat4 liMat4::RotateZ(float angle) {
    liMat4 result;
    result.mat = glms_rotate_z(result.mat, angle);
    return result;
}

liMat4 liMat4::Perspective(float fov, float aspectRatio, float nearPlane, float farPlane) {
    liMat4 result;
    result.mat = glms_perspective(LI_RADIANS(fov), aspectRatio, nearPlane, farPlane);
    return result;
}

liMat4 liMat4::operator*(liMat4 with) {
    liMat4 result = *this;
    result._Multiply(with);
    return result;
}

liMat4& liMat4::operator*=(liMat4 with) {
    *this = _Multiply(with);
    return *this;
}

float& liMat4::operator()(int x, int y) {
    int index = y * 4 + x;
    return ((float*)mat.raw)[index];
}

const float& liMat4::operator()(int x, int y) const {
    int index = y * 4 + x;
    return ((float*)mat.raw)[index];
}

liMat4 liMat4::_Multiply(liMat4 with) {
    liMat4 result;
    result.mat = glms_mat4_mul(mat, with.mat);
    return result;
}