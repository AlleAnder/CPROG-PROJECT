#include "Game.h"
#include "GameWindow.h"


Game::Game(GameWindow* win) {
	this->win = win;

}

Game::~Game() {
	elements.clear();
	win->~GameWindow();
}

void Game::setPlayer(PlayableEntity* player){
	this->player = player;
}

bool Game::addElement(Element* elm){
	elements.push_back(elm);
	return false;
}

bool Game::removeElement(Element* comp){
	
	for (int i = 0; i < elements.size() / sizeof(Element); i++) {
		if (elements.at(i) == comp) {
			elements.erase(elements.begin() + i);
		}
	}
	return false;
}

void Game::update() {
	
}

void Game::draw() {
	SDL_SetRenderDrawColor(win->ren, 0, 0, 0, 255);
	SDL_RenderClear(win->ren);

	for (Element* e : elements) {
		e->draw(win->ren);
	}
	player->draw(win->ren);

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
			case SDL_KEYDOWN:
				player->keyDown(event.key.keysym.sym);
				std::cout << "he";
				break;
			case SDL_QUIT: 
				run = false; 
				break;
			}
		}
		
		update();
		draw();
		



		int delay = startTime - SDL_GetTicks();
		if (delay > 0)
			SDL_Delay(delay);
	}
}