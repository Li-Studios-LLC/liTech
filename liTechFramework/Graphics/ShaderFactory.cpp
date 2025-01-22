#include "ShaderFactory.h"

#define VERSION_TAG "#version 320 es"
#define PRECISIONS "precision mediump float;"

liShaderFactory::liShaderFactory(shaderType_t type) {
    this->type = type;
}

liShaderFactory::~liShaderFactory() {
}

void liShaderFactory::Generate() {
    if(type != shaderType_t::COMPUTE) {
        // Vertex shader code
        vertexStream << VERSION_TAG << std::endl;
        vertexStream << PRECISIONS;
        vertexStream << "layout (location = 0) in vec3 position;";
        switch (type) {
        case shaderType_t::UI:
        case shaderType_t::CANVAS:
            vertexStream << "layout (location = 1) in vec2 texCoords;";
            break;
        case shaderType_t::MAIN:
            vertexStream << "layout (location = 1) in vec2 texCoords;";
            vertexStream << "layout (location = 2) in vec3 normals;";
            break;
        }
        _AddVertexBuiltins();
        vertexStream << "void main() {";
        vertexStream << "}";

        // Pixel shader code
        pixelStream << VERSION_TAG << std::endl;
        pixelStream << PRECISIONS;
        _AddPixelBuiltins();
        pixelStream << "void main() {";
        pixelStream << "}";
    }
}

void liShaderFactory::Regenerate() {
    vertexStream.clear();
    pixelStream.clear();
    computeStream.clear();
    Generate();
}

void liShaderFactory::AddUniform(std::string name, shaderDataType_t dtype, shaderDesignation_t designation) {
    shaderUniform_t uniform;
    uniform.name = name;
    uniform.dtype = dtype;
    uniform.designation = designation;
    uniforms.emplace(name, uniform);
}

void liShaderFactory::_AddVertexBuiltins() {
    _AddBuiltins(vertexStream);
    vertexStream << "layout(std140) uniform VertexUniform {";
    vertexStream << "mat4 projection;";
    vertexStream << "mat4 view;";
    vertexStream << "mat4 model;";
    for(liUniformMapIt it = uniforms.begin(); it != uniforms.end(); it++) {
        shaderUniform_t uniform = it->second;
        if(uniform.designation == shaderDesignation_t::VERTEX) {
            vertexStream << _GetDataTypeTag(uniform.dtype) << " " << uniform.name << ";";
        }
    }
    vertexStream << "};";
}

void liShaderFactory::_AddPixelBuiltins() {
    _AddBuiltins(pixelStream);
    pixelStream << "layout(std140) uniform PixelUniform {";
    for(liUniformMapIt it = uniforms.begin(); it != uniforms.end(); it++) {
        shaderUniform_t uniform = it->second;
        if(uniform.designation == shaderDesignation_t::PIXEL) {
            pixelStream << _GetDataTypeTag(uniform.dtype) << " " << uniform.name << ";";
        }
    }
    pixelStream << "};";
    pixelStream << "out vec4 outColor;";
}

void liShaderFactory::_AddBuiltins(std::stringstream& stream) {
}

std::string liShaderFactory::_GetDataTypeTag(shaderDataType_t dtype) {
    switch (dtype) {
    case shaderDataType_t::VEC2:
        return "vec2";
    case shaderDataType_t::VEC3:
        return "vec3";
    case shaderDataType_t::VEC4:
        return "vec4";
    case shaderDataType_t::MAT4:
        return "mat4";
    case shaderDataType_t::FLOAT:
        return "float";
    case shaderDataType_t::SAMPLER2D:
        return "sampler2d";
    case shaderDataType_t::INT:
    default:
        return "int";
    }
}