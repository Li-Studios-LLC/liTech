#ifndef LITECHFRAMEWORK_ACTOR_H
#define LITECHFRAMEWORK_ACTOR_H
#include "Utility/Resource.h"

class liActor : public liResource {
public:
    liActor(std::string name = "Actor");
    ~liActor();

    virtual void CalculateHash() override;

    void Render();
    void Update(double deltaTime);
protected:
    std::string name;
};

#endif