#pragma once
#include <string>
#include "Graphics.h"
#include "Ball.h"
#include "Paddle.h"
#include "Text_Button.h"
#include "Text.h"
#include "Button.h"
#include "Sound_Effect.h"
#include "Volume_Slide.h"

class Pong
{
public:
	Pong();
private:
	
	bool quit = false;
	double frame_time = 0.0;

	Graphics graphics{ "Ping Pong" };


	//--------------------------WINDOW CONSTANTS--------------------------
	
	const int WINDOW_WIDTH = graphics.get_window_width();
	const int WINDOW_HEIGHT = graphics.get_window_height();

	//--------------------------------------------------------------------
	






	//--------------------------BALL CONSTANTS----------------------------
	
	static constexpr int BALL_SPEED = 900;
	static constexpr int BALL_SIDE_LENGTH = 10;
	const int BALL_START_X = WINDOW_WIDTH / 2;
	const int BALL_START_Y = WINDOW_HEIGHT / 2;
	
	//--------------------------------------------------------------------







	//--------------------------PADDLE CONSTANTS--------------------------
	
	static constexpr int PADDLE_SPEED = 600;
	const int LEFT_PADDLE_START_X = WINDOW_WIDTH / 38;
	const int LEFT_PADDLE_START_Y = WINDOW_HEIGHT / 21;
	const int RIGHT_PADDLE_START_X = WINDOW_WIDTH - LEFT_PADDLE_START_X;
	const int RIGHT_PADDLE_START_Y = LEFT_PADDLE_START_Y;
	static constexpr int PADDLE_WIDTH = 8;
	const int PADDLE_HEIGHT = WINDOW_HEIGHT / 5;

	//--------------------------------------------------------------------






	//--------------------------TEXT CONSTANTS----------------------------
	
	const int SCORE_TEXT_SIZE = WINDOW_HEIGHT / 12;
	const int WIN_MSG_TEXT_SIZE = WINDOW_HEIGHT / 13;
	const int LEFT_SCORE_TEXT_X = WINDOW_WIDTH / 4;
	const int RIGHT_SCORE_TEXT_X = WINDOW_WIDTH * 0.75;
	const int SCORE_TEXT_Y = WINDOW_HEIGHT / 22;
	const int WIN_MSG_TEXT_X = WINDOW_WIDTH / 2.75;
	const int WIN_MSG_TEXT_Y = WINDOW_HEIGHT / 3;
	const std::string LEFT_WIN_MESSAGE = "Left player wins!";
	const std::string RIGHT_WIN_MESSAGE = "Right player wins!";
	const int PAUSE_MSG_TEXT_X = WINDOW_WIDTH / 2.4;
	const int PAUSE_MSG_TEXT_Y = WINDOW_HEIGHT / 8;
	const int PAUSE_MSG_TEXT_SIZE = WINDOW_HEIGHT / 14;
	const std::string PAUSE_MESSAGE = "Paused";
	const int BALL_VOLUME_TEXT_SIZE = WINDOW_HEIGHT / 13;
	const int BALL_VOLUME_TEXT_X = WINDOW_WIDTH / 2.45;
	const int BALL_VOLUME_TEXT_Y = WINDOW_HEIGHT / 3;

	//--------------------------------------------------------------------






	//--------------------------COLOR CONSTANTS---------------------------
	
	static constexpr SDL_Color WHITE = SDL_Color{ 255,255,255,255 };
	static constexpr SDL_Color RED = SDL_Color{ 255,0,0,255 };
	static constexpr SDL_Color ORANGE = SDL_Color{ 255,165,0 };
	static constexpr SDL_Color YELLOW = SDL_Color{ 255,255,0 };
	static constexpr SDL_Color GREEN = SDL_Color{ 0,255,0 };
	static constexpr SDL_Color BLUE = SDL_Color{ 0,0,255 };
	static constexpr SDL_Color INDIGO = SDL_Color{ 75,0,130 };
	static constexpr SDL_Color VIOLET = SDL_Color{ 143,0,255 };

	//--------------------------------------------------------------------






	//--------------------------FILE CONSTANTS----------------------------
	
	const std::string FONT_FILE_PATH = "RonysiswadiArchitect6-X3V9G.ttf";
	const std::string BALL_SOUND_EFFECT_FILE_PATH = "ball.wav";

	//--------------------------------------------------------------------






	//--------------------------BUTTON CONSTANTS--------------------------
	
	const int PLAY_BUTTON_Y = WINDOW_HEIGHT / 9.61;
	const int AUDIO_BUTTON_Y = WINDOW_HEIGHT / 4;
	const int BALL_COLOR_Y = WINDOW_HEIGHT / 2.5;
	const int LEFT_PADDLE_COLOR_Y = WINDOW_HEIGHT / 1.82;
	const int RIGHT_PADDLE_COLOR_Y = WINDOW_HEIGHT / 1.43;
	const int QUIT_BUTTON_Y = WINDOW_HEIGHT / 1.18;

