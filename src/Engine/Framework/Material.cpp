#include "pch.h"
#include "Material.h"
#include "Engine/Graphics/ShaderProgram.h"

liMaterial::liMaterial(liShaderProgram* program) {
    this->program = program;
    this->vertexUniform = new liUniformBuffer(sizeof(vertexMaterialData_t));
    this->pixelUniform = new liUniformBuffer(sizeof(pixelMaterialData_t));
    std::memset((void*)&vertexData, 0, sizeof(vertexMaterialData_t));
    std::memset((void*)&pixelData, 0, sizeof(pixelMaterialData_t));
}

liMaterial::~liMaterial() {
    delete pixelUniform;
    delete vertexUniform;
}

void liMaterial::Bind() {
    program->Bind();
    vertexUniform->Bind(program->Program(), "VertexUniform", 0);
    pixelUniform->Bind(program->Program(), "PixelUniform", 1);
}

void liMaterial::Update() {
    vertexUniform->Upload((void*)&vertexData);
    pixelUniform->Upload((void*)&pixelData);
}

void liMaterial::SetVertexData(vertexMaterialData_t data) {
    this->vertexData = data;
    vertexUniform->Upload((void*)&vertexData);
}

void liMaterial::SetPixelData(pixelMaterialData_t data) {
    this->pixelData = data;
    pixelUniform->Upload((void*)&pixelData);
}