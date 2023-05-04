#include "Pong.h"
#include "SDL_mixer.h"
#include <iostream>

int main(int argc, char* args[])
{
	try {
		if (SDL_Init(SDL_INIT_VIDEO | SDL_INIT_AUDIO) < 0)
		{
			throw std::runtime_error(SDL_GetError());
		}

		if (TTF_Init() == -1)
		{
			throw std::runtime_error(TTF_GetError());
		}

		if (Mix_Init(MIX_INIT_MP3) != MIX_INIT_MP3)
		{
			throw std::runtime_error("could not initialize SDL_mixer");
		}

		{					// scope to force TTF_CloseFont to be called before TTF_Quit() 
			Pong game;
		}
		TTF_Quit();
		Mix_Quit();
		SDL_Quit();
	}
	catch (std::exception& e)
	{
		std::cerr << e.what() << '\n';
	}
	return 0;
}