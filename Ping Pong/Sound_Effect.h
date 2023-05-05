#pragma once
#include <string>
#include "SDL_mixer.h"
#include "sdl2_memory.h"

class Sound_Effect
{
public:
	Sound_Effect(const std::string& file_path);

	void play() const { Mix_PlayChannel(-1, chunk.get(), 0); }
	const mix_chunk_ptr& get_chunk() { return chunk; }
private:
	mix_chunk_ptr chunk;
};