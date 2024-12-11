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
public:
	liMouse();
	liMouse(const liMouse&) = delete;
	~liMouse();

	void Update() override;
	bool IsConnected() const override;
	bool IsButtonDown(button_t btn) const override;
	bool IsButtonPressed(button_t btn) const override;
	bool IsButtonReleased(button_t btn) const override;
	bool IsButtonUp(button_t btn) const override;

	double X() const { return x; }
	double Y() const { return y; }

	// DO NOT USE!
	void _SetButtonDown(button_t btn);
	void _SetButtonUp(button_t btn);
	void _SetPosition(double x, double y);
private:
	bool* buttons, *lastButtons;
	double x, y;
};

#endif