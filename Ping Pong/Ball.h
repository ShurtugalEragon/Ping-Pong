#pragma once
#include "SDL_rect.h"
#include "Graphics.h"
#include "Paddle.h"

enum class Collision
{
	LEFT_BORDER, RIGHT_BORDER, TOP_BORDER, BOTTOM_BORDER, LEFT_PADDLE, RIGHT_PADDLE, NONE
};

class Ball
{
public:
	/// <summary>
	/// Square representation of a ball
	/// </summary>
	/// <param name="x_">x coord of top left corner</param>
	/// <param name="y_">y coord of top left corner</param>
	/// <param name="s">side length of square</param>
	/// <param name="color_">color of the ball</param>
	/// <param name="vx">velocity x component in pixels per second</param>
	/// <param name="vy">velocity y component in pixels per second</param>
	Ball(int x_ = 0, int y_ = 0, int s = 1, SDL_Color color_ = SDL_Color{ 255,255,255,255 }, int vx = 0, int vy = 0);
	void update(double seconds);
	void draw(const Graphics& graphics);
	Collision check_collisions(int window_height, int window_width, const Paddle& left, const Paddle& right);
	void apply_random_velocity();
	void reset(int window_width, int window_height);
private:
	int side_length;
	SDL_Color color;
	int x_velocity;
	int y_velocity;

	SDL_Rect square;

	const double pi = acos(-1);
};