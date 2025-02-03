#include "Matrices.h"

liMatrix2f::liMatrix2f() {
    SetIdentity();
}

void liMatrix2f::SetIdentity() {
    SetZero();
    vecs[0][0] = 1.0f;
    vecs[1][1] = 1.0f;
}

void liMatrix2f::SetZero() {
    memset(vecs, 0, sizeof(liVector4f[2]));
}

liMatrix3f::liMatrix3f() {
    SetIdentity();
}

void liMatrix3f::SetIdentity() {
    SetZero();
    vecs[0][0] = 1.0f;
    vecs[1][1] = 1.0f;
    vecs[2][2] = 1.0f;
}

void liMatrix3f::SetZero() {
    memset(vecs, 0, sizeof(liVector4f[3]));
}

liMatrix4f::liMatrix4f() {
    SetIdentity();
}

void liMatrix4f::SetIdentity() {
    SetZero();
    vecs[0][0] = 1.0f;
    vecs[1][1] = 1.0f;
    vecs[2][2] = 1.0f;
    vecs[3][3] = 1.0f;
}

void liMatrix4f::SetZero() {
    memset(vecs, 0, sizeof(liVector4f[4]));
}

void liMatrix4f::Translate(liVector3f position) {
    vecs[3][0] = position.x;
    vecs[3][1] = position.y;
    vecs[3][2] = position.z;
    vecs[3][3] = 1.0f;
}

void liMatrix4f::Scale(liVector3f scale) {
    vecs[0][0] = scale.x;
    vecs[1][1] = scale.y;
    vecs[2][2] = scale.z;
    vecs[3][3] = 1.0f;
}

void liMatrix4f::Rotate(liVector3f axis, float angle) {
    float c = cosf(angle);
	float s = sinf(angle);
	float omc = 1.0f - c;

	float x = axis.x;
	float y = axis.y;
	float z = axis.z;

	vecs[0][0] = x * x * omc + c;
	vecs[0][1] = y * x * omc + z * s;
	vecs[0][2] = x * z * omc - y * s;
	vecs[1][0] = x * y * omc - z * s;
	vecs[1][1] = y * y * omc + c;
	vecs[1][2] = y * z * omc + x * s;
	vecs[2][0] = x * z * omc + y * s;
	vecs[2][1] = y * z * omc - x * s;
	vecs[2][2] = z * z * omc + c;
}

liMatrix4f liMatrix4f::Perspective(float fov, float aspect, float nearPlane, float farPlane) {
    liMatrix4f mat;
    float q = 1.0f / tan(LITECH_RADIANS(fov / 2.0f));
	float a = q / aspect;
	float frustumLength = farPlane - nearPlane;
	float b = (nearPlane + farPlane) / frustumLength;
	float c = (2.0f * nearPlane * farPlane) / frustumLength;

	mat[0][0] = a;
	mat[1][1] = q;
	mat[2][2] = b;
	mat[2][3] = -1.0f;
	mat[3][2] = c;
	mat[3][3] = 1.0f;
    return mat;
}

liMatrix4f liMatrix4f::operator*(liMatrix4f mat) {
    liMatrix4f result = *this;
    result._Multiply(mat);
    return result;
}

liMatrix4f& liMatrix4f::operator*=(liMatrix4f mat) {
    _Multiply(mat);
    return *this;
}

void liMatrix4f::_Multiply(liMatrix4f mat) {
    for(int i = 0; i < 4; i++) {
        for(int j = 0; j < 4; j++) {
            vecs[i][j] += vecs[i][j] * mat[i][j];
        }   
    }
}