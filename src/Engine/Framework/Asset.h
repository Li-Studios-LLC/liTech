#ifndef ASSET_H
#define ASSET_H
#pragma once

class liAssetManager;

class liAsset {
    friend class liAssetManager;
public:
    liAsset();
    virtual ~liAsset() { }

    void GenerateGUID();
    void SetGUID(guid_t guid);

    inline std::string Name() const { return name; }
    inline guid_t GUID() const { return guid; }
protected:
    std::string name;
    guid_t guid;
};

#endif