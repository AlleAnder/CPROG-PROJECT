#include "Game.h"


Game::Game(GameWindow* win, PhysicsHandler* physics, Background* background, PlayableEntity* player) : win(win), background(background), manager((physics)), player(player){
	manager.setPlayer(player);
}

void Game::addElement(Element* elm){
	manager.addElement(elm);
}

void Game::removeElement(Element* elm){
	manager.removeElement(elm);
}

void Game::addForeLayer(Layer* lay){
	manager.addForeLayer(lay);
}

void Game::addBackLayer(Layer* lay) {
	manager.addBackLayer(lay);
}

void Game::removeLayer(Layer* lay){
	manager.removeLayer(lay);
}

void Game::draw() {
	SDL_SetRenderDrawColor(win->getRenderer(), 0, 0, 0, 255);
	SDL_RenderClear(win->getRenderer());

	background->draw(win->getRenderer());
	manager.updateElements(win->getRenderer());
	
	SDL_RenderPresent(win->getRenderer());
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
		if (player->isDead())
			run = false;
		
		draw();
		
		int delay = startTime - SDL_GetTicks();
		if (delay > 0)
			SDL_Delay(delay);
	}
}