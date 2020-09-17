#pragma once
#include "Graphics.h"
#include "Vec2.h"
#include "Keyboard.h"
#include "Mouse.h"
class Flappy
{
public:
	Flappy(const Vec2& pos, float speedMax, float grav, const Color& color);
	void Draw(Graphics& gfx);
	void Update(Keyboard& kbd, Mouse& mouse, float dt);

private:
	Vec2 pos;
	static constexpr float width = 80.0f;
	static constexpr float height = 30.0f;
	float MaxSpeed;
	float speed = 0;
	float grav;
	Color c;

	bool bMouse_LB_Inhibited = false;
	bool bKBD_Space_Inhibited = false;
};

