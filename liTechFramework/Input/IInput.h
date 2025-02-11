#ifndef LITECHFRAMEWORK_IINPUT_H
#define LITECHFRAMEWORK_IINPUT_H

typedef unsigned short button_t;

struct IInput {
    virtual ~IInput() { }

    virtual void Update() = 0;
    virtual bool IsConnected() const = 0;
    virtual bool IsButtonDown(button_t btn) const = 0;
    virtual bool IsButtonPressed(button_t btn) const = 0;
    virtual bool IsButtonReleased(button_t btn) const = 0;
    virtual bool IsButtonUp(button_t btn) const = 0;
};

#endif