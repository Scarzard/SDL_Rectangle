#include "SDL/include/SDL.h"
#include <cstdbool>
#pragma comment(lib, "SDL/libx86/SDL2.lib")
#pragma comment(lib, "SDL/libx86/SDL2main.lib")


int main(int arfc, char* argv[])
{
	SDL_Init(SDL_INIT_VIDEO);

	SDL_Window *window = SDL_CreateWindow("Rectangle", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED,
		600, 400, SDL_WINDOW_OPENGL);

	SDL_Renderer *renderer = SDL_CreateRenderer(window, -1, SDL_RENDERER_ACCELERATED |
		SDL_RENDERER_PRESENTVSYNC);

	SDL_SetRenderDrawColor(renderer, 255, 0, 0, 255);
	SDL_Rect rect = { 110, 110, 60, 40 };

	int x = 0;
	int y = 0;

	bool isRunning = true;
	SDL_Event event;

	while (isRunning)
	{
		
		

		SDL_SetRenderDrawColor(renderer, 0, 0, 255, 255);

		SDL_RenderClear(renderer);
		
		SDL_RenderFillRect(renderer, &rect);

	/*	if (x == 0 && rect.x <= 540) rect.x += 2;
		else x = 1;

		if (x == 1 && rect.x >= 0) rect.x -= 2;
		else x = 0;

		if (y == 0 && rect.y <= 360) rect.y += 2;
		else y = 1;

		if (y == 1 && rect.y >= 0) rect.y -= 2;
		else y = 0;
		*/

		rect = { rect.x, rect.y, 60, 40 };
		SDL_SetRenderDrawColor(renderer, 255, 0, 0, 255);
		SDL_RenderFillRect(renderer, &rect);
		SDL_RenderPresent(renderer);

		while (SDL_PollEvent(&event))
		{
			if (event.type == SDL_QUIT)
			{
				isRunning = false;
			}
			switch (event.type)
			{
			case SDL_KEYDOWN:
				switch (event.key.keysym.sym) {
				case SDLK_LEFT:
					rect.x -= 10;
					break;
				case SDLK_RIGHT:
					rect.x += 10;
					break;
				case SDLK_UP:
					rect.y -= 10;
					break;
				case SDLK_DOWN:
					rect.y += 10;
					break;
				}
			}
		}
	}

	SDL_DestroyRenderer(renderer);
	SDL_DestroyWindow(window);
	SDL_Quit();

	return 0;
}