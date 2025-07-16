#ifndef MP_H
#define MP_H
#pragma once
#include <Engine/Framework/Game.h>
#include <Engine/Framework/Material.h>
#include <Engine/Framework/Scene.h>
#include <Engine/Framework/MeshRenderer.h>

class MPGame : public liGame {
public:
    MPGame(gameContext_t context);
    MPGame(const MPGame&) = delete;
    ~MPGame();

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