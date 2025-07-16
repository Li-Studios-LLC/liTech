#include "pch.h"
#include "Scene.h"

liScene::liScene(std::string name) {
    this->name = name;
}

liScene::~liScene() {
    ClearActors();
}

void liScene::Render() {
    for(ulong_t i = 0; i < actors.size(); i++) {
        actors[i]->Render();
    }
}

void liScene::Update(float deltaTime) {
    for(ulong_t i = 0; i < actors.size(); i++) {
        actors[i]->Update(deltaTime);
    }
}

void liScene::AddActor(liActor* actor) {
    actors.push_back(actor);
}

void liScene::RemoveActor(ulong_t index) {
    liActor* actor = actors[index];
    actors.erase(actors.begin() + index);
    delete actor;
}

void liScene::ClearActors() {
    for(ulong_t i = 0; i < actors.size(); i++) {
        delete actors[i];
    }
    actors.clear();
}