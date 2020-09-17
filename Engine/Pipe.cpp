#include "Pipe.h"

Pipe::Pipe(float x, const Color& c)
	:
	x (x),
	c (c)
{
	safebox = { Vec2(x, rng::rdm_float(safebox.height + 20.0f, 580.0f - safebox.height)), width };
}

void Pipe::Draw(Graphics& gfx)
{
	gfx.DrawRect((int)(x - width / 2.0f), 0, (int)(x + width / 2.0f), gfx.ScreenHeight, c);
	safebox.Draw(gfx);
}

void Pipe::Update(float speed, float dt)
{
	x -= speed * dt;
	safebox.center.x = x;
}

void Pipe::PushBack(float gap, int nPipes)
{
	if ((x + width / 2) < 0)
	{
		x += (width + gap) * nPipes + gap * 5.0f; //Push back the pipe when it goes off the left side of the screen, make a bigger gap after every 10 pipes
		safebox.center.y = rng::rdm_float(safebox.height + 20.0f, 580.0f - safebox.height); //Randomize the position of the safebox
	}
}

float Pipe::GetX()
{
	return x;
}

float Pipe::GetWidth()
{
	return width;
}
