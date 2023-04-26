#include "Text.h"
#include <stdexcept>

Text::Text(const Graphics& graphics, std::string font_file_path, int point_size_, std::string text_, SDL_Color color_, int x_, int y_)
	:point_size{ point_size_ }, text{text_}, color{color_}, x{x_}, y{y_}
{
	font = font_ptr(TTF_OpenFont(font_file_path.c_str(),point_size_));
	if (!font) throw std::runtime_error("could not create font");

	surface = surface_ptr(TTF_RenderUTF8_Solid(font.get(), text.c_str(), color));
	if (!surface) throw std::runtime_error("could not create text surface");

	texture = texture_ptr(SDL_CreateTextureFromSurface(graphics.get_renderer(), surface.get()));
	if (!texture) throw std::runtime_error(SDL_GetError());
}

Text::Text()
	:point_size{ 1 }, text{ "" }, color{ SDL_Color{255,255,255,255} }, x{ 0 }, y{ 0 }
{

}

void Text::draw(const Graphics& graphics)
{
	SDL_Rect destination_rect{ x,y,surface.get()->w,surface.get()->h };
	if (SDL_RenderCopy(graphics.get_renderer(), texture.get(), nullptr, &destination_rect) < 0) throw std::runtime_error(SDL_GetError());
}

void Text::update_text(std::string text_, const Graphics& graphics)
{
	text = text_;

	surface = surface_ptr(TTF_RenderUTF8_Solid(font.get(), text.c_str(), color));
	if (!surface) throw std::runtime_error("could not create text surface");

	texture = texture_ptr(SDL_CreateTextureFromSurface(graphics.get_renderer(), surface.get()));
	if (!texture) throw std::runtime_error(SDL_GetError());
}