#include "Resource.h"
#include "Graphics/GraphicsObject.h"

#define RESOURCEID_LENGTH 0x10
#define RESOURCEID_CHARS "abcdefghijklmnopqrstuvwxyz0123456789"

liResource::liResource() {
}

liResource::~liResource() {
}

liResourceManager::liResourceManager() {
}

liResourceManager::~liResourceManager() {
    ClearResources();
}

liResourceID liResourceManager::GenerateID() {
    liResourceID id;
    for(int i = 0; i < RESOURCEID_LENGTH; i++) {
        id.push_back(RESOURCEID_CHARS[rand() % 36]);
    }
    return id;
}

liResource* liResourceManager::AddResource(liResourceID id, liResource* resource) {
    for(liResourceMapIt it = resources.begin(); it != resources.end(); it++) {
        liResource* current = it->second;
        if(current->hash == resource->hash && typeid(*current) == typeid(*resource)) {
            liDelete(resource);
            return current;
        }
    }
    resource->id = id;
    resources.emplace(id, resource);
    return resource;
}

void liResourceManager::DeleteResource(liResourceID id) {
    liDelete(resources[id]);
    resources.erase(id);
}

void liResourceManager::ClearResources() {
    for(liResourceMapIt it = resources.begin(); it != resources.end(); it++) {
        liResourceID id = it->first;
        liResource* resource = it->second;
        liTechPrint("Clearing resource [type: %s, id: %s, hash: %llu, pointer: %p]", typeid(*resource).name(), id.c_str(), resource->hash, resource);
        liDelete(resources[id]);
    }
    resources.clear();
}