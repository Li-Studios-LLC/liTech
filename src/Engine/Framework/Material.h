#ifndef MATERIAL_H
#define MATERIAL_H
#pragma once
#include "Asset.h"
#include "IMaterial.h"
#include "Engine/Math/Vectors.h"
#include "Engine/Math/Matrices.h"

class liShaderProgram;
class liUniformBuffer;

enum class materialType_t : uint_t {
    LIT = 0,
    UNLIT = 1,
    CUSTOM = 2
};

struct pixelMaterialData_t {
    materialType_t type;
    liColor color;
};

struct vertexMaterialData_t {
    liMat4 projection;
    liMat4 view;
    liMat4 model;
};

class liMaterial : public IMaterial, public liAsset {
public:
    liMaterial(liShaderProgram* program = nullptr);
    liMaterial(const liMaterial&) = delete;
    ~liMaterial();
    
    virtual void Bind() override;
    virtual void Update() override;
    void SetVertexData(vertexMaterialData_t data);
    void SetPixelData(pixelMaterialData_t data);
private:
    vertexMaterialData_t vertexData;
    pixelMaterialData_t pixelData;
};

#endif