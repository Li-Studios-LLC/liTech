#ifndef LITECHFRAMEWORK_RESOURCE_H
#define LITECHFRAMEWORK_RESOURCE_H
#include "Typedefs.h"
#include "Heap.h"

#define LITECH_RESOURCEID_LENGTH 0x10

typedef std::string liResourceID;

class liResourceManager;

class liResource {
    friend class liResourceManager;
public:
    liResource(liResourceID id);
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

    liResourceID GenerateID();
    void AddResource(liResourceID id, liResource* resource);
    void DeleteResource(liResourceID id);
private:
    liResourceMap resources;
};

#endif