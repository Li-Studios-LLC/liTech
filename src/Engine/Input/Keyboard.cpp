#include "pch.h"
#include "Keyboard.h"

liKeyboard::liKeyboard() {
    this->keys = new bool[LI_KEY_COUNT];
    this->lastKeys = new bool [LI_KEY_COUNT];
    memset(keys, 0, LI_KEY_COUNT);
    memset(lastKeys, 0, LI_KEY_COUNT);
}

liKeyboard::~liKeyboard() {
    delete[] keys;
    delete[] lastKeys;
}

void liKeyboard::Update() {
    memcpy(lastKeys, keys, LI_KEY_COUNT);
}

bool liKeyboard::IsConnected() const {
    return SDL_HasKeyboard();
}

bool liKeyboard::IsButtonDown(button_t btn) const {
    return keys[btn];
}

bool liKeyboard::IsButtonPressed(button_t btn) const {
    return keys[btn] && !lastKeys[btn];
}

bool liKeyboard::IsButtonReleased(button_t btn) const {
    return !keys[btn] && lastKeys[btn];
}

bool liKeyboard::IsButtonUp(button_t btn) const {
    return !keys[btn];
}

ushort_t liKeyboard::KeyMods() const {
    return SDL_GetModState();
}