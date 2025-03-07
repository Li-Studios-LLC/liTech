#ifndef LITECHFRAMEWORK_MOUSE_H
#define LITECHFRAMEWORK_MOUSE_H
#include "Typedefs.h"
#include "IInput.h"

#define LITECH_MOUSE_BUTTON_COUNT 0x10
#define LITECH_BUTTON_LEFT 1
#define LITECH_BUTTON_MIDDLE 2
#define LITECH_BUTTON_RIGHT 3
#define LITECH_BUTTON_X1 4
#define LITECH_BUTTON_X2 5

enum class mouseMode_t {
    CAPTURED,
    SHOWN,
    NORMAL
};

class liMouse : public IInput {
    friend SDL_AppResult SDL_AppEvent(void* appstate, SDL_Event* event);
public:
    liMouse();
    ~liMouse();

	void Update() override;
	bool IsConnected() const override;
    bool IsButtonDown(button_t btn) const override;
    bool IsButtonPressed(button_t btn) const override;
    bool IsButtonReleased(button_t btn) const override;
    bool IsButtonUp(button_t btn) const override;

    double X() const { return x; }
    double Y() const { return y; }
private:
    bool* buttons, *lastButtons;
    double x, y;
};

#endif