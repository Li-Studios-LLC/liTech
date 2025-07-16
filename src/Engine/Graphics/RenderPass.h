#ifndef RENDERPASS_H
#define RENDERPASS_H
#pragma once
#include "Engine/Math/Vectors.h"

class liRenderPass {
public:
    liRenderPass(int width, int height, bool useDepth = true);
    liRenderPass(const liRenderPass&) = delete;
    ~liRenderPass();

    void Begin(liColor clearColor = liColor(0.0f));
    void End();

    inline ghandle_t GetTexture() const { return colorTexture; }
    inline ghandle_t GetFramebuffer() const { return framebuffer; }
private:
    liColor clearColor;
    ghandle_t framebuffer = 0;
    ghandle_t colorTexture = 0;
    ghandle_t depthBuffer = 0;
    int width, height;
    bool useDepth;
};

#endif