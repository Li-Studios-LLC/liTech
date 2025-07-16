#ifndef SPRITERENDERER_H
#define SPRITERENDERER_H
#pragma once
#include "ActorComponent.h"

class liSpriteRenderer : public liActorComponent {
public:
    virtual void Render() override;
    virtual void Update(float deltaTime) override;
private:
};

#endif