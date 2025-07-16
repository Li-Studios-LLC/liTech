#include "pch.h"
#include "Mouse.h"

liMouse::liMouse() {
    this->buttons = new bool[LI_MOUSE_BUTTON_COUNT];
    this->lastButtons = new bool [LI_MOUSE_BUTTON_COUNT];
    this->x = 0;
    this->y = 0;
    memset(buttons, 0, LI_MOUSE_BUTTON_COUNT);
    memset(lastButtons, 0, LI_MOUSE_BUTTON_COUNT);
}

liMouse::~liMouse() {
    delete[] buttons;
    delete[] lastButtons;
}

void liMouse::Update() {
    memcpy(lastButtons, buttons, LI_MOUSE_BUTTON_COUNT);
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