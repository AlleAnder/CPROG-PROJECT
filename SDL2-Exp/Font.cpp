#include "Font.h"

Font::Font(const char* path, int size){
	font = TTF_OpenFont(path, size);
}

Font::~Font(){ 
	TTF_CloseFont(font);
	TTF_Quit;
}

void Font::setFont(const char* path, int size) {
	TTF_CloseFont(font);
	font = TTF_OpenFont(path, size);
}

TTF_Font* Font::getFont() {
	return font;
}