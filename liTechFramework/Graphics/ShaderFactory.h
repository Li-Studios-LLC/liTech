#ifndef LITECHFRAMEWORK_SHADER_FACTORY_H
#define LITECHFRAMEWORK_SHADER_FACTORY_H
#include "Typedefs.h"
#include "Enums.h"

class liShaderFactory {
public:
    liShaderFactory(shaderType_t type);
    ~liShaderFactory();

    void Generate();
    void Regenerate();

    LITECH_INLINE std::string VertexCode() const { return vertexStream.str(); }
    LITECH_INLINE std::string PixelCode() const { return pixelStream.str(); }
private:
    shaderType_t type;
    std::stringstream vertexStream, pixelStream;
};

#endif