#include "Resource.h"

liResource::liResource(liResourceID id) {
    this->id = id;
}

liResource::~liResource() {
}

liResourceManager::liResourceManager() {
}

liResourceManager::~liResourceManager() {
}

liResourceID liResourceManager::GenerateID() {
    liResourceID id;
    return id;
}

void liResourceManager::AddResource(liResourceID id, liResource *resource) {
    resources.emplace(id, resource);
}

void liResourceManager::DeleteResource(liResourceID id) {
}