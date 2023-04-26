#include "Button.h"
#include <stdexcept>

Button::Button(const Graphics& graphics, const std::string& font_file_path, const std::string& button_text, int x_, int y_, int text_size, int vertical_padding, int horizontal_padding, SDL_Color button_color_, SDL_Color text_color_, bool horizontal_centered)
	:x{x_},y{y_},button_color{button_color_},text_color{text_color_}
{
	int measured_width = 0;
	int measured_height = 0;

	font_ptr font = font_ptr(TTF_OpenFont(font_file_path.c_str(), text_size));
	if (TTF_SizeUTF8(font.get(), button_text.c_str(), &measured_width, &measured_height) == -1) throw std::runtime_error("could not measure UTF8 text width");

	if (measured_width > graphics.get_window_width()) throw std::runtime_error("button text width > window width");
	if (measured_height > graphics.get_window_height()) throw std::runtime_error("button text height > window height");

	width = measured_width + 2 * horizontal_padding;
	height = measured_height + 2 * vertical_padding;

	if (horizontal_centered)
	{
		x = graphics.get_window_width() / 2 - width / 2;
	}

	text = Text(graphics, font_file_path, text_size, button_text, text_color_, x + horizontal_padding, y + vertical_padding);
	button = SDL_Rect{ x,y,width,height };
}

bool Button::clicked() const
{
	int mouse_x = 0;
	int mouse_y = 0;

	if (SDL_GetMouseState(&mouse_x, &mouse_y) == SDL_BUTTON(SDL_BUTTON_LEFT) && mouse_x >= button.x && mouse_x <= button.x + button.w
		&& mouse_y >= button.y && mouse_y <= button.y + button.h) return true;
	return false;
}

void Button::draw(const Graphics& graphics)
{
	graphics.draw(&button, button_color,false);
	text.draw(graphics);
}
