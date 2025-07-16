#ifndef GAME_H
#define GAME_H
#pragma once

class liKeyboard;
class liMouse;
class liRenderPass;
class liPostProcessing;
class liAssetManager;

struct gameContext_t {
    liKeyboard* keyboard;
    liMouse* mouse;
    liRenderPass* renderPass;
    liPostProcessing* post;
    liAssetManager* assets;
};

class liGame : public IRunnable {
public:
    liGame(gameContext_t context);
    virtual ~liGame() { }

    virtual void Setup() override;
    virtual void Render() override;
    virtual void Update(float deltaTime) override;
    virtual void ImGui() = 0;

    inline liKeyboard* Keyboard() { return keyboard; }
    inline liMouse* Mouse() { return mouse; }
    inline liRenderPass* Pass() { return renderPass; }
    inline liAssetManager* Assets() { return assets; }
private:
    liKeyboard* keyboard;
    liMouse* mouse;
    liRenderPass* renderPass;
    liPostProcessing* post;
    liAssetManager* assets;
};

#endif