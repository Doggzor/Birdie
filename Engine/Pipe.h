#pragma once
#include "Graphics.h"
class Pipe
{
public:
	Pipe(float x, const Color& c);
	Pipe() = default;
	void Draw(Graphics& gfx);
	void Update(float speed, float dt);

private:
	float x;
	float width = 100.0f;
	Color c;
};

