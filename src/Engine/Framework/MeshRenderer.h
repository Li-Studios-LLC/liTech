#ifndef MESHRENDERER_H
#define MESHRENDERER_H
#pragma once
#include "ActorComponent.h"
#include "Engine/Graphics/Mesh.h"
#include "Engine/Framework/Material.h"

class liMeshRenderer : public liActorComponent {
public:
    liMeshRenderer(liMesh* mesh, liMaterial* material, cullMode_t cull = cullMode_t::BACK_FACE, topology_t topology = topology_t::TRIANGLES, ulong_t start = 0, ulong_t count = -1);
    ~liMeshRenderer();

    virtual void Render() override;
    virtual void Update(float deltaTime) override;
    
    inline void SetMesh(liMesh* mesh) { this->mesh = mesh; }
    inline liMesh* Mesh() { return mesh; }
    inline void SetMaterial(liMaterial* material) { this->material = material; }
    inline liMaterial* Material() { return material; }
private:
    liMesh* mesh;
    liMaterial* material;
    topology_t topology;
    cullMode_t cull;
    ulong_t start, count;
};

#endif