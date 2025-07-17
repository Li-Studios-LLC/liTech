#ifndef RUNTIME_H
#define RUNTIME_H
#pragma once
#include <Engine/Framework/Game.h>
#include <Engine/Framework/Material.h>
#include <Engine/Framework/Scene.h>
#include <Engine/Framework/MeshRenderer.h>

class liRuntime : public liGame {
public:
    liRuntime(gameContext_t context);
    liRuntime(const liRuntime&) = delete;
    ~liRuntime();

    virtual void Setup() override;
    virtual void Render() override;
    virtual void Update(float deltaTime) override;
    virtual void ImGui() override;
private:
    bool debugMenus;
    liMesh* mesh;
    liMaterial* material;
    liActor* actor;
};

#endif