#include "pch.h"
#include "MeshRenderer.h"

liMeshRenderer::liMeshRenderer(liMesh *mesh, liMaterial *material, cullMode_t cull, topology_t topology, ulong_t start, ulong_t count)
    : liActorComponent(actorComponentType_t::MESHRENDERER) {
    this->mesh = mesh;
    this->material = material;
    this->topology = topology;
    this->cull = cull;
    this->start = start;
    this->count = count;
}

liMeshRenderer::~liMeshRenderer() {
}

void liMeshRenderer::Render() {
    if(mesh != nullptr && material != nullptr) { 
        material->Bind();
        mesh->Draw(cull, topology, start, count);
    }
}

void liMeshRenderer::Update(float deltaTime) {
}