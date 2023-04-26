#include "Pong.h"
#include <iostream>

int main(int argc, char* args[])
{
	try {
		if (SDL_Init(SDL_INIT_VIDEO) < 0)
		{
			throw std::runtime_error(SDL_GetError());
		}

		if (TTF_Init() == -1)
		{
			throw std::runtime_error(TTF_GetError());
		}

		{					// scope to force TTF_CloseFont to be called before TTF_Quit() 
			Pong game;
		}
		TTF_Quit();
	}
	catch (std::exception& e)
	{
		std::cerr << e.what() << '\n';
	}
	return 0;
}