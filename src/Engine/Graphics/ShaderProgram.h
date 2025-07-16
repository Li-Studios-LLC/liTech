#ifndef SHADERPROGRAM_H
#define SHADERPROGRAM_H
#pragma once
#include "UniformBuffer.h"
#include "Engine/Framework/Asset.h"

class liRenderShader;
class liComputeShader;

class liShaderProgram : public liAsset {
    friend class liRenderShader;
public:
    liShaderProgram();
    liShaderProgram(const liShaderProgram&) = delete;
    ~liShaderProgram();

    bool Link(std::unordered_map<int, std::string> attribs);
    void Bind() const;
    void LoadTexture(std::string name, ghandle_t handle);
    
    inline ghandle_t Program() const { return program; }
    inline liRenderShader* RenderShader() { return renderShader; }
    inline liComputeShader* ComputeShader() { return compute; }
private:
    ghandle_t program;
    liRenderShader* renderShader;
    liComputeShader* compute;
};

#endif