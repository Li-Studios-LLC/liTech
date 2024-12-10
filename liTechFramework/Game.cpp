#include "Game.h"
#include "FileSystem.h"

liGame::liGame() {
	this->running = true;
	this->filesystem = liFileSystem::Instance();
}

void liGame::Quit() {
	this->running = false;
}