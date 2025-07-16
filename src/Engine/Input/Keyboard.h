#ifndef LITECHFRAMEWORK_KEYBOARD_H
#define LITECHFRAMEWORK_KEYBOARD_H
#pragma once
#include "IInput.h"

#define LI_KEY_COUNT 0x200

// Key mods
#define LI_KEYMOD_NONE 0b0
#define LI_KEYMOD_LSHIFT LILIB_BIT(0)
#define LI_KEYMOD_RSHIFT LILIB_BIT(1)
#define LI_KEYMOD_LCTRL LILIB_BIT(2)
#define LI_KEYMOD_RCTRL LILIB_BIT(3)
#define LI_KEYMOD_LALT LILIB_BIT(4)
#define LI_KEYMOD_RALT LILIB_BIT(5)
#define LI_KEYMOD_LGUI LILIB_BIT(6)
#define LI_KEYMOD_RGUI LILIB_BIT(7)
#define LI_KEYMOD_NUM LILIB_BIT(8)
#define LI_KEYMOD_CAPS LILIB_BIT(9)
#define LI_KEYMOD_MODE LILIB_BIT(10)
#define LI_KEYMOD_SCROLL LILIB_BIT(11)
#define LI_KEYMOD_CTRL (LI_KEYMOD_LCTRL | LI_KEYMOD_RCTRL)
#define LI_KEYMOD_SHIFT (LI_KEYMOD_LSHIFT | LI_KEYMOD_RSHIFT)
#define LI_KEYMOD_ALT (LI_KEYMOD_LALT | LI_KEYMOD_RALT)
#define LI_KEYMOD_GUI (LI_KEYMOD_LGUI | LI_KEYMOD_RGUI)

// Scan codes
#define LI_KEY_A 4
#define LI_KEY_B 5
#define LI_KEY_C 6
#define LI_KEY_D 7
#define LI_KEY_E 8
#define LI_KEY_F 9
#define LI_KEY_G 10
#define LI_KEY_H 11
#define LI_KEY_I 12
#define LI_KEY_J 13
#define LI_KEY_K 14
#define LI_KEY_L 15
#define LI_KEY_M 16
#define LI_KEY_N 17
#define LI_KEY_O 18
#define LI_KEY_P 19
#define LI_KEY_Q 20
#define LI_KEY_R 21
#define LI_KEY_S 22
#define LI_KEY_T 23
#define LI_KEY_U 24
#define LI_KEY_V 25
#define LI_KEY_W 26
#define LI_KEY_X 27
#define LI_KEY_Y 28
#define LI_KEY_Z 29
#define LI_KEY_1 30
#define LI_KEY_2 31
#define LI_KEY_3 32
#define LI_KEY_4 33
#define LI_KEY_5 34
#define LI_KEY_6 35
#define LI_KEY_7 36
#define LI_KEY_8 37
#define LI_KEY_9 38
#define LI_KEY_0 39
#define LI_KEY_RETURN 40
#define LI_KEY_ESCAPE 41
#define LI_KEY_BACKSPACE 42
#define LI_KEY_TAB 43
#define LI_KEY_SPACE 44
#define LI_KEY_MINUS 45
#define LI_KEY_EQUALS 46
#define LI_KEY_RIGHTBRACKET 48
#define LI_KEY_LEFTBRACKET 47
#define LI_KEY_BACKSLASH 49
#define LI_KEY_NONUSHASH 50
#define LI_KEY_SEMICOLON 51
#define LI_KEY_APOSTROPHE 52
#define LI_KEY_GRAVE 53
#define LI_KEY_COMMA 54
#define LI_KEY_PERIOD 55
#define LI_KEY_SLASH 56,
#define LI_KEY_CAPSLOCK 57
#define LI_KEY_F1 58
#define LI_KEY_F2 59
#define LI_KEY_F3 60
#define LI_KEY_F4 61
#define LI_KEY_F5 62
#define LI_KEY_F6 63
#define LI_KEY_F7 64
#define LI_KEY_F8 65
#define LI_KEY_F9 66
#define LI_KEY_F10 67
#define LI_KEY_F11 68
#define LI_KEY_F12 69
#define LI_KEY_PRINTSCREEN 70
#define LI_KEY_SCROLLLOCK 71
#define LI_KEY_PAUSE 72
#define LI_KEY_INSERT 73
#define LI_KEY_HOME 74
#define LI_KEY_PAGEUP 75
#define LI_KEY_DELETE 76
#define LI_KEY_END 77
#define LI_KEY_PAGEDOWN 78
#define LI_KEY_RIGHT 79
#define LI_KEY_LEFT 80
#define LI_KEY_DOWN 81
#define LI_KEY_UP 82
#define LI_KEY_NUMLOCKCLEAR 83
#define LI_KEY_KP_DIVIDE 84
#define LI_KEY_KP_MULTIPLY 85
#define LI_KEY_KP_MINUS 86,
#define LI_KEY_KP_PLUS 87
#define LI_KEY_KP_ENTER 88
#define LI_KEY_KP_1 89
#define LI_KEY_KP_2 90
#define LI_KEY_KP_3 91
#define LI_KEY_KP_4 92
#define LI_KEY_KP_5 93
#define LI_KEY_KP_6 94
#define LI_KEY_KP_7 95
#define LI_KEY_KP_8 96
#define LI_KEY_KP_9 97
#define LI_KEY_KP_0 98
#define LI_KEY_KP_PERIOD 99
#define LI_KEY_POWER 102
#define LI_KEY_KP_EQUALS 103
#define LI_KEY_KP_COMMA 133
#define LI_KEY_LCTRL 224
#define LI_KEY_LSHIFT 225
#define LI_KEY_LALT 226
#define LI_KEY_LGUI 227
#define LI_KEY_RCTRL 228
#define LI_KEY_RSHIFT 229
#define LI_KEY_RALT 230
#define LI_KEY_RGUI 231

class liKeyboard : public IInput {
	friend SDL_AppResult SDL_AppEvent(void* appstate, SDL_Event* event);
public:
	liKeyboard();
	liKeyboard(const liKeyboard&) = delete;
	~liKeyboard();

	void Update() override;
	bool IsConnected() const override;
	bool IsButtonDown(button_t btn) const override;
	bool IsButtonPressed(button_t btn) const override;
	bool IsButtonReleased(button_t btn) const override;
    bool IsButtonUp(button_t btn) const override;
	
	ushort_t KeyMods() const;
private:
	bool* keys, *lastKeys;
};

#endif