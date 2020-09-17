#pragma once
#include "Graphics.h"
#include "SafeBox.h"
#include "rng.h"
class Pipe
{
public:
	Pipe(float x, const Color& c);
	Pipe() = default;
	void Draw(Graphics& gfx);
	void Update(float speed, float dt);
	void PushBack(float gap, int nPipes);
	float GetX();
	float GetWidth();

private:
	float x;
	float width = 100.0f;
	Color c;
	SafeBox safebox;
};

