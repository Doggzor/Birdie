#pragma once
#include "Graphics.h"
#include "SafeBox.h"
#include "rng.h"
class Pipe
{
public:
	Pipe(float x, const Color& c);
	Pipe() = default;
	void Draw(int top, Graphics& gfx);
	void Update(float speed, float dt);
	void reset(int top);
	void PushBack(float gap, int nPipes);
	float GetX();
	float GetWidth();
	const SafeBox& GetSafeBox() const;

private:
	float x;
	float x_start;
	float width = 100.0f;
	Color c;
	Color c_start;
	SafeBox safebox;
};

