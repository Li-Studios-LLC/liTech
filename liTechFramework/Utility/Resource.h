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
    
    virtual void CalculateHash() = 0;

    LITECH_INLINE liResourceID ID() const { return id; }
    LITECH_INLINE ulong_t Hash() const { return hash; }
protected:
    ulong_t hash;
    liResourceID id;
};

typedef std::unordered_map<liResourceID, liResource*> liResourceMap;
typedef std::unordered_map<liResourceID, liResource*>::iterator liResourceMapIt;

class liGraphicsObject;

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

    template <typename T>
    LITECH_INLINE T* GetResource(liResourceID id) {
        return (T*)resources[id];
    }
private:
    liResourceMap resources;
};

#define LITECH_ADD_RESOURCE(resource) liResourceManager::Instance()->AddResource(liResourceManager::GenerateID(), (liResource*)resource)
#define LITECH_DELETE_RESOURCE(id) liResourceManager::Instance()->DeleteResource(id)
#define LITECH_GET_RESOURCE(type, id) liResourceManager::Instance()->GetResource<type>(id)

#endif