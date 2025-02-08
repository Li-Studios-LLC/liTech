#ifndef LITECHFRAMEWORK_SCENE_H
#define LITECHFRAMEWORK_SCENE_H
#include "Actor.h"

class liScene : public liResource {
public:
private:
    std::string name;
    std::list<liActor*> actors;
};

#endif