#pragma once
#include "Graphics.h"
#include "Vec2.h"
class Flappy
{
public:
	Flappy(const Vec2& pos, float speed, float grav, const Color& color);
	void Draw(Graphics& gfx);

private:
	Vec2 pos;
	static constexpr float width = 80.0f;
	static constexpr float height = 30.0f;
	float speed;
	float grav;
	Color c;
};

