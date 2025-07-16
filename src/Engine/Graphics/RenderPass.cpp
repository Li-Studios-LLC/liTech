#include "pch.h"
#include "RenderPass.h"

liRenderPass::liRenderPass(int width, int height, bool useDepth) {
    this->width = width;
    this->height = height;
    this->useDepth = useDepth;

    glGenFramebuffers(1, &framebuffer);
    glBindFramebuffer(GL_FRAMEBUFFER, framebuffer);

    glGenTextures(1, &colorTexture);
    glBindTexture(GL_TEXTURE_2D, colorTexture);
    glTexImage2D(GL_TEXTURE_2D, 0, GL_RGBA, width, height, 0, GL_RGBA, GL_UNSIGNED_BYTE, nullptr);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);
    glFramebufferTexture2D(GL_FRAMEBUFFER, GL_COLOR_ATTACHMENT0, GL_TEXTURE_2D, colorTexture, 0);

    if (useDepth) {
        glGenRenderbuffers(1, &depthBuffer);
        glBindRenderbuffer(GL_RENDERBUFFER, depthBuffer);
        glRenderbufferStorage(GL_RENDERBUFFER, GL_DEPTH24_STENCIL8, width, height);
        glFramebufferRenderbuffer(GL_FRAMEBUFFER, GL_DEPTH_STENCIL_ATTACHMENT, GL_RENDERBUFFER, depthBuffer);
    }
    glBindFramebuffer(GL_FRAMEBUFFER, 0);
}

liRenderPass::~liRenderPass() {
    if (useDepth) {
        glDeleteRenderbuffers(1, &depthBuffer);
    }
    glDeleteTextures(1, &colorTexture);
    glDeleteFramebuffers(1, &framebuffer);
}

void liRenderPass::Begin(liColor clearColor) {
    this->clearColor = clearColor;
    glBindFramebuffer(GL_FRAMEBUFFER, framebuffer);
    glViewport(0, 0, width, height);
    glClearColor(clearColor.X(), clearColor.Y(), clearColor.Z(), clearColor.W());
    glClear(GL_COLOR_BUFFER_BIT | (useDepth ? GL_DEPTH_BUFFER_BIT : 0));
    glEnable(GL_DEPTH_TEST);
}

void liRenderPass::End() {
    glBindFramebuffer(GL_FRAMEBUFFER, 0);
}