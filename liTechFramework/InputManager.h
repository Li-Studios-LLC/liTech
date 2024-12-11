#ifndef LITECHFRAMEWORK_INPUTMANAGER_H
#define LITECHFRAMEWORK_INPUTMANAGER_H
#include "Typedefs.h"
#include "IManager.h"
#include "Keyboard.h"
#include "Mouse.h"

class liInputManager : public IManager {
public:
	static liInputManager* Instance() {
		static liInputManager* instance = nullptr;
		if (!instance) {
			instance = liNew<liInputManager>();
		}
		return instance;
	}

	~liInputManager();

	void Initialize() override;
	void Shutdown() override;
	void Update() override;

	LITECH_INLINE liMouse* GetMouse() { return mouse; }
	LITECH_INLINE liKeyboard* GetKeyboard() { return keyboard; }
private:
	liMouse* mouse;
	liKeyboard* keyboard;
};

#endif