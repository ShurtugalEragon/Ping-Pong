#include "Pong.h"
#include <stdexcept>
#include <memory>
#include <chrono>
#include "Paddle.h"
#include <string>

Pong::Pong()
{
	ball.apply_random_velocity();
	show_main_menu();
}

void Pong::show_main_menu()
{
	graphics.clear_screen();
	play_button.draw(graphics);
	ball_color.draw(graphics);
	left_paddle_color.draw(graphics);
	right_paddle_color.draw(graphics);
	quit_button.draw(graphics);
	graphics.present();
	while (!quit)
	{
		SDL_Event event;
		while (SDL_PollEvent(&event))
		{
			switch (event.type)
			{
			case SDL_QUIT:
				quit = true;
				break;
			}
			if (play_button.clicked())
			{
				reset();
				start();
			}
			else if (ball_color.clicked()) show_color_picker(ball);
			else if (left_paddle_color.clicked()) show_color_picker(left_paddle,left_player_score_text);
			else if (right_paddle_color.clicked()) show_color_picker(right_paddle,right_player_score_text);
			else if (quit_button.clicked()) quit = true;
		}
	}
}

void Pong::show_color_picker(Paddle& paddle, Text& score_text, bool paused)
{
	graphics.clear_screen();

	red.draw(graphics);
	orange.draw(graphics);
	yellow.draw(graphics);

	green.draw(graphics);
	blue.draw(graphics);
	indigo.draw(graphics);

	violet.draw(graphics);

	graphics.present();

	SDL_Event event;
	while (!quit)
	{
		while (SDL_PollEvent(&event))
		{
			switch (event.type)
			{
			case SDL_QUIT:
				quit = true;
				break;
			}
			if (red.clicked())
			{
				paddle.change_color(RED);
				score_text.change_color(RED, graphics);
				if (paused) start();
				show_main_menu();
			}
			else if (orange.clicked())
			{
				paddle.change_color(ORANGE);
				score_text.change_color(ORANGE,graphics);
				if (paused) start();
				show_main_menu();
			}
			else if (yellow.clicked())
			{
				paddle.change_color(YELLOW);
				score_text.change_color(YELLOW,graphics);
				if (paused) start();
				show_main_menu();
			}
			else if (green.clicked())
			{
				paddle.change_color(GREEN);
				score_text.change_color(GREEN,graphics);
				if (paused) start();
				show_main_menu();
			}
			else if (blue.clicked())
			{
				paddle.change_color(BLUE);
				score_text.change_color(BLUE,graphics);
				if (paused) start();
				show_main_menu();
			}
			else if (indigo.clicked())
			{
				paddle.change_color(INDIGO);
				score_text.change_color(INDIGO,graphics);
				if (paused) start();
				show_main_menu();
			}
			else if (violet.clicked())
			{
				paddle.change_color(VIOLET);
				score_text.change_color(VIOLET,graphics);
				if (paused) start();
				show_main_menu();
			}
		}
	}
}

void Pong::show_color_picker(Ball& ball, bool paused)
{
	graphics.clear_screen();

	red.draw(graphics);
	orange.draw(graphics);
	yellow.draw(graphics);

	green.draw(graphics);
	blue.draw(graphics);
	indigo.draw(graphics);

	violet.draw(graphics);

	graphics.present();

	SDL_Event event;
	while (!quit)
	{
		while (SDL_PollEvent(&event))
		{
			switch (event.type)
			{
			case SDL_QUIT:
				quit = true;
				break;
			}
			if (red.clicked())
			{
				ball.change_color(RED);
				if (paused) start();
				show_main_menu();
			}
			else if (orange.clicked())
			{
				ball.change_color(ORANGE);
				if (paused) start();
				show_main_menu();
			}
			else if (yellow.clicked())
			{
				ball.change_color(YELLOW);
				if (paused) start();
				show_main_menu();
			}
			else if (green.clicked())
			{
				ball.change_color(GREEN);
				if (paused) start();
				show_main_menu();
			}
			else if (blue.clicked())
			{
				ball.change_color(BLUE);
				if (paused) start();
				show_main_menu();
			}
			else if (indigo.clicked())
			{
				ball.change_color(INDIGO);
				if (paused) start();
				show_main_menu();
			}
			else if (violet.clicked())
			{
				ball.change_color(VIOLET);
				if (paused) start();
				show_main_menu();
			}
		}
	}
}