	const int BUTTON_TEXT_SIZE = WINDOW_HEIGHT / 20;
	const int BUTTON_VERTICAL_PADDING =	WINDOW_HEIGHT / 50;
	const int PLAY_BUTTON_HORIZONTAL_PADDING = WINDOW_HEIGHT / 3;
	const int AUDIO_BUTTON_HORIZONTAL_PADDING = WINDOW_HEIGHT / 3.15;
	const int BALL_COLOR_BUTTON_HORIZONTAL_PADDING = WINDOW_HEIGHT / 4.9;
	const int LEFT_COLOR_BUTTON_HORIZONTAL_PADDING = WINDOW_HEIGHT / 8.108;
	const int RIGHT_COLOR_BUTTON_HORIZONTAL_PADDING = WINDOW_HEIGHT / 8.61;
	const int QUIT_BUTTON_HORIZONTAL_PADDING = WINDOW_HEIGHT / 3;

	const int RED_BUTTON_X = WINDOW_WIDTH / 4;
	const int ORANGE_BUTTON_X = WINDOW_WIDTH / 2;
	const int YELLOW_BUTTON_X = WINDOW_WIDTH * 0.75;
	const int GREEN_BUTTON_X = RED_BUTTON_X;
	const int BLUE_BUTTON_X = ORANGE_BUTTON_X;
	const int INDIGO_BUTTON_X = YELLOW_BUTTON_X;
	const int VIOLET_BUTTON_X = ORANGE_BUTTON_X;

	const int COLOR_ROW1_Y = WINDOW_HEIGHT / 4;
	const int COLOR_ROW2_Y = WINDOW_HEIGHT / 2;
	const int COLOR_ROW3_Y = WINDOW_HEIGHT * 0.75;

	const int COLOR_BUTTON_WIDTH = WINDOW_WIDTH / 20;
	const int COLOR_BUTTON_HEIGHT = WINDOW_HEIGHT / 12;

	//--------------------------------------------------------------------






	//--------------------------Volume Constants--------------------------
	
	const int BALL_VOLUME_WIDTH = WINDOW_WIDTH / 3;
	const int BALL_VOLUME_HEIGHT = WINDOW_HEIGHT / 25;
	const int BALL_VOLUME_X = WINDOW_WIDTH / 2 - BALL_VOLUME_WIDTH / 2;
	const int BALL_VOLUME_Y = WINDOW_HEIGHT / 2 - BALL_VOLUME_HEIGHT / 2;
	const int BALL_MAX_VOLUME = MIX_MAX_VOLUME;
	const SDL_Color BALL_VOLUME_BAR_COLOR = WHITE;
	const SDL_Color BALL_VOLUME_USER_CHOICE_COLOR = RED;


	//--------------------------------------------------------------------
	
	
	Text_Button play_button = Text_Button(graphics, FONT_FILE_PATH, "Play", 0, PLAY_BUTTON_Y, BUTTON_TEXT_SIZE, BUTTON_VERTICAL_PADDING, PLAY_BUTTON_HORIZONTAL_PADDING, WHITE);

	Text_Button audio_button = Text_Button(graphics, FONT_FILE_PATH, "Audio", 0, AUDIO_BUTTON_Y, BUTTON_TEXT_SIZE, BUTTON_VERTICAL_PADDING, AUDIO_BUTTON_HORIZONTAL_PADDING, WHITE);

	Text_Button ball_color = Text_Button(graphics, FONT_FILE_PATH, "Choose ball color", 0, BALL_COLOR_Y, BUTTON_TEXT_SIZE, BUTTON_VERTICAL_PADDING, BALL_COLOR_BUTTON_HORIZONTAL_PADDING, WHITE);

	Text_Button left_paddle_color = Text_Button(graphics, FONT_FILE_PATH, "Choose left paddle color", 0, LEFT_PADDLE_COLOR_Y, BUTTON_TEXT_SIZE, BUTTON_VERTICAL_PADDING, LEFT_COLOR_BUTTON_HORIZONTAL_PADDING, WHITE);

	Text_Button right_paddle_color = Text_Button(graphics, FONT_FILE_PATH, "Choose right paddle color", 0, RIGHT_PADDLE_COLOR_Y, BUTTON_TEXT_SIZE, BUTTON_VERTICAL_PADDING, RIGHT_COLOR_BUTTON_HORIZONTAL_PADDING, WHITE);

