#include "pch.h"
#include "Game.h"

liGame::liGame(gameContext_t context) {
    this->keyboard = context.keyboard;
    this->mouse = context.mouse;
    this->assets = context.assets;
    this->renderPass = context.renderPass;
    this->post = context.post;
}

void liGame::Setup() {
}

void liGame::Render() {
}

void liGame::Update(float deltaTime) {
}