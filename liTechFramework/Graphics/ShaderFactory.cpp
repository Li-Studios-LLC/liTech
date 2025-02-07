#include "ShaderFactory.h"

#define VERSION_TAG "#version 460 core"
#define MATERIAL_INPUT_STRUCT "struct MaterialInput {sampler2D img;vec4 value;int flags;};"
#define MATERIAL_STRUCT "struct Material {MaterialInput diffuse;};"

liShaderFactory::liShaderFactory(shaderType_t type) {
    this->type = type;
}

liShaderFactory::~liShaderFactory() {
}

void liShaderFactory::Generate() {
    switch(type) {
    case shaderType_t::CANVAS:
    case shaderType_t::UI:
    case shaderType_t::MAIN:
        // Vertex shader code
        vertexStream << VERSION_TAG << std::endl;
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
        vertexStream << "vec4 calculatedPosition = projection * view * model * vec4(position, 1);";
        for(std::string mod : vertexModifiers) {
            vertexStream << "position=" << mod << ';';
        }
        vertexStream << "gl_Position = calculatedPosition;";
        vertexStream << "}";

        // Pixel shader code
        pixelStream << VERSION_TAG << std::endl;
        _AddPixelBuiltins();
        pixelStream << "void main() {";
        for(std::string mod : pixelModifiers) {
            pixelStream << "outColor=" << mod << ';';
        }
        pixelStream << "}";
        break;
    case shaderType_t::COMPUTE:
        break;
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

void liShaderFactory::AddVertexModifier(std::string mod) {
    vertexModifiers.push_back(mod);
}

void liShaderFactory::AddPixelModifier(std::string mod) {
    pixelModifiers.push_back(mod);
}

void liShaderFactory::_AddVertexBuiltins() {
    vertexStream << "uniform mat4 projection;";
    vertexStream << "uniform mat4 view;";
    vertexStream << "uniform mat4 model;";
    for(liUniformMapIt it = uniforms.begin(); it != uniforms.end(); it++) {
        shaderUniform_t uniform = it->second;
        if(uniform.designation == shaderDesignation_t::VERTEX) {
            vertexStream << "uniform " << _GetDataTypeTag(uniform.dtype) << " " << uniform.name << ';';
        }
    }
}

void liShaderFactory::_AddPixelBuiltins() {
    switch (type) {
    case shaderType_t::MAIN:
        pixelStream << MATERIAL_INPUT_STRUCT << MATERIAL_STRUCT;
        break;
    }

    for(liUniformMapIt it = uniforms.begin(); it != uniforms.end(); it++) {
        shaderUniform_t uniform = it->second;
        if(uniform.designation == shaderDesignation_t::PIXEL) {
            pixelStream << "uniform " << _GetDataTypeTag(uniform.dtype) << " " << uniform.name << ';';
        }
    }
    
    switch (type) {
    case shaderType_t::MAIN:
        pixelStream << "uniform Material material;";
        break;
    }
    pixelStream << "out vec4 outColor;";
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
        return "sampler2D";
    case shaderDataType_t::INT:
    default:
        return "int";
    }
}