#include "Pong.h"
#include <iostream>

int main(int argc, char* args[])
{
	try {
		if (SDL_Init(SDL_INIT_VIDEO) < 0)
		{
			throw std::runtime_error(SDL_GetError());
		}
		Pong game;
	}
	catch (std::exception& e)
	{
		std::cerr << e.what() << '\n';
	}
	return 0;
}