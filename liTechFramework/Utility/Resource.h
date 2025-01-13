#ifndef LITECHFRAMEWORK_RESOURCE_H
#define LITECHFRAMEWORK_RESOURCE_H
#include "Typedefs.h"
#include "Heap.h"

typedef std::string liResourceID;

class liResourceManager;

class liResource {
    friend class liResourceManager;
public:
    liResource();
    virtual ~liResource();
    
    LITECH_INLINE liResourceID ID() const { return id; }
private:
    liResourceID id;
};

typedef std::unordered_map<liResourceID, liResource*> liResourceMap;

class liResourceManager {
    friend class liResource;
public:
    static liResourceManager* Instance() {
        static liResourceManager* instance;
        if(!instance) {
            instance = liNew<liResourceManager>();
        }
        return instance;
    }

    liResourceManager();
    ~liResourceManager();

    static liResourceID GenerateID();
    void AddResource(liResourceID id, liResource* resource);
    void DeleteResource(liResourceID id);
    void ClearResources();
private:
    liResourceMap resources;
};

#define LITECH_ADD_RESOURCE(resource) liResourceManager::Instance->AddResource(GenerateID(), resource)
#define LITECH_DELETE_RESOURCE(id) liResourceManager::Instance->DeleteResource(id)

#endif