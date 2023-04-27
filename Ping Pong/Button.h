#pragma once

#include "SDL_mouse.h"
#include "Graphics.h"

class Button
{
public:
	Button(const Graphics& graphics, int x_ = 0, int y_ = 0, int w = 10, int h = 10, SDL_Color button_color_ = SDL_Color{ 255,255,255,255 });
	void draw(const Graphics& graphics);
	bool clicked() const;
private:
	int x;
	int y;
	int width;
	int height;
	SDL_Color button_color;
	SDL_Rect button;
};