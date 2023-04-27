#include "Button.h"

Button::Button(const Graphics& graphics, int x_, int y_, int w, int h, SDL_Color button_color_)
	:x{ x_ }, y{ y_ }, width{ w }, height{ h }, button_color{button_color_}
{
	button = SDL_Rect{ x,y,w,h };
}

void Button::draw(const Graphics& graphics)
{
	graphics.draw(&button,button_color);
}

bool Button::clicked() const
{
	int mouse_x = 0;
	int mouse_y = 0;

	if (SDL_GetMouseState(&mouse_x, &mouse_y) == SDL_BUTTON(SDL_BUTTON_LEFT) && mouse_x >= button.x && mouse_x <= button.x + button.w
		&& mouse_y >= button.y && mouse_y <= button.y + button.h) return true;
	return false;
}
