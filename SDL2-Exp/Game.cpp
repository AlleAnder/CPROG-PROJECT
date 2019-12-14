#include "Game.h"
#include "GameWindow.h"


Game::Game(GameWindow* win) {
	this->win = win;
	EntityManager manager;
}

Game::~Game() {
	manager.~EntityManager();
	win->~GameWindow();
}

void Game::setPlayer(PlayableEntity* player){
	manager.setPlayer(player);
}

void Game::addElement(Element* elm){
	manager.addElement(elm);
}

void Game::removeElement(Element* elm){
	manager.removeElement(elm);
}

void Game::draw() {
	SDL_SetRenderDrawColor(win->ren, 0, 0, 0, 255);
	SDL_RenderClear(win->ren);

	manager.updateElements(win->ren);
	
	SDL_RenderPresent(win->ren);
}

void Game::run(int maxFPS) {
	bool run = true;
	Uint32 fps = 1000 / maxFPS;
	

	while (run) {
		Uint32 startTime = SDL_GetTicks() + fps;
		SDL_Event event;

		while (SDL_PollEvent(&event)) {

			switch (event.type) {
			case SDL_QUIT: 
				run = false; 
				break;
			default:
				manager.triggerEvent(event);
			}
		}
		
		draw();
		
		int delay = startTime - SDL_GetTicks();
		if (delay > 0)
			SDL_Delay(delay);
	}
}