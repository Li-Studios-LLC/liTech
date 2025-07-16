#ifndef POSTPROCESSING_H
#define POSTPROCESSING_H
#pragma once

class liRenderShader;
class liShaderProgram;
class liUniformBuffer;
class liRenderPass;

class liPostProcessing {
    struct PixelUniform {
        int padding[4];
    };
public:
    liPostProcessing();
    liPostProcessing(const liPostProcessing&) = delete;
    ~liPostProcessing();

    void Process(liRenderPass* source);
private:
    liRenderShader* renderShader;
    liShaderProgram* program;
    liRenderPass* source;
    liUniformBuffer* uniform;
    ghandle_t vao, vbo;
};

#endif