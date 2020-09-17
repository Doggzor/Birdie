#include "Flappy.h"

Flappy::Flappy(const Vec2& pos, float speed, float grav, const Color& color)
	:
	pos (pos),
	speed (speed),
	grav (grav),
	c (color)
{
}

void Flappy::Draw(Graphics& gfx)
{
	gfx.DrawRect(pos, width, height, c);
}
