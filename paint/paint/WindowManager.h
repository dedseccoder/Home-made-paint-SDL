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
		render = SDL_CreateRenderer(MainWindow, -1, 0);
		MainWindow = SDL_CreateWindow("Home made paint" , SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, width, height, 0);
		if (MainWindow == NULL)
		{
			// In the case that the window could not be made...
			cout << "Could not create window: " << SDL_GetError() << endl;
			SDL_DestroyWindow(MainWindow);
			SDL_Quit();
			return;
		}
	}
	bool Work()
	{
		return work;
	}
	void pollevent()
	{
		SDL_Delay;
		if (SDL_PollEvent(event))
		{
			switch (event->type)
			{
			case SDL_QUIT:
				work = false;
				SDL_DestroyWindow(MainWindow);
				break;
			default:
				break;
			}
		}
		/*SDL_SetWindowPosition(MainWindow, SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED);*/
		cout << "SDL_Delay" << endl;
	}
private:
	bool work = true;
	int width;
	int height;
	SDL_Window * MainWindow;
	SDL_Renderer * render;
	SDL_Event* event;
};