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

	SDL_Rect rect = { 110, 110, 60, 40 };

	SDL_Rect projectile;
	projectile.h = 20;
	projectile.w = 30;

	bool isRunning = true;
	SDL_Event event;

	while (isRunning)
	{

		

		rect = { rect.x, rect.y, 60, 40 };
		

		while (SDL_PollEvent(&event))
		{
			if (event.type == SDL_QUIT)
			{
				isRunning = false;
			}
			if (event.type == SDL_KEYDOWN)
			{
				switch (event.key.keysym.sym)
				 {
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
				case SDLK_SPACE:
					projectile.x = rect.x + 60;
					projectile.y = rect.y + (rect.h / 2 - projectile.h / 2);
					break;
				}
			}
		}
		if (projectile.y <= 600) {
			projectile.x += 10;
		}


		SDL_SetRenderDrawColor(renderer, 0, 0, 255, 255);
		SDL_RenderClear(renderer);

		
		SDL_SetRenderDrawColor(renderer, 255, 0, 0, 255);
		SDL_RenderFillRect(renderer, &rect);

		SDL_SetRenderDrawColor(renderer, 0, 255, 0, 255);
		SDL_RenderFillRect(renderer, &projectile);
		SDL_RenderPresent(renderer);
		
	}
	SDL_DestroyRenderer(renderer);
	SDL_DestroyWindow(window);
	SDL_Quit();

	return 0;
}