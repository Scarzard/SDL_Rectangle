#include "SDL/include/SDL.h"
#include "SDL_Image\include\SDL_image.h"

#pragma comment(lib, "SDL/libx86/SDL2.lib")
#pragma comment(lib, "SDL/libx86/SDL2main.lib")

#pragma comment(lib, "SDL_Image/libx86/SDL2_image.lib")


int main(int arfc, char* argv[])
{
	
	SDL_Init(SDL_INIT_VIDEO);
	IMG_Init(IMG_INIT_PNG | IMG_INIT_JPG);

	SDL_Window *window = SDL_CreateWindow("Rectangle", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED,
		600, 400, SDL_WINDOW_OPENGL);

	SDL_Renderer *renderer = SDL_CreateRenderer(window, -1, SDL_RENDERER_ACCELERATED);
	SDL_Texture * texture;
	SDL_Surface * surface = IMG_Load("ship.png");

	SDL_Rect rect = { 110, 110, 60, 40 };

	SDL_Rect projectile;
	projectile.h = 20;
	projectile.w = 30;

	bool isRunning = true;
	bool LKey = false;
	bool RKey = false;
	bool UKey = false;
	bool DKey = false;

	float v = 0.1;

	SDL_Event event;
	//Game Loop
	while (isRunning)
	{
		//rect = { rect.x, rect.y, 60, 40 };

		//Events: Player movement
		while (SDL_PollEvent(&event))
		{
			if (event.type == SDL_QUIT)
			{
				isRunning = false;
			}
			else if (event.type == SDL_KEYDOWN)
			{
				switch (event.key.keysym.sym)
				{
				case SDLK_LEFT:
					LKey = true;
					break;
				case SDLK_RIGHT:
					RKey = true;
					break;
				case SDLK_UP:
					UKey = true;
					break;
				case SDLK_DOWN:
					DKey = true;
					break;
				}
			}

		    else if (event.type == SDL_KEYUP)
			{
				switch (event.key.keysym.sym)
				{
				case SDLK_LEFT:
					LKey = false;
					break;
				case SDLK_RIGHT:
					RKey = false;
					break;
				case SDLK_UP:
					UKey = false;
					break;
				case SDLK_DOWN:
					DKey = false;
					break;
				case SDLK_SPACE:
					break;
				}
			}

			
			

		}
		//Velocity of movement
		if (LKey == true) rect.x -= v;
		if (RKey == true) rect.x += v;
		if (UKey == true) rect.y -= v;
		if (DKey == true) rect.y += v;

		//Limits of movement

		if (rect.x > 540) rect.x = 540;

		else if (rect.x < 0) rect.x = 0;

		if (rect.y > 360) rect.y = 360;

		else if (rect.y < 0) rect.y = 0;
		
		//Renderers
		SDL_SetRenderDrawColor(renderer, 0, 0, 255, 255);
		SDL_RenderClear(renderer);


		SDL_SetRenderDrawColor(renderer, 255, 0, 0, 255);
		SDL_RenderFillRect(renderer, &rect);

		SDL_SetRenderDrawColor(renderer, 0, 255, 0, 255);
		SDL_RenderFillRect(renderer, &projectile);
		SDL_RenderPresent(renderer);
	}

	//Destroy resources
	SDL_DestroyRenderer(renderer);
	SDL_DestroyWindow(window);
	IMG_Quit();
	SDL_Quit();

	return 0;
}