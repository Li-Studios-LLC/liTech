#ifndef DATAFILEEXPLORER_H
#define DATAFILEEXPLORER_H
#pragma once
#include <Engine/Framework/Game.h>
#include <engine/Tools/DataFile.h>

namespace ImGui {
    class FileBrowser;
}

class liDataFileExplorer : public liGame {
public:
    liDataFileExplorer(gameContext_t context);
    liDataFileExplorer(const liDataFileExplorer&) = delete;
    ~liDataFileExplorer();

    virtual void Setup() override;
    virtual void Render() override;
    virtual void Update(float deltaTime) override;
    virtual void ImGui() override;
private:
    liDataFile* dataFile;
    ImGui::FileBrowser* browser;
};

#endif