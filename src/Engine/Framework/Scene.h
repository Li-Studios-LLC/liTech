#ifndef SCENE_H
#define SCENE_H
#pragma once
#include "Asset.h"
#include "Actor.h"

typedef std::vector<liActor*> liActorList;

class liScene : public liAsset {
public:
    liScene(std::string name = "Scene");
    liScene(const liScene&) = delete;
    ~liScene();

    void Render();
    void Update(float deltaTime);
    void AddActor(liActor* actor);
    void RemoveActor(ulong_t index);
    void ClearActors();

    inline liActor* Get(ulong_t index) { return actors[index]; }
    inline const liActor* Get(ulong_t index) const { return actors[index]; }
    inline ulong_t ActorCount() const { return actors.size(); }
private:
    liActorList actors;
};

#endif