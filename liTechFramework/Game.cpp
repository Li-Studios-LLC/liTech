#include "Game.h"
#include "FileSystem.h"
#include "InputManager.h"

liGame::liGame() {
	this->running = true;
	this->filesystem = liFileSystem::Instance();
	this->inputManager = liInputManager::Instance();
}

void liGame::Quit() {
	this->running = false;
}