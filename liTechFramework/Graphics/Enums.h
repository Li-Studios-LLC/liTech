#ifndef LITECHFRAMEWORK_GRAPHICS_ENUMS_H
#define LITECHFRAMEWORK_GRAPHICS_ENUMS_H

enum class shaderType_t {
    UI,
    CANVAS, // 2D
    MAIN, // 3D
    COMPUTE
};

enum class shaderDataType_t {
    VEC2,
    VEC3,
    VEC4,
    MAT4,
    INT,
    FLOAT,
    SAMPLER2D
};

enum class shaderDesignation_t {
    VERTEX,
    PIXEL,
    COMPUTE
};

#endif