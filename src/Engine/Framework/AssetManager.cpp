#include "pch.h"
#include "AssetManager.h"

liAssetManager::liAssetManager() {
}

liAssetManager::~liAssetManager() {
    UnloadAssets();
}

liAsset* liAssetManager::LoadAsset(std::string name, liAsset* asset) {
    auto found = assets.find(name);
    if(found == assets.end()) {
        asset->name = name;
        assets.emplace(name, asset);
        std::cerr << "Loaded asset " << name << " " << std::string(asset->guid.id) << std::endl;
        return asset;
    } else {
        std::cerr << "Asset " << name << " " << std::string(found->second->guid.id) << " already loaded!" << std::endl;
        return nullptr;
    }
}

void liAssetManager::UnloadAsset(std::string name) {
    auto found = assets.find(name);
    if(found != assets.end()) {
        std::cerr << "Unloaded asset " << name << " " << std::string(found->second->guid.id) << std::endl;
        delete found->second;
        assets.erase(found);
    } else {
        std::cerr << "Asset " << name << " wasn't found!" << std::endl;
    }
}

void liAssetManager::UnloadAssets() {
    for(auto& [name, asset] : assets) {
        std::cerr << "Unloaded asset " << name << " " << asset->guid.id << std::endl;
        delete asset;
    }
    assets.clear();
}

liAsset* liAssetManager::GetAssetByIndex(ulong_t index) {
    std::map<std::string, liAsset*>::iterator it = assets.begin();
    std::advance(it, index);
    return it->second;
}