#pragma once
#include "SDL_rect.h"
#include "Graphics.h"
#include "Paddle.h"

class Ball
{
public:
	/// <summary>
	/// Square representation of a ball
	/// </summary>
	/// <param name="x_">x coord of top left corner</param>
	/// <param name="y_">y coord of top left corner</param>
	/// <param name="s">side length of square</param>
	/// <param name="r_">red color component</param>
	/// <param name="g_">green color component</param>
	/// <param name="b_">blue color component</param>
	/// <param name="a_">alpha color component</param>
	/// <param name="vx">velocity x component in pixels per second</param>
	/// <param name="vy">velocity y component in pixels per second</param>
	Ball(int x_ = 0, int y_ = 0, int s = 1, int r_ = 255, int g_ = 255, int b_ = 255, int a_ = 255,int vx = 0, int vy = 0);
	void update(double seconds);
	void draw(const Graphics& graphics);
	void check_collisions(int window_height, int window_width, const Paddle& left, const Paddle& right);
	void apply_random_velocity();
private:
	int side_length;
	int r;
	int g;
	int b;
	int a;
	int x_velocity;
	int y_velocity;

	SDL_Rect square;

	const double pi = acos(-1);
};