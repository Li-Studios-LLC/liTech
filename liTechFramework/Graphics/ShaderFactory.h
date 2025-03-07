#ifndef LITECHFRAMEWORK_SHADER_FACTORY_H
#define LITECHFRAMEWORK_SHADER_FACTORY_H
#include "Typedefs.h"
#include "Enums.h"
#include "Structs.h"

typedef std::unordered_map<std::string, shaderUniform_t> liUniformMap;
typedef std::unordered_map<std::string, shaderUniform_t>::iterator liUniformMapIt;

class liShaderFactory {
public:
    liShaderFactory(shaderType_t type);
    ~liShaderFactory();

    void Generate();
    void Regenerate();
    void AddUniform(std::string name, shaderDataType_t dtype, shaderDesignation_t designation);

    LITECH_INLINE std::string VertexCode() const { return vertexStream.str(); }
    LITECH_INLINE std::string PixelCode() const { return pixelStream.str(); }
    LITECH_INLINE std::string ComputeCode() const { return computeStream.str(); }
    LITECH_INLINE shaderType_t Type() const { return type; }
private:
    void _AddVertexBuiltins();
    void _AddPixelBuiltins();
    static std::string _GetDataTypeTag(shaderDataType_t dtype);

    shaderType_t type;
    std::stringstream vertexStream, pixelStream, computeStream;
    std::unordered_map<std::string, shaderUniform_t> uniforms;
};

#endif