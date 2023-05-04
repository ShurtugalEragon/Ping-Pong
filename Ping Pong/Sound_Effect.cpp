#include "Sound_Effect.h"
#include <stdexcept>

Sound_Effect::Sound_Effect(const std::string& file_path)
{
	if (Mix_OpenAudio(44100, MIX_DEFAULT_FORMAT, 2, 2048) == -1)
	{
		throw std::runtime_error(Mix_GetError());
	}
	chunk = mix_chunk_ptr(Mix_LoadWAV(file_path.c_str()));
	if (!chunk) throw std::runtime_error(Mix_GetError());
}
