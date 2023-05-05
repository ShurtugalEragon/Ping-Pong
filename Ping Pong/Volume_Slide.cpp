#include "Volume_Slide.h"
#include <stdexcept>

Volume_Slide::Volume_Slide(int x, int y, int w, int h, int max_volume_, SDL_Color bar_color_, SDL_Color user_choice_color_)
	:max_volume{max_volume_}, bar_color{bar_color_},user_choice_color{user_choice_color_}
{
	if (x < 0 || y < 0) throw std::runtime_error("negative Volume_Slide coord");
	if (w < 0 || h < 0) throw std::runtime_error("negative Volume_Slide dimension");
	if (max_volume_ <= 0) throw std::runtime_error("Volume_Slide max_volume was not a positive integer");

	bar = SDL_Rect{x,y,w,h};
	user_choice_bar = SDL_Rect{ x,y,w,h };
}

bool Volume_Slide::update(const mix_chunk_ptr& chunk)
{
	int mouse_x = 0;
	int mouse_y = 0;

	// user clicked within the volume slide bar
	if (SDL_GetMouseState(&mouse_x, &mouse_y) == SDL_BUTTON(SDL_BUTTON_LEFT) && mouse_x >= bar.x && mouse_x <= bar.x + bar.w
		&& mouse_y >= bar.y && mouse_y <= bar.y + bar.h)
	{
		int user_choice_width = mouse_x - bar.x;
		user_choice_bar.w = user_choice_width;

		double volume_ratio = (double)user_choice_bar.w / bar.w;

		int new_volume = max_volume * volume_ratio;

		Mix_VolumeChunk(chunk.get(), new_volume);

		return true;
	}
	return false;
}


void Volume_Slide::draw(const Graphics& graphics)
{
	graphics.draw(&user_choice_bar, user_choice_color);
	graphics.draw(&bar, bar_color, false);
}

