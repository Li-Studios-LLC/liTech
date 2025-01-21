#include "ShaderFactory.h"

#define VERSION_TAG "#version 320 es"
#define PRECISIONS "precision mediump float;"

liShaderFactory::liShaderFactory(shaderType_t type) {
    this->type = type;
}

liShaderFactory::~liShaderFactory() {
}

void liShaderFactory::Generate() {
    // Vertex shader code
    vertexStream << VERSION_TAG << std::endl;
    vertexStream << PRECISIONS << std::endl;
    vertexStream << "void main() {" << std::endl;
    vertexStream << "}" << std::endl;

    // Pixel shader code
    pixelStream << VERSION_TAG << std::endl;
    pixelStream << PRECISIONS << std::endl;
    pixelStream << "void main() {" << std::endl;
    pixelStream << "}" << std::endl;
}

void liShaderFactory::Regenerate() {
    vertexStream.clear();
    pixelStream.clear();
    Generate();
}