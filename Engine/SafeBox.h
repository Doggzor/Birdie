#pragma once
#include "Vec2.h"
#include "Graphics.h"
struct SafeBox
{
public:
	SafeBox() = default;
	SafeBox(Vec2& center, float width);
	void Draw(Graphics& gfx);
	Vec2 center;
	float width;
	static constexpr float height = 160.0f;
};

