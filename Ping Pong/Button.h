#pragma once
#include "SDL_mouse.h"
#include "Graphics.h"
#include "Text.h"
#include "sdl2_memory.h"

class Button
{
public:
	Button(const Graphics& graphics, const std::string& font_file_path, const std::string& button_text = "Button", int x_ = 0, int y_ = 0, int text_size = 10, int vertical_padding = 10, int horizontal_padding = 10, SDL_Color button_color_ = SDL_Color{255,255,255,255},
		SDL_Color text_color_ = SDL_Color{ 255,255,255,255 }, bool horizontal_centered = true);

	bool clicked() const;
	void draw(const Graphics& graphics);
private:
	int x;
	int y;
	int width;
	int height;
	SDL_Color button_color;
	SDL_Color text_color;
	Text text;
	SDL_Rect button;
};