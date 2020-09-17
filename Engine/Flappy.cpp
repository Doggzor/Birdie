#include "Flappy.h"

Flappy::Flappy(const Vec2& pos, float MaxSpeed, float grav, const Color& color)
	:
	pos (pos),
	MaxSpeed (MaxSpeed),
	grav (grav),
	c (color)
{
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
