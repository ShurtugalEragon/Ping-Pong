#pragma once

#include "SDL_mouse.h"
#include "Graphics.h"
#include "SDL_mixer.h"
#include "sdl2_memory.h"

class Volume_Slide
{
public:
	Volume_Slide(int x = 0, int y = 0, int w = 10, int h = 10, int max_volume_ = 128, SDL_Color bar_color_ = SDL_Color{ 255,255,255,255 },
		SDL_Color user_choice_color_ = SDL_Color{ 255,0,0,255 });

	bool update(const mix_chunk_ptr& chunk);
	void draw(const Graphics& graphics);
private:
	int max_volume;

	SDL_Rect bar;
	SDL_Color bar_color;
	SDL_Rect user_choice_bar;
	SDL_Color user_choice_color;
};