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
	//gfx.DrawRect(pos, width, height, c);

	int x = (int)(pos.x - width / 2);
	int y = (int)(pos.y - height / 2);
	if (speed > 0) img::BirdFlap(x, y, gfx);
	else img::BirdFly(x, y, gfx);
}

void Flappy::Update(Keyboard& kbd, Mouse& mouse, float dt)
{
	//Controls
	if ((kbd.KeyIsPressed(VK_SPACE) || mouse.LeftIsPressed()) && (!bKBD_Space_Inhibited && !bMouse_LB_Inhibited))
	{
		speed = MaxSpeed;
	}
	bMouse_LB_Inhibited = mouse.LeftIsPressed();
	bKBD_Space_Inhibited = kbd.KeyIsPressed(VK_SPACE);
	
	//Movement
	pos.y -= speed * dt;
	speed -= grav * dt;

	//Score counter cooldown timer
	if (fScoreCD > 0) fScoreCD -= dt;
	else fScoreCD = 0;
}

void Flappy::reset()
{
	pos = pos_start;
	c = c_start;
	speed = 0;
	score = 0;
}

bool Flappy::bDead(const SafeBox& safebox, int topwall)
{
	//2.0f at the end is a margin for error
	const float left = pos.x - width / 2.0f + 2.0f;
	const float right = pos.x + width / 2.0f - 2.0f;
	const float top = pos.y - height / 2.0f + 2.0f;
	const float bottom = pos.y + height / 2.0f - 2.0f;

	const float boxleft = safebox.center.x - safebox.width / 2.0f;
	const float boxright = safebox.center.x + safebox.width / 2.0f;
	const float boxtop = safebox.center.y - safebox.height / 2.0f;
	const float boxbottom = safebox.center.y + safebox.height / 2.0f;

	if (right > boxleft && left < boxright) //Is bird overlapping with the pipe
	{
		if (top > boxtop && bottom < boxbottom) return false; //Is bird inside the hole in the pipe
		else return true;
	}
	if (top < (float)topwall || bottom > 590.0f) return true; //Did bird hit the top or the bottom
	else return false;
}

void Flappy::UpdateScore(const SafeBox& safebox)
{
	if (highscore < score) highscore = score;
	if ((int)pos.x == (int)safebox.center.x && fScoreCD <= 0)
	{
		score++;
		fScoreCD = 0.3f;
	}
}
