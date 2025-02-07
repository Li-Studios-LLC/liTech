#include "ShaderFactory.h"

#define VERSION_TAG "#version 460 core"
#define MATERIAL_INPUT_STRUCT "struct MaterialInput { sampler2D img; vec4 value; float mixValue; bool usesTexture; };"
#define MATERIAL_STRUCT "struct Material { MaterialInput diffuse; };"
#define CALCULATE_INPUT_FUNC "vec4 calculateInput(MaterialInput i) { return mix(i.usesTexture ? texture(i.img, outTexCoords) : vec4(1), i.value, i.mixValue); }"
#define MATERIAL_CODE (MATERIAL_INPUT_STRUCT MATERIAL_STRUCT CALCULATE_INPUT_FUNC)

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
        _AddVertexBuiltins();
        vertexStream << "void main() {";
        vertexStream << "vec4 calculatedPosition = projection * view * model * vec4(position, 1);";
        vertexStream << "outTexCoords = texCoords;";
        vertexStream << "gl_Position = calculatedPosition;";
        vertexStream << "}";

        // Pixel shader code
        pixelStream << VERSION_TAG << std::endl;
        _AddPixelBuiltins();
        pixelStream << "void main() {";
        pixelStream << "vec4 diffuse = calculateInput(material.diffuse);";
        pixelStream << "outColor = diffuse;";
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

void liShaderFactory::_AddVertexBuiltins() {
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
    vertexStream << "uniform mat4 projection;";
    vertexStream << "uniform mat4 view;";
    vertexStream << "uniform mat4 model;";
    vertexStream << "out vec2 outTexCoords;";
    for(liUniformMapIt it = uniforms.begin(); it != uniforms.end(); it++) {
        shaderUniform_t uniform = it->second;
        if(uniform.designation == shaderDesignation_t::VERTEX) {
            vertexStream << "uniform " << _GetDataTypeTag(uniform.dtype) << " " << uniform.name << ';';
        }
    }
}

void liShaderFactory::_AddPixelBuiltins() {
    pixelStream << "in vec2 outTexCoords;";
    pixelStream << "out vec4 outColor;";
    switch (type) {
    case shaderType_t::MAIN:
        pixelStream << MATERIAL_CODE;
        pixelStream << "uniform Material material;";
        break;
    }

    for(liUniformMapIt it = uniforms.begin(); it != uniforms.end(); it++) {
        shaderUniform_t uniform = it->second;
        if(uniform.designation == shaderDesignation_t::PIXEL) {
            pixelStream << "uniform " << _GetDataTypeTag(uniform.dtype) << " " << uniform.name << ';';
        }
    }
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