#ifndef LITECHFRAMEWORK_ACTOR_H
#define LITECHFRAMEWORK_ACTOR_H
#include "Utility/Resource.h"
#include "Interfaces/IComponent.h"

#define COMPONENT_COUNT 0x10

class liActor : public liResource {
    friend class IComponent;
public:
    liActor(std::string name = "Actor");
    ~liActor();

    virtual void CalculateHash() override;

    void Render();
    void Update(double deltaTime);
protected:
    std::string name;
    std::bitset<COMPONENT_COUNT> componentBits;
    std::array<IComponent*, COMPONENT_COUNT> components;
};

#endif