#ifndef LITECHFRAMEWORK_SHADER_H
#define LITECHFRAMEWORK_SHADER_H
#include "GraphicsObject.h"
#include "Enums.h"

class liShader : public liGraphicsObject<1> {
public:
    liShader(shaderDesignation_t designation);
    ~liShader();

    virtual void Initialize() override;
    virtual void Delete() override;
    // Does nothing, hash is calculated when shader is compiled.
    virtual void CalculateHash() override { }

    int Compile(const std::string& src);
private:
    static uint_t _GetShaderDesignation(shaderDesignation_t designation);

    shaderDesignation_t designation;
};

#endif