	Text_Button quit_button = Text_Button(graphics, FONT_FILE_PATH, "Quit", 0, QUIT_BUTTON_Y, BUTTON_TEXT_SIZE, BUTTON_VERTICAL_PADDING, QUIT_BUTTON_HORIZONTAL_PADDING, WHITE);

	Text_Button back_button = Text_Button(graphics, FONT_FILE_PATH, "Back", 0, QUIT_BUTTON_Y, BUTTON_TEXT_SIZE, BUTTON_VERTICAL_PADDING, QUIT_BUTTON_HORIZONTAL_PADDING, WHITE);

	Button red = Button(graphics, RED_BUTTON_X, COLOR_ROW1_Y, COLOR_BUTTON_WIDTH, COLOR_BUTTON_HEIGHT, RED);
	Button orange = Button(graphics, ORANGE_BUTTON_X, COLOR_ROW1_Y, COLOR_BUTTON_WIDTH, COLOR_BUTTON_HEIGHT, ORANGE);
	Button yellow = Button(graphics, YELLOW_BUTTON_X, COLOR_ROW1_Y, COLOR_BUTTON_WIDTH, COLOR_BUTTON_HEIGHT, YELLOW);

	Button green = Button(graphics, GREEN_BUTTON_X, COLOR_ROW2_Y, COLOR_BUTTON_WIDTH, COLOR_BUTTON_HEIGHT, GREEN);
	Button blue = Button(graphics, BLUE_BUTTON_X, COLOR_ROW2_Y, COLOR_BUTTON_WIDTH, COLOR_BUTTON_HEIGHT, BLUE);
	Button indigo = Button(graphics, INDIGO_BUTTON_X, COLOR_ROW2_Y, COLOR_BUTTON_WIDTH, COLOR_BUTTON_HEIGHT, INDIGO);

	Button violet = Button(graphics, VIOLET_BUTTON_X, COLOR_ROW3_Y, COLOR_BUTTON_WIDTH, COLOR_BUTTON_HEIGHT, VIOLET);


	Ball ball{ BALL_START_X,BALL_START_Y,BALL_SIDE_LENGTH,WHITE,BALL_SPEED,0 };

	Paddle left_paddle{ LEFT_PADDLE_START_X, LEFT_PADDLE_START_Y, PADDLE_WIDTH, PADDLE_HEIGHT, WHITE, PADDLE_SPEED };
	Paddle right_paddle{ RIGHT_PADDLE_START_X, RIGHT_PADDLE_START_Y, PADDLE_WIDTH, PADDLE_HEIGHT, WHITE, PADDLE_SPEED };

	Text left_player_score_text{ graphics,FONT_FILE_PATH,SCORE_TEXT_SIZE,"0",WHITE,LEFT_SCORE_TEXT_X,SCORE_TEXT_Y };
	Text right_player_score_text{ graphics,FONT_FILE_PATH,SCORE_TEXT_SIZE,"0",WHITE,RIGHT_SCORE_TEXT_X,SCORE_TEXT_Y };

	Text left_win_text{ graphics,FONT_FILE_PATH,WIN_MSG_TEXT_SIZE,LEFT_WIN_MESSAGE,WHITE,
	WIN_MSG_TEXT_X, WIN_MSG_TEXT_Y };
	Text right_win_text{ graphics,FONT_FILE_PATH,WIN_MSG_TEXT_SIZE,RIGHT_WIN_MESSAGE,WHITE,
	WIN_MSG_TEXT_X, WIN_MSG_TEXT_Y };
	Text pause_text{ graphics,FONT_FILE_PATH,PAUSE_MSG_TEXT_SIZE,PAUSE_MESSAGE,WHITE,PAUSE_MSG_TEXT_X,PAUSE_MSG_TEXT_Y };

	Sound_Effect ball_sound{ BALL_SOUND_EFFECT_FILE_PATH };

	Volume_Slide ball_volume{ BALL_VOLUME_X,BALL_VOLUME_Y,BALL_VOLUME_WIDTH,BALL_VOLUME_HEIGHT,BALL_MAX_VOLUME,BALL_VOLUME_BAR_COLOR,BALL_VOLUME_USER_CHOICE_COLOR };

	Text ball_volume_text{ graphics,FONT_FILE_PATH,BALL_VOLUME_TEXT_SIZE,"Ball Bounce",WHITE,BALL_VOLUME_TEXT_X,BALL_VOLUME_TEXT_Y };

	void show_main_menu();
	void show_color_picker(Paddle& paddle, Text& score_text, bool paused = false);
	void show_color_picker(Ball& ball, bool paused = false);
	void show_volume_menu();
	void handle_key_press(const SDL_Event& e);
	void update();
	void draw();
	void start();
	void pause();
	void reset();

	int left_player_score = 0;
	int right_player_score = 0;

	bool left_win = false;
	bool right_win = false;
	bool paused = false;
};