#include "Pipe.h"

Pipe::Pipe(float x, const Color& c)
	:
	x (x),
	c (c)
{
}

void Pipe::Draw(Graphics& gfx)
{
	gfx.DrawRect((int)(x - width / 2.0f), 0, (int)(x + width / 2.0f), gfx.ScreenHeight, c);
}

void Pipe::Update(float speed, float dt)
{
	x -= speed * dt;
}
