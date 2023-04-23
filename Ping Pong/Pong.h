#pragma once
#include <string>
#include "Graphics.h"
#include "Ball.h"
#include "Paddle.h"

#include "Text.h"

class Pong
{
public:
	Pong();
	~Pong();
private:
	bool playing = true;
	double frame_time = 0.0;

	Graphics graphics{ "Ping Pong" };

	Ball ball{ graphics.get_window_width() / 2,graphics.get_window_height() / 2,10,255,255,255,255,800,0 };
	Paddle left_paddle{ 50, 50, 8, graphics.get_window_height() / 5, 255, 255, 255, 255, 500 };
	Paddle right_paddle{ graphics.get_window_width()-60, 50, 8, graphics.get_window_height() / 5, 255, 255, 255, 255, 500 };

	Text left_player_score_text{ graphics,"RonysiswadiArchitect6-X3V9G.ttf",50,"0",SDL_Color{255,255,255,255},graphics.get_window_width() / 4,50 };
	Text right_player_score_text{ graphics,"RonysiswadiArchitect6-X3V9G.ttf",50,"0",SDL_Color{255,255,255,255},graphics.get_window_width() * 0.75,50 };


	void handle_key_press(const SDL_Event& e);
	void update();
	void draw();
	void play();

	int left_player_score = 0;
	int right_player_score = 0;

	bool left_win = false;
	bool right_win = false;
};