#include "InputManager.h"

liInputManager::~liInputManager() {
	Shutdown();
}

void liInputManager::Initialize() {
	this->mouse = liNew<liMouse>();
	this->keyboard = liNew<liKeyboard>();
}

void liInputManager::Shutdown() {
	liDelete(mouse);
	liDelete(keyboard);
}

void liInputManager::Update() {
	keyboard->Update();
	mouse->Update();
}