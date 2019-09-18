#include <iostream>
#include "WindowManager.h"
using namespace std;

int main()
{
	Window window;
	SDL_Init(SDL_INIT_VIDEO);
	window.window(960, 600);
	while (window.Work())
	{
		window.pollevent();
	}
	system("pause");
	SDL_Quit();
	return 0;
}