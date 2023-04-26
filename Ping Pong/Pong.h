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


	//--------------------------WINDOW CONSTANTS--------------------------
	
	const int WINDOW_WIDTH = graphics.get_window_width();
	const int WINDOW_HEIGHT = graphics.get_window_height();

	//--------------------------------------------------------------------
	






	//--------------------------BALL CONSTANTS----------------------------
	
	static constexpr int BALL_SPEED = 800;
	static constexpr int BALL_SIDE_LENGTH = 10;
	const int BALL_START_X = WINDOW_WIDTH / 2;
	const int BALL_START_Y = WINDOW_HEIGHT / 2;
	
	//--------------------------------------------------------------------







	//--------------------------PADDLE CONSTANTS--------------------------
	
	static constexpr int PADDLE_SPEED = 500;
	const int LEFT_PADDLE_START_X = WINDOW_WIDTH / 38;
	const int LEFT_PADDLE_START_Y = WINDOW_HEIGHT / 21;
	const int RIGHT_PADDLE_START_X = WINDOW_WIDTH - LEFT_PADDLE_START_X;
	const int RIGHT_PADDLE_START_Y = LEFT_PADDLE_START_Y;
	static constexpr int PADDLE_WIDTH = 8;
	const int PADDLE_HEIGHT = WINDOW_HEIGHT / 5;

	//--------------------------------------------------------------------






	//--------------------------TEXT CONSTANTS----------------------------
	
	static constexpr int SCORE_TEXT_SIZE = 60;
	static constexpr int WIN_MSG_TEXT_SIZE = 75;
	const int LEFT_SCORE_TEXT_X = WINDOW_WIDTH / 4;
	const int RIGHT_SCORE_TEXT_X = WINDOW_WIDTH * 0.75;
	const int SCORE_TEXT_Y = WINDOW_HEIGHT / 22;
	const int WIN_MSG_TEXT_X = WINDOW_WIDTH / 3.25;
	const int WIN_MSG_TEXT_Y = WINDOW_HEIGHT / 3;
	const std::string LEFT_WIN_MESSAGE = "Left player wins!";
	const std::string RIGHT_WIN_MESSAGE = "Right player wins!";

	//--------------------------------------------------------------------






	//--------------------------COLOR CONSTANTS---------------------------
	
	static constexpr SDL_Color WHITE = SDL_Color{ 255,255,255,255 };

	//--------------------------------------------------------------------






	//--------------------------FILE CONSTANTS----------------------------
	
	const std::string FONT_FILE_PATH = "RonysiswadiArchitect6-X3V9G.ttf";

	//--------------------------------------------------------------------
	
	


	Ball ball{ BALL_START_X,BALL_START_Y,BALL_SIDE_LENGTH,WHITE,BALL_SPEED,0 };
	Paddle left_paddle{ LEFT_PADDLE_START_X, LEFT_PADDLE_START_Y, PADDLE_WIDTH, PADDLE_HEIGHT, WHITE, PADDLE_SPEED };
	Paddle right_paddle{ RIGHT_PADDLE_START_X, RIGHT_PADDLE_START_Y, PADDLE_WIDTH, PADDLE_HEIGHT, WHITE, PADDLE_SPEED };

	Text left_player_score_text{ graphics,FONT_FILE_PATH,SCORE_TEXT_SIZE,"0",WHITE,LEFT_SCORE_TEXT_X,SCORE_TEXT_Y };
	Text right_player_score_text{ graphics,FONT_FILE_PATH,SCORE_TEXT_SIZE,"0",WHITE,RIGHT_SCORE_TEXT_X,SCORE_TEXT_Y };

	Text left_win_text{ graphics,FONT_FILE_PATH,WIN_MSG_TEXT_SIZE,LEFT_WIN_MESSAGE,WHITE,
	WIN_MSG_TEXT_X, WIN_MSG_TEXT_Y };

	Text right_win_text{ graphics,FONT_FILE_PATH,WIN_MSG_TEXT_SIZE,RIGHT_WIN_MESSAGE,WHITE,
	WIN_MSG_TEXT_X, WIN_MSG_TEXT_Y };

	void handle_key_press(const SDL_Event& e);
	void update();
	void draw();
	void play();
	void pause();

	int left_player_score = 0;
	int right_player_score = 0;

	bool left_win = false;
	bool right_win = false;
	bool paused = false;
};