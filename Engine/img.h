#pragma once
#include "Graphics.h"
class img
{
public:
	//size: 110x25
	static void score(int x, int y, Graphics& gfx);
	//size: 190x25
	static void hscore(int x, int y, Graphics& gfx);
	//size: 60x30
	static void BirdFly(int x, int y, Graphics& gfx);
	//size: 60x30
	static void BirdFlap(int x, int y, Graphics& gfx);
};

