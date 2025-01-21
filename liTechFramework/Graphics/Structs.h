#ifndef LITECHFRAMEWORK_GRAPHICS_STRUCTS_H
#define LITECHFRAMEWORK_GRAPHICS_STRUCTS_H
#include "Enums.h"

struct shaderUniform_t {
    std::string name;
    shaderDataType_t dtype;
    shaderDesignation_t designation;
};

#endif