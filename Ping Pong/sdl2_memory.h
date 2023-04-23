#pragma once
#include "SDL.h"
#include "SDL_ttf.h"
#include <memory>

struct SDL_Deleter
{
	void operator()(SDL_Surface* ptr) { if (ptr) SDL_FreeSurface(ptr); }
	void operator()(SDL_Texture* ptr) { if (ptr) SDL_DestroyTexture(ptr); }
	void operator()(SDL_Renderer* ptr) { if (ptr) SDL_DestroyRenderer(ptr); }
	void operator()(SDL_Window* ptr) { if (ptr) SDL_DestroyWindow(ptr); }
	void operator()(TTF_Font* ptr) { if (ptr) TTF_CloseFont(ptr); }
};

using surface_ptr = std::unique_ptr<SDL_Surface, SDL_Deleter>;
using texture_ptr = std::unique_ptr<SDL_Texture, SDL_Deleter>;
using renderer_ptr = std::unique_ptr<SDL_Renderer, SDL_Deleter>;
using window_ptr = std::unique_ptr<SDL_Window, SDL_Deleter>;
using font_ptr = std::unique_ptr<TTF_Font, SDL_Deleter>;
