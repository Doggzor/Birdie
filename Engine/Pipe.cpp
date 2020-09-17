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

void Pipe::PushBack(float gap, int nPipes)
{
	//Push back the pipe when it goes off the left side of the screen, make a bigger gap after every 10 pipes
	if ((x + width / 2) < 0) x += (width + gap) * nPipes + gap * 5.0f;
}
