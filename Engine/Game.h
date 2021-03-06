/****************************************************************************************** 
 *	Chili DirectX Framework Version 16.07.20											  *	
 *	Game.h																				  *
 *	Copyright 2016 PlanetChili.net <http://www.planetchili.net>							  *
 *																						  *
 *	This file is part of The Chili DirectX Framework.									  *
 *																						  *
 *	The Chili DirectX Framework is free software: you can redistribute it and/or modify	  *
 *	it under the terms of the GNU General Public License as published by				  *
 *	the Free Software Foundation, either version 3 of the License, or					  *
 *	(at your option) any later version.													  *
 *																						  *
 *	The Chili DirectX Framework is distributed in the hope that it will be useful,		  *
 *	but WITHOUT ANY WARRANTY; without even the implied warranty of						  *
 *	MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the						  *
 *	GNU General Public License for more details.										  *
 *																						  *
 *	You should have received a copy of the GNU General Public License					  *
 *	along with The Chili DirectX Framework.  If not, see <http://www.gnu.org/licenses/>.  *
 ******************************************************************************************/
#pragma once

#include "Keyboard.h"
#include "Mouse.h"
#include "Graphics.h"
#include "Numbers.h"
#include "rng.h"
#include "FrameTimer.h"
#include "Vec2.h"
#include "Flappy.h"
#include "Pipe.h"
#include "img.h"

class Game
{
public:
	Game( class MainWindow& wnd );
	Game( const Game& ) = delete;
	Game& operator=( const Game& ) = delete;
	void Go();
private:
	void ComposeFrame();
	void UpdateModel(float dt);
	/********************************/
	/*  User Functions              */
	/********************************/
private:
	MainWindow& wnd;
	Graphics gfx;
	/********************************/
	/*  User Variables              */
    FrameTimer ft;
	Numbers numb;
	/********************************/
	bool bGameStarted = false;
	bool bGameOver = false;
	float WorldSpeed = 180.0f; //How fast is the wolr around flappy moving
	static constexpr int top = 60;

	Flappy flappy;

	static constexpr int nPipes = 10;
	Pipe pipe[nPipes];
	float gap = 150.0f;
	float PipeWidth = 100.0f;



	bool bMouse_LB_Inhibited = false;
	bool bKBD_Space_Inhibited = false;
};