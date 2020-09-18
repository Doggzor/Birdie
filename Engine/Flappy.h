#pragma once
#include "Graphics.h"
#include "Vec2.h"
#include "Keyboard.h"
#include "Mouse.h"
#include "SafeBox.h"
class Flappy
{
public:
	Flappy(const Vec2& pos, float speedMax, float grav, const Color& color);
	void Draw(Graphics& gfx);
	void Update(Keyboard& kbd, Mouse& mouse, float dt);
	void reset();
	bool bDead(const SafeBox& safebox, int topwall);
	void UpdateScore(const SafeBox& safebox);
	int score = 0;
	int highscore = 0;

private:
	Vec2 pos;
	static constexpr float width = 60.0f;
	static constexpr float height = 30.0f;
	float MaxSpeed;
	float speed = 0;
	float grav;
	Color c;
	Vec2 pos_start;
	Color c_start;

	bool bMouse_LB_Inhibited = false;
	bool bKBD_Space_Inhibited = false;
	float fScoreCD = 0;
};

