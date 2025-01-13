#include "Resource.h"

#define RESOURCEID_LENGTH 0x20
#define RESOURCEID_CHARS "abcdefghijklmnopqrstuvwxyz0123456789"

liResource::liResource() {
}

liResource::~liResource() {
}

liResourceManager::liResourceManager() {
}

liResourceManager::~liResourceManager() {
}

liResourceID liResourceManager::GenerateID() {
    liResourceID id;
    srand(LITECH_TIMESTAMP());
    for(int i = 0; i < RESOURCEID_LENGTH; i++) {
        id.push_back(RESOURCEID_CHARS[rand() % 37]);
    }
    return id;
}

void liResourceManager::AddResource(liResourceID id, liResource* resource) {
    resource->id = id;
    resources.emplace(id, resource);
}

void liResourceManager::DeleteResource(liResourceID id) {
    resources.erase(id);
}

void liResourceManager::ClearResources() {
    resources.clear();
}