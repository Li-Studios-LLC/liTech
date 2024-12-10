#include "Game.h"

liGame::liGame() {
	this->running = true;
}

void liGame::Quit() {
	this->running = false;
}