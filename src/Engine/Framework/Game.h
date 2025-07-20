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
    float aspectRatio;
};

class liGame : public IRunnable {
public:
    liGame(gameContext_t context);
    virtual ~liGame() { }

    virtual void Setup() override;
    virtual void Render() override;
    virtual void Update(float deltaTime) override;
    virtual void ImGui() = 0;

    inline liKeyboard* Keyboard() { return context.keyboard; }
    inline liMouse* Mouse() { return context.mouse; }
    inline liRenderPass* Pass() { return context.renderPass; }
    inline liAssetManager* Assets() { return context.assets; }
    inline float AspectRatio() const { return context.aspectRatio; }
private:
    gameContext_t context;
};

#endif