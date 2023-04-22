#include "Pong.h"
#include <stdexcept>
#include <memory>
#include <chrono>
#include "Paddle.h"

Pong::Pong()
{
	play();
}

Pong::~Pong()
{
	SDL_Quit();
}

void Pong::handle_key_press(const SDL_Event& e)
{
	// key is pressed
	if (e.type == SDL_KEYDOWN && e.key.repeat == 0)
	{
		switch (e.key.keysym.sym)
		{
		case SDLK_w:
			left_paddle.move(Direction::UP);
			break;
		case SDLK_s:
			left_paddle.move(Direction::DOWN);
			break;
		case SDLK_UP:
			right_paddle.move(Direction::UP);
			break;
		case SDLK_DOWN:
			right_paddle.move(Direction::DOWN);
			break;
		}
		
	}
	// key is released
	else if (e.type == SDL_KEYUP && e.key.repeat == 0)
	{
		switch (e.key.keysym.sym)
		{
		case SDLK_w:
			left_paddle.stop();
			break;
		case SDLK_s:
			left_paddle.stop();
			break;
		case SDLK_UP:
			right_paddle.stop();
			break;
		case SDLK_DOWN:
			right_paddle.stop();
			break;
		}
	}
}

void Pong::update()
{
	ball.update(frame_time);
	ball.check_collisions(graphics.get_window_height(), graphics.get_window_width(),left_paddle,right_paddle);
	left_paddle.update(frame_time,graphics.get_window_height());
	right_paddle.update(frame_time,graphics.get_window_height());
}

void Pong::draw()
{
	ball.draw(graphics);
	left_paddle.draw(graphics);
	right_paddle.draw(graphics);
}

void Pong::play()
{
	while (playing)
	{
		auto start_time = std::chrono::high_resolution_clock::now();

		//-----------------------------Events--------------------------------
		SDL_Event event;
		while (SDL_PollEvent(&event))
		{
			switch (event.type)
			{
			case SDL_QUIT:
				playing = false;
				break;
			}
			handle_key_press(event);
		}
		//-------------------------------------------------------------------

		graphics.clear_screen();

		update();
		draw();

		graphics.present();

		auto stop_time = std::chrono::high_resolution_clock::now();
		frame_time = std::chrono::duration<double>(stop_time - start_time).count();
	}
}


