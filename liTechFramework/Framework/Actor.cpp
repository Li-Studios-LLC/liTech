#include "Actor.h"

liActor::liActor(std::string name) {
    this->name = name;
    componentBits.reset();
    components.fill(nullptr);
}

liActor::~liActor() {
}

void liActor::CalculateHash() {
}

void liActor::Render() {
}

void liActor::Update(double deltaTime) {
}