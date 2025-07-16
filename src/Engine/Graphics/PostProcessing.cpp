#include "pch.h"
#include "PostProcessing.h"
#include <Engine/Math/Vertex.h>
#include <Engine/Graphics/RenderPass.h>
#include <Engine/Graphics/RenderShader.h>
#include <Engine/Graphics/ShaderProgram.h>
#include <Engine/Tools/FileIO.h>

float vertices[] = {
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
    glBufferData(GL_ARRAY_BUFFER, 24 * sizeof(float), vertices, GL_STATIC_DRAW);
    glVertexAttribPointer(0, 2, GL_FLOAT, GL_FALSE, 4 * sizeof(float), (void*)0);
    glVertexAttribPointer(1, 2, GL_FLOAT, GL_FALSE, 4 * sizeof(float), (void*)(2 * sizeof(float)));
    glBindVertexArray(0);
    
    this->program = new liShaderProgram();
    this->renderShader = new liRenderShader();
    std::string vertexSource, pixelSource;
    liFileIO::Read("./Assets/Shaders/final.vert", vertexSource);
    liFileIO::Read("./Assets/Shaders/final.frag", pixelSource);
    renderShader->CompileVertex(vertexSource);
    renderShader->CompilePixel(pixelSource);
    
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