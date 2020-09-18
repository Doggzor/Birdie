/****************************************************************************************** 
 *	Chili DirectX Framework Version 16.07.20											  *	
 *	Game.cpp																			  *
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
#include "MainWindow.h"
#include "Game.h"

Game::Game( MainWindow& wnd )
	:
	wnd( wnd ),
	gfx( wnd ),
	flappy (Vec2(100.0f, (float)(gfx.ScreenHeight/2)), 275.0f, 750.0f, Colors::Magenta)
{
	for (int i = 0; i < nPipes; i++)
	{
		pipe[i] = { (float)gfx.ScreenWidth + (PipeWidth / 2.0f) + ((gap + PipeWidth) * i), Colors::Green };
		pipe[i].reset(top);
	}
}

void Game::Go()
{
	gfx.BeginFrame();
	float ElapsedTime = ft.Mark();
	while (ElapsedTime > 0.0f)
	{
		const float dt = std::min(0.0025f, ElapsedTime);
		UpdateModel(dt);
		ElapsedTime -= dt;
	}
	ComposeFrame();
	gfx.EndFrame();
}

void Game::UpdateModel(float dt)
{
	if (bGameStarted)
	{
		flappy.Update(wnd.kbd, wnd.mouse, dt);

		for (auto& p : pipe)
		{
			p.Update(WorldSpeed, dt);
			p.PushBack(gap, nPipes);
		}
	}
	else if (wnd.kbd.KeyIsPressed(VK_SPACE) || wnd.mouse.LeftIsPressed() && (!bMouse_LB_Inhibited && !bKBD_Space_Inhibited))
	{
		if (bGameOver)
		{
			flappy.reset();
			for (auto& p : pipe) p.reset(top);
			bGameOver = false;
		}
		else bGameStarted = true;
	}

	for (int i = 0; i < nPipes; i++)
	{
		if (flappy.bDead(pipe[i].GetSafeBox()))
		{
			bGameOver = true;
			bGameStarted = false;
		}
	}

	bMouse_LB_Inhibited = wnd.mouse.LeftIsPressed();
	bKBD_Space_Inhibited = wnd.kbd.KeyIsPressed(VK_SPACE);
}

void Game::ComposeFrame()
{
	gfx.DrawRect(0, top - 10, gfx.ScreenWidth, top, Colors::Green);
	gfx.DrawRect(0, gfx.ScreenHeight - 10, gfx.ScreenWidth, gfx.ScreenHeight, Colors::Green);
	for (auto& p : pipe) p.Draw(top, gfx);
	flappy.Draw(gfx);
}

