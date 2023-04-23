#pragma once
#include "SDL_ttf.h"
#include "sdl2_memory.h"
#include "Graphics.h"
#include <string>

class Text
{
public:
	Text(const Graphics& graphics, std::string font_file_path = "", int point_size_ = 1, std::string text_ = "", SDL_Color color_ = SDL_Color{ 255,255,255,255 }, int x_ = 0, int y_ = 0);
	~Text() { TTF_Quit(); }

	void draw(const Graphics& graphics);
	void update_text(std::string text_, const Graphics& graphics);
private:
	int point_size;
	font_ptr font;
	std::string text;
	SDL_Color color;
	surface_ptr surface;
	texture_ptr texture;
	int x;
	int y;
};