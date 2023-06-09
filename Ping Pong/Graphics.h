#pragma once
#include "sdl2_memory.h"
#include <vector>
#include <string>

class Graphics
{
public:
	Graphics(std::string window_title = "Default");
	void clear_screen();
	void draw(SDL_Rect* rect, SDL_Color color, bool fill = true) const;
	void present();

	int get_window_width() const { return width; }
	int get_window_height() const { return height; }

	SDL_Renderer* get_renderer() const { return renderer.get(); }
private:
	window_ptr window;
	renderer_ptr renderer;

	std::string title;
	int width;
	int height;
	int x;
	int y;
};