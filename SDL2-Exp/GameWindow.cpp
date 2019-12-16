#include "GameWindow.h"

GameWindow::GameWindow() {
	SDL_Init(SDL_INIT_EVERYTHING);
	SetWindow("Window", 600, 400);
}

GameWindow::GameWindow(const char* name, int sizeX, int sizeY) {
	SDL_Init(SDL_INIT_EVERYTHING);
	SetWindow(name, sizeX, sizeY);
}

GameWindow::~GameWindow() {
	SDL_DestroyRenderer(ren);
	SDL_DestroyWindow(win);

	SDL_Quit;
}

bool GameWindow::SetWindow(const char* name, int sizeX, int sizeY){
	SDL_DestroyWindow(win);
	SDL_DestroyRenderer(ren);
	

	win = SDL_CreateWindow(name, SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, sizeX, sizeY, SDL_WINDOW_SHOWN);
	if (win == nullptr) {
		std::cerr << "Could not create window.\n";
		return false;
	}

	ren = SDL_CreateRenderer(win, -1, 0);
	if (ren == nullptr) {
		std::cerr << "Could not create renderer.\n";
		return false;
	}
	return true;
}







