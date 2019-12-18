#pragma once
#include <SDL.h>
#include "Element.h"
#include <vector>

struct Background: public Element{
	Background(const int w, const int h) : Element(0, 0, w, h, 0) {};
	~Background() {};

private:

	std::vector<Element*> levelElements;

};

