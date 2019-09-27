#pragma once
#define SDL_MAIN_HANDLED
#include <SDL.h>
#include <SDL_events.h>
#include <conio.h>
#include <iostream>

using namespace std;

class Window
{
public:
	void window(int w, int h)
	{
		width = w;
		height = h;
		//creating window
		MainWindow = SDL_CreateWindow("Home made paint" , SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, width, height, 0);
		if (MainWindow == NULL)
		{
			// In the case that the window could not be made...
			cout << "Could not create window: " << SDL_GetError() << endl;
			SDL_DestroyWindow(MainWindow);
			SDL_Quit();
			return;
		}
		//creating render to use it in future
		render = SDL_CreateRenderer(MainWindow, -1, 0);
		//set backgrong color
		SDL_SetRenderDrawColor(render, 255, 255, 255, 1);
		// Clear the entire screen to our selected color.
		SDL_RenderClear(render);
	}
	void pollevent()
	{
		while (SDL_PollEvent(&event))
		{
			if (event.type == SDL_QUIT)
			{
				work = false;
				SDL_DestroyWindow(MainWindow);
				SDL_DestroyRenderer(render);
			}
			if (event.type == SDL_MOUSEMOTION)
			{
				SDL_GetMouseState(&xMOUSE, &yMOUSE);
				cout << "x = " << xMOUSE << "\t" << "y = " << yMOUSE << endl;
			}
			if (event.button.button == SDL_BUTTON_LEFT)
			{
				SDL_RenderClear(render);
				SDL_SetRenderDrawColor(render, 0, 191, 255, 1);
				SDL_RenderDrawPoint(render, xMOUSE, yMOUSE);
				SDL_RenderPresent(render);
			}
			if (event.button.button == SDL_BUTTON_RIGHT)
			{
				SDL_RenderClear(render);
				SDL_SetRenderDrawColor(render, 255, 255, 255, 1);
				SDL_RenderDrawPoint(render, xMOUSE, yMOUSE);
				SDL_RenderPresent(render);
			}
		}
		SDL_RenderPresent(render);
		SDL_Delay(1);
	}

	bool Work()
	{
		return work;
	}
	private:
		SDL_Event event;
		SDL_Window* MainWindow;
		SDL_Renderer* render;
		int x, y;
		int xMOUSE, yMOUSE;
		bool work = true;
		int width;
		int height;
};