void Pong::handle_key_press(const SDL_Event& e)
{
	//---------------------key is pressed---------------------
	if (e.type == SDL_KEYDOWN)
	{
		switch (e.key.keysym.sym)
		{
		case SDLK_p:
			paused = true;
			pause();
			break;
		case SDLK_m:
			show_main_menu();
			break;
		}
	}
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
	//--------------------------------------------------------



	//--------------------key is released---------------------
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
	//--------------------------------------------------------
}

void Pong::update()
{
	ball.update(frame_time);
	Collision collision = ball.check_collisions(WINDOW_HEIGHT, WINDOW_WIDTH,left_paddle,right_paddle);
	left_paddle.update(frame_time,WINDOW_HEIGHT);
	right_paddle.update(frame_time,WINDOW_HEIGHT);

	if (collision == Collision::LEFT_BORDER)
	{
		++right_player_score;
		right_player_score_text.update_text(std::to_string(right_player_score), graphics);
	}
	else if (collision == Collision::RIGHT_BORDER)
	{
		++left_player_score;
		left_player_score_text.update_text(std::to_string(left_player_score), graphics);
	}
	if (left_player_score == 11) left_win = true;
	else if (right_player_score == 11) right_win = true;

	if (collision != Collision::NONE)
	{
		ball_sound.play();
	}
}

void Pong::draw()
{
	ball.draw(graphics);
	left_paddle.draw(graphics);
	right_paddle.draw(graphics);
	left_player_score_text.draw(graphics);
	right_player_score_text.draw(graphics);
	if (left_win) left_win_text.draw(graphics);
	else if (right_win) right_win_text.draw(graphics);
}

void Pong::start()
{
	while (!quit)
	{
		auto start_time = std::chrono::high_resolution_clock::now();

		//-----------------------------Events--------------------------------
		SDL_Event event;
		while (SDL_PollEvent(&event))
		{
			switch (event.type)
			{
			case SDL_QUIT:
				quit = true;
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

		if (left_win || right_win)
		{
			reset();
			SDL_Delay(2500);			// keep win message up
		}
	}
}

void Pong::pause()
{
	graphics.clear_screen();
	pause_text.draw(graphics);
	ball_color.draw(graphics);
	left_paddle_color.draw(graphics);
	right_paddle_color.draw(graphics);
	quit_button.draw(graphics);
	graphics.present();
	SDL_Event event;
	while (!quit)
	{
		while (SDL_PollEvent(&event))
		{
			switch (event.type)
			{
			case SDL_QUIT:
				quit = true;
				break;
			case SDL_KEYDOWN:
				if (event.key.keysym.sym == SDLK_p)
				{
					paused = false;
					start();
				}
			}
			if (ball_color.clicked()) show_color_picker(ball,true);
			else if (left_paddle_color.clicked()) show_color_picker(left_paddle, left_player_score_text,true);
			else if (right_paddle_color.clicked()) show_color_picker(right_paddle, right_player_score_text,true);
			else if (quit_button.clicked()) quit = true;
		}
	}
}

void Pong::reset()
{
	ball.reset(WINDOW_WIDTH, WINDOW_HEIGHT);
	left_player_score = 0;
	right_player_score = 0;
	left_player_score_text.update_text("0", graphics);
	right_player_score_text.update_text("0", graphics);
	left_win = false;
	right_win = false;
	frame_time = 0.0;
}


