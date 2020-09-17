#include "SafeBox.h"

SafeBox::SafeBox(Vec2& center, float width)
	:
	center (center),
	width (width)
{
}

void SafeBox::Draw(Graphics& gfx)
{
	gfx.DrawRect(center, width, height, Colors::Black);
}

