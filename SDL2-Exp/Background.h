#pragma once
#include "Element.h"


struct Background : public Element {
	Background(const int w, const int h) : Element(0, 0, w, h, 0) {};
};