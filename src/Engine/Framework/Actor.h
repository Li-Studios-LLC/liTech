#ifndef ACTOR_H
#define ACTOR_H
#pragma once
#include "Engine/Math/Transform.h"
#include "ActorComponent.h"

class liActor {
    friend class liActorComponent;
public:
    liActor(std::string name = "Actor");
    liActor(const liActor&) = delete;
    ~liActor();

    void Render();
    void Update(float deltaTime);
    void AddComponent(liActorComponent* component);
    void RemoveComponent(actorComponentType_t type);

    std::string name;
    liTransform transform;
    int layer;
private:
    std::array<liActorComponent*, actorComponentType_t::COUNT> components;
};

#endif