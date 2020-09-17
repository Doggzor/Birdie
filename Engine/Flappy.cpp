#include "Flappy.h"

Flappy::Flappy(const Vec2& pos, float MaxSpeed, float grav, const Color& color)
	:
	pos (pos),
	MaxSpeed (MaxSpeed),
	grav (grav),
	c (color)
{
	pos_start = pos;
	c_start = c;
}

void Flappy::Draw(Graphics& gfx)
{
	gfx.DrawRect(pos, width, height, c);
}

void Flappy::Update(Keyboard& kbd, Mouse& mouse, float dt)
{
	if ((kbd.KeyIsPressed(VK_SPACE) || mouse.LeftIsPressed()) && (!bKBD_Space_Inhibited && !bMouse_LB_Inhibited))
	{
		speed = MaxSpeed;
	}
	bMouse_LB_Inhibited = mouse.LeftIsPressed();
	bKBD_Space_Inhibited = kbd.KeyIsPressed(VK_SPACE);
	
	pos.y -= speed * dt;
	speed -= grav * dt;
}

void Flappy::reset()
{
	pos = pos_start;
	c = c_start;
	speed = 0;
}

bool Flappy::bDead(const SafeBox& safebox)
{
	const float left = pos.x - width / 2.0f;
	const float right = pos.x + width / 2.0f;
	const float top = pos.y - height / 2.0f;
	const float bottom = pos.y + height / 2.0f;

	const float boxleft = safebox.center.x - safebox.width / 2.0f;
	const float boxright = safebox.center.x + safebox.width / 2.0f;
	const float boxtop = safebox.center.y - safebox.height / 2.0f;
	const float boxbottom = safebox.center.y + safebox.height / 2.0f;

	if (right > boxleft && left < boxright) //Is bird overlapping with the pipe
	{
		if (top > boxtop && bottom < boxbottom) return false; //Is bird inside the hole in the pipe
		else return true;
	}
	else return false;
}
