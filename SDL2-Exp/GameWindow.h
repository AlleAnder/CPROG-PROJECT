#pragma once
#include <SDL.h>
#include <SDL_ttf.h>
#include <iostream>

struct GameWindow
{
	GameWindow();
	GameWindow(const char* name, int sizeX, int sizeY);
	~GameWindow();

	bool SetWindow(const char* name, int sizeX, int sizeY);
	
	SDL_Window* getWindow() { return win; };
	SDL_Renderer* getRenderer() { return ren; };
	
private:

	SDL_Window* win = nullptr;
	SDL_Renderer* ren = nullptr;


};



