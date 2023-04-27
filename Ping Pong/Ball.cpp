#include "Ball.h"
#include <stdexcept>
#include "Random.h"
#include <cmath>


Ball::Ball(int x_, int y_, int s, SDL_Color color_,int vx,int vy)
	:side_length{ s }, color{color_}, x_velocity{
	vx
}, y_velocity{ vy }
{
	if (x_ < 0) throw std::runtime_error("negative ball top left x coord");
	if (y_ < 0) throw std::runtime_error("negative ball top left y coord");
	if (s <= 0) throw std::runtime_error("nonpositive ball side length");
	if (color_.r < 0 || color_.r > 255) throw std::runtime_error("ball red color component not within [0,255]");
	if (color_.g < 0 || color_.g > 255) throw std::runtime_error("ball green color component not within [0,255]");
	if (color_.b < 0 || color_.b > 255) throw std::runtime_error("ball blue color component not within [0,255]");
	if (color_.a < 0 || color_.a > 255) throw std::runtime_error("ball alpha color component not within [0,255]");

	square = SDL_Rect{ x_,y_,s,s };
}

void Ball::update(double seconds)
{
	square.x += x_velocity * seconds;
	square.y += y_velocity * seconds;
}

void Ball::draw(const Graphics& graphics)
{
	graphics.draw(&square, color);
}

Collision Ball::check_collisions(int window_height,int window_width, const Paddle& left, const Paddle& right)
{
	Collision collision = Collision::NONE;
	// top window border
	if (square.y <= 0)
	{
		y_velocity *= -1;
		if (square.y < 0) square.y = 0;
		collision = Collision::TOP_BORDER;
	}

	// bottom window border
	if (square.y + square.h >= window_height)
	{
		y_velocity *= -1;
		if (square.y + square.h > window_height) square.y = window_height - square.h;
		collision = Collision::BOTTOM_BORDER;
	}

	// right window border
	if (square.x + square.w >= window_width)
	{
		square.x = window_width / 2;
		square.y = window_height / 2;
		apply_random_velocity();
		collision = Collision::RIGHT_BORDER;
	}

	// left window border
	if (square.x <= 0)
	{
		square.x = window_width / 2;
		square.y = window_height / 2;
		apply_random_velocity();
		collision = Collision::LEFT_BORDER;
	}

	// left paddle
	if (square.x <= left.get_x() + left.get_w() && square.x >= left.get_x() && ((square.y >= left.get_y() && square.y <= left.get_y() + left.get_h())
		|| (square.y + square.h >= left.get_y() && square.y + square.h <= left.get_y() + left.get_h())))
	{
		x_velocity *= -1;
		if (square.x < left.get_x() + left.get_w()) square.x = left.get_x() + left.get_w();
		// paddle and ball are moving in different vertical directions
		if ((y_velocity > 0 && left.get_velocity() < 0) || (y_velocity < 0 && left.get_velocity() > 0))
		{
			y_velocity *= -1;
		}
		collision = Collision::LEFT_PADDLE;
	}
	
	// right paddle
	if (square.x + square.w >= right.get_x() && square.x + square.w <= right.get_x() + right.get_w() && ((square.y >= right.get_y() && square.y <= right.get_y() + right.get_h())
		|| (square.y + square.h >= right.get_y() && square.y + square.h <= right.get_y() + right.get_h())))
	{
		x_velocity *= -1;
		if (square.x > right.get_x()) square.x = right.get_x();
		// paddle and ball are moving in different vertical directions
		if ((y_velocity > 0 && right.get_velocity() < 0) || (y_velocity < 0 && right.get_velocity() > 0))
		{
			y_velocity *= -1;
		}
		collision = Collision::RIGHT_PADDLE;
	}
	return collision;
}

void Ball::apply_random_velocity()
{
	int speed = sqrt((x_velocity * x_velocity) + (y_velocity * y_velocity));
	double x_direction = cos(random_double(0, 2 * pi));
	while (x_direction == 0) x_direction = cos(random_double(0, 2 * pi));
	double y_direction = sin(random_double(0, 2 * pi));
	double direction_magnitude = sqrt((x_direction * x_direction) + (y_direction * y_direction));
	x_velocity = speed * x_direction / direction_magnitude;
	y_velocity = speed * y_direction / direction_magnitude;
	if (abs(x_velocity) < 200) apply_random_velocity();		// too slow for frame time for the ball to move horizontally 
	if (abs(y_velocity) < 200) apply_random_velocity();
}

void Ball::reset(int window_width, int window_height)
{
	square.x = window_width / 2;
	square.y = window_height / 2;
	apply_random_velocity();
}

void Ball::change_color(SDL_Color color_)
{
	color = color_;
}
