#ifndef EDITOR_H
#define EDITOR_H
#pragma once
#include <Engine/Framework/Game.h>
#include "Components.h"

namespace ImGui {
    class FileBrowser;
}

class liEditor : public liGame {
public:
    liEditor(gameContext_t context);
    liEditor(const liEditor&) = delete;
    ~liEditor();

    virtual void Setup() override;
    virtual void Render() override;
    virtual void Update(float deltaTime) override;
    virtual void ImGui() override;
private:
    liDataFileEditor* dataEditor;
};

#endif