#ifndef RENDERSHADER_H
#define RENDERSHADER_H
#pragma once
#include "Engine/Framework/Asset.h"

class liShaderProgram;

class liRenderShader : public liAsset {
    friend class liShaderProgram;
public:
    liRenderShader();
    liRenderShader(class liRenderShader&) = delete;
    ~liRenderShader();

    bool CompileVertex(std::string_view source);
    bool CompilePixel(std::string_view source);
    void Attach(liShaderProgram* program);
private:
    ghandle_t vertex, pixel;
};

#endif