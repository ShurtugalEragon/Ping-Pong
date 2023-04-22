#pragma once
#include "SDL_rect.h"
#include "Graphics.h"

enum class Direction
{
	UP,DOWN
};

class Paddle
{
public:
	/// <summary>
	/// 
	/// </summary>
	/// <param name="x_">top left x coordinate of paddle</param>
	/// <param name="y_">top left y coordinate of paddle</param>
	/// <param name="w">width</param>
	/// <param name="h">height</param>
	/// <param name="r_">red</param>
	/// <param name="g_">green</param>
	/// <param name="b_">blue</param>
	/// <param name="a_">alpha</param>
	/// <param name="s">vertical speed</param>
	Paddle(int x_, int y_, int w, int h, int r_, int g_, int b_, int a_, int s);

	void move(Direction d);
	void stop();
	void update(double seconds, int window_height);
	void draw(const Graphics& graphics);

	int get_x() const {	return x; }
	int get_y() const { return y; }
	int get_w() const { return width; }
	int get_h() const { return height; }
	int get_velocity() const { return velocity; }

private:
	int x;
	int y;
	int width;
	int height;
	int r;
	int g;
	int b;
	int a;
	int speed;					// max vertical speed
	int velocity;				// actual real-time velocity

	SDL_Rect rectangle;
};