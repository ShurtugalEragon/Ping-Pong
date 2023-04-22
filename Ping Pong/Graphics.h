#pragma once
#include "sdl2_memory.h"
#include <vector>
#include <string>

class Graphics
{
public:
	Graphics(std::string window_title = "Default");
	void clear_screen();
	void draw(const std::vector<SDL_Point>& points) const;
	void draw(SDL_Rect* rect, int r,int g,int b,int a) const;
	void present();

	int get_window_width() const { return width; }
	int get_window_height() const { return height; }
private:
	window_ptr window;
	renderer_ptr renderer;

	std::string title;
	int width;
	int height;
	int x;
	int y;
};