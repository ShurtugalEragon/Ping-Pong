#include "Paddle.h"
#include <cmath>
#include <stdexcept>

Paddle::Paddle(int x_, int y_, int w, int h, int r_, int g_, int b_, int a_, int s)
	:x{ x_ }, y{ y_ }, width{w}, height{ h }, r{ r_ }, g{ g_ }, b{ b_ }, a{ a_ }, speed{ s }
{
	if (x_ < 0) throw std::runtime_error("negative paddle top left x coord");
	if (y_ < 0) throw std::runtime_error("negative paddle top left y coord");
	if (s <= 0) throw std::runtime_error("nonpositive paddle side length");
	if (r_ < 0 || r_ > 255) throw std::runtime_error("paddle red color component not within [0,255]");
	if (g_ < 0 || g_ > 255) throw std::runtime_error("paddle green color component not within [0,255]");
	if (b_ < 0 || b_ > 255) throw std::runtime_error("paddle blue color component not within [0,255]");
	if (a_ < 0 || a_ > 255) throw std::runtime_error("paddle alpha color component not within [0,255]");
	if (s == 0) throw std::runtime_error("paddle must have nonzero vertical speed value");

	rectangle = SDL_Rect{ x_,y_,w,h };
}

void Paddle::move(Direction d)
{
	switch (d)
	{
	case Direction::UP:
		velocity = -speed;
		break;
	case Direction::DOWN:
		velocity = speed;
		break;
	}
}

void Paddle::stop()
{
	velocity = 0;
}

void Paddle::update(double seconds, int window_height)
{
	if (rectangle.y <= 0 && velocity < 0)					// stop paddle from going beyond top window border
	{
		velocity = 0;
		if (rectangle.y < 0) rectangle.y = 0;
	}
	else if (rectangle.y + rectangle.h >= window_height && velocity > 0)		// stop paddle from going beyond bottom window border
	{
		velocity = 0;
		if (rectangle.y + rectangle.h > window_height) rectangle.y = window_height - rectangle.h;
	}
	else rectangle.y += velocity * seconds;
	y = rectangle.y;
}

void Paddle::draw(const Graphics& graphics)
{
	graphics.draw(&rectangle, r, g, b, a);
}
