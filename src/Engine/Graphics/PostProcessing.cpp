#include "pch.h"
#include "PostProcessing.h"
#include <Engine/Math/Vertex.h>
#include <Engine/Graphics/RenderPass.h>
#include <Engine/Graphics/RenderShader.h>
#include <Engine/Graphics/ShaderProgram.h>
#include <Engine/Tools/FileIO.h>

float fboVertices[] = {
    -1.0f, 1.0f, 0.0f, 1.0f,
    -1.0f, -1.0f, 0.0f, 0.0f,
    1.0f, -1.0f, 1.0f, 0.0f,

    -1.0f, 1.0f, 0.0f, 1.0f,
    1.0f, -1.0f, 1.0f, 0.0f,
    1.0f, 1.0f, 1.0f, 1.0f
};

liPostProcessing::liPostProcessing() {
    glGenVertexArrays(1, &vao);
    glGenBuffers(1, &vbo);
    glBindVertexArray(vao);
    glBindBuffer(GL_ARRAY_BUFFER, vbo);
    glBufferData(GL_ARRAY_BUFFER, 24 * sizeof(float), fboVertices, GL_STATIC_DRAW);
    glVertexAttribPointer(0, 2, GL_FLOAT, GL_FALSE, 4 * sizeof(float), (void*)0);
    glVertexAttribPointer(1, 2, GL_FLOAT, GL_FALSE, 4 * sizeof(float), (void*)(2 * sizeof(float)));
    glBindVertexArray(0);
    
    this->program = new liShaderProgram();
    this->renderShader = new liRenderShader();
    liCharBuffer vertexSource, pixelSource;
    liFileIO::Read(LI_ASSET_PATH + "Shaders/final.vert", vertexSource);
    liFileIO::Read(LI_ASSET_PATH + "Shaders/final.frag", pixelSource);
    renderShader->CompileVertex(vertexSource.data());
    renderShader->CompilePixel(pixelSource.data());
    
    this->renderShader->Attach(program);
    this->program->Link({ { 0, "position" }, { 1, "texCoord" } });
    this->uniform = new liUniformBuffer(sizeof(PixelUniform));
}

liPostProcessing::~liPostProcessing() {
    delete uniform;
    delete renderShader;
    delete program;
    glDeleteBuffers(1, &vbo);
    glDeleteBuffers(1, &vao);
}

void liPostProcessing::Process(liRenderPass* source) {
    glDisable(GL_DEPTH_TEST);
    glBindVertexArray(vao);
    
    PixelUniform uniformData = { };
    
    program->Bind();
    uniform->Upload(&uniformData);
    uniform->Bind(program->Program(), "PixelUniform", 1);
    glBindTexture(GL_TEXTURE_2D, source->GetTexture());
    glEnableVertexAttribArray(0);
    glEnableVertexAttribArray(1);
    glDrawArrays(GL_TRIANGLES, 0, 6);
    
    glBindVertexArray(0);
}