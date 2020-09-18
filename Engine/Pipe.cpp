#include "Pipe.h"

Pipe::Pipe(float x, const Color& c)
	:
	x (x),
	c (c)
{
	safebox = { Vec2(x, rng::rdm_float(safebox.height + 20.0f, 580.0f - safebox.height)), width };
	x_start = x;
	c_start = c;
}

void Pipe::Draw(int top, Graphics& gfx)
{
	gfx.DrawRect((int)(x - width / 2.0f), top, (int)(x + width / 2.0f), gfx.ScreenHeight, c);
	safebox.Draw(gfx);
}

void Pipe::Update(float speed, float dt)
{
	x -= speed * dt;
	safebox.center.x = x;
}

void Pipe::reset(int top)
{
	x = x_start;
	c = c_start;
	safebox = { Vec2(x, rng::rdm_float(safebox.height + (float)top + 20.0f, 580.0f - safebox.height)), width };
}

void Pipe::PushBack(float gap, int nPipes)
{
	if ((x + width / 2) < 0)
	{
		x += (width + gap) * nPipes; //Push back the pipe when it goes off the left side of the screen, to make a bigger gap after every 10 pipes, add "+ gap * 5.0f" at the end
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

const SafeBox& Pipe::GetSafeBox() const
{
	return safebox;
}
