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

void liResourceManager::AddResource(liResourceID id, liResource* resource) {
    resource->id = id;
    resources.emplace(id, resource);
}

void liResourceManager::DeleteResource(liResourceID id) {
    liDelete(resources[id]);
    resources.erase(id);
}

void liResourceManager::ClearResources() {
    for(liResourceMap::iterator it = resources.begin(); it != resources.end(); it++) {
        liResourceID id = it->first;
        liResource* resource = it->second;
        liTechPrint("Clearing resource %s at %p", id.c_str(), resource);
        liDelete(resources[id]);
    }
    resources.clear();
}

liGraphicsObject* liResourceManager::GetGraphicsObject(ulong_t hash) {
    for(liResourceMap::iterator it = resources.begin(); it != resources.end(); it++) {
        liResource* resource = it->second;
        if(liGraphicsObject* obj = dynamic_cast<liGraphicsObject*>(resource)) {
            if(obj->Hash() == hash) {
                return obj;
            }
        }
    }
    return nullptr;
}