#include "pch.h"
#include "Runtime.h"
#include "imgui/imgui.h"
#include <Engine/Graphics/RenderPass.h>
#include <Engine/Framework/AssetManager.h>
#include <Engine/Input/Keyboard.h>

liVertexList testVertices = {
    liVertex(liVec3(-0.5f, -0.5f, 0.0f), liVec2(0.0f, 0.0f), liVec3(0, 0, 1)),
    liVertex(liVec3(0.5f, -0.5f, 0.0f), liVec2(1.0f, 0.0f), liVec3(0, 0, 1)),
    liVertex(liVec3(-0.5f, 0.5f, 0.0f), liVec2(0.0f, 1.0f), liVec3(0, 0, 1)),
    liVertex(liVec3(0.5f, 0.5f, 0.0f), liVec2(1.0f, 1.0f), liVec3(0, 0, 1))
};

liUIntBuffer testIndices = {
    0, 1, 2, 1, 2, 3
};

liRuntime::liRuntime(gameContext_t context)
    : liGame(context) {
    Setup();

    this->actor = new liActor();
    this->mesh = new liMesh(4, 6);
    mesh->UploadVertices(&testVertices);
    mesh->UploadIndices(&testIndices);
    Assets()->LoadAsset("TestMesh", mesh);
    this->material = new liMaterial(Assets()->FindAssetByName<liShaderProgram>("DefaultShaderProgram3D"));
    Assets()->LoadAsset("TestMaterial", material);
    actor->AddComponent(new liMeshRenderer(mesh, material));

    vertexMaterialData_t vertData = { };
    vertData.projection = liMat4::Perspective(70.0f, 1.6f, 0.1f, 1000.0f);
    vertData.model = liMat4::Translate(liVec3(0, 0, -1));
    material->SetVertexData(vertData);
    pixelMaterialData_t pixelData = { };
    pixelData.color = liColor(1, 0.5f, 1, 1);
    material->SetPixelData(pixelData);
}

liRuntime::~liRuntime() {
}

void liRuntime::Setup() {
    liGame::Setup();

    this->debugMenus = true;
}

void liRuntime::Render() {
    actor->Render();
}

void liRuntime::Update(float deltaTime) {
    liKeyboard* keyboard = Keyboard();

    if(keyboard->IsButtonPressed(LI_KEY_KP_7)) {
        this->debugMenus = !debugMenus;
    }
}

void liRuntime::ImGui() {
    if(debugMenus) {
        if(ImGui::Begin("Assets")) {
            ulong_t assetCount = Assets()->AssetCount();
            ImGui::Text("Loaded assets: %d", assetCount);
            ImGui::BeginChild("Scrolling");
            for(ulong_t i = 0; i < assetCount; i++) {
                liAsset* asset = Assets()->GetAssetByIndex(i);
                ImGui::Text("%s, %s: %s", asset->Name().c_str(), asset->GUID(), typeid(*asset).name());
            }
            ImGui::EndChild();
            ImGui::End();
        }
    }
}