#include "Mouse.h"
#include "Utility/Heap.h"

liMouse::liMouse() {
    this->buttons = liNewArray<bool>(LITECH_MOUSE_BUTTON_COUNT);
    this->lastButtons = liNewArray<bool>(LITECH_MOUSE_BUTTON_COUNT);
    this->x = 0;
    this->y = 0;
    memset(buttons, 0, LITECH_MOUSE_BUTTON_COUNT);
    memset(lastButtons, 0, LITECH_MOUSE_BUTTON_COUNT);
}

liMouse::~liMouse() {
    liDeleteArray(buttons);
    liDeleteArray(lastButtons);
}

void liMouse::Update() {
    memcpy(lastButtons, buttons, LITECH_MOUSE_BUTTON_COUNT);
}

bool liMouse::IsConnected() const {
    return SDL_HasMouse();
}

bool liMouse::IsButtonDown(button_t btn) const {
    return buttons[btn];
}

bool liMouse::IsButtonPressed(button_t btn) const {
    return buttons[btn] && !lastButtons[btn];
}

bool liMouse::IsButtonReleased(button_t btn) const {
    return !buttons[btn] && lastButtons[btn];
}

bool liMouse::IsButtonUp(button_t btn) const {
    return !buttons[btn];
}