#include "pch.h"
#include "Actor.h"

liActor::liActor(std::string name) {
    this->name = name;

    for(ulong_t i = 0; i < actorComponentType_t::COUNT; i++) {
        components[i] = nullptr;
    }
}

liActor::~liActor() {
    for(ulong_t i = 0; i < actorComponentType_t::COUNT; i++) {
        if(components[i] != nullptr) {
            delete components[i];
        }
    }
}

void liActor::Render() {
    for(ulong_t i = 0; i < actorComponentType_t::COUNT; i++) {
        if(components[i] != nullptr) {
            components[i]->Render();
        }
    }
}

void liActor::Update(float deltaTime) {
    for(ulong_t i = 0; i < actorComponentType_t::COUNT; i++) {
        if(components[i] != nullptr) {
            components[i]->Update(deltaTime);
        }
    }
}

void liActor::AddComponent(liActorComponent* component) {
    liActorComponent* dest = components[component->type];
    if(dest == nullptr) {
        delete dest;
    }
    component->owner = this;
    components[component->type] = component;
}

void liActor::RemoveComponent(actorComponentType_t type) {
    assert(type < actorComponentType_t::COUNT);
    liActorComponent* dest = components[type];
    if(dest != nullptr) {
        delete dest;
    }
    components[type] = nullptr;
}