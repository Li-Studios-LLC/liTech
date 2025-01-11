#include "Keyboard.h"
#include "Utility/Heap.h"

liKeyboard::liKeyboard() {
    this->keys = liNewArray<bool>(LITECH_KEY_COUNT);
    this->lastKeys = liNewArray<bool>(LITECH_KEY_COUNT);
    memset(keys, 0, LITECH_KEY_COUNT);
    memset(lastKeys, 0, LITECH_KEY_COUNT);
}

liKeyboard::~liKeyboard() {
    liDeleteArray(keys);
    liDeleteArray(lastKeys);
}

void liKeyboard::Update() {
    memcpy(lastKeys, keys, LITECH_KEY_COUNT);
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