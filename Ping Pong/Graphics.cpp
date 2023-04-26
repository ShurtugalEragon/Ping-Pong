#include "Graphics.h"
#include <stdexcept>

Graphics::Graphics(std::string window_title)
	:title{window_title}
{
	window = window_ptr(SDL_CreateWindow(window_title.c_str(), SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, 100, 100, SDL_WINDOW_MAXIMIZED));

	if (!window)
	{
		throw std::runtime_error(SDL_GetError());
	}
	SDL_GetWindowSize(window.get(), &width, &height);
	SDL_GetWindowPosition(window.get(), &x, &y);

	renderer = renderer_ptr(SDL_CreateRenderer(window.get(),-1,SDL_RENDERER_ACCELERATED | SDL_RENDERER_PRESENTVSYNC));
	if (!renderer) throw std::runtime_error(SDL_GetError());
}

void Graphics::clear_screen()
{
	if (SDL_SetRenderDrawColor(renderer.get(), 0, 0, 0, 255) < 0) throw std::runtime_error(SDL_GetError());
	if (SDL_RenderClear(renderer.get()) < 0) throw std::runtime_error(SDL_GetError());
}

void Graphics::draw(SDL_Rect* rect,SDL_Color color, bool fill) const
{

	if (SDL_SetRenderDrawColor(renderer.get(), color.r, color.g, color.b, color.a) < 0) throw std::runtime_error(SDL_GetError());
	if (fill)
	{
		if (SDL_RenderFillRect(renderer.get(), rect) < 0) throw std::runtime_error(SDL_GetError());
	}
	else
	{
		if (SDL_RenderDrawRect(renderer.get(), rect) < 0) throw std::runtime_error(SDL_GetError());
	}
}
void Graphics::present()
{
	SDL_RenderPresent(renderer.get());
}
