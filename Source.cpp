#include "SDL/include/SDL.h"
<<<<<<< HEAD
#include "SDL_Image/include/SDL_image.h"
#include "SDL_Mixer/include/SDL_mixer.h"

#pragma comment(lib,"SDL/libx86/SDL2.lib")
#pragma comment(lib,"SDL/libx86/SDL2main.lib")
#pragma comment(lib, "SDL_Image/libx86/SDL2_image.lib")
#pragma comment(lib, "SDL_Mixer/libx86/SDL2_mixer.lib")
=======
#include "SDL_Image\include\SDL_image.h"

#pragma comment(lib, "SDL/libx86/SDL2.lib")
#pragma comment(lib, "SDL/libx86/SDL2main.lib")

#pragma comment(lib, "SDL_Image/libx86/SDL2_image.lib")

>>>>>>> 7a8c83f9e7ae007044f6c3e672254abe460df2f2

const int SCREEN_WIDTH = 640;
const int SCREEN_HEIGHT = 360;


int main(int argc, char* argv[])
{
<<<<<<< HEAD

	SDL_Window* window = nullptr;
	SDL_Renderer* renderer = nullptr;
	SDL_Surface* surface = nullptr;
	SDL_Texture* bg = nullptr;
	SDL_Texture* projectile_ = nullptr;
	SDL_Texture* ship = nullptr;
	Mix_Music* music = nullptr;
	Mix_Chunk* laser = nullptr;

	SDL_Init(SDL_INIT_VIDEO);
	SDL_Init(SDL_INIT_AUDIO);
=======
	
	SDL_Init(SDL_INIT_VIDEO);
>>>>>>> 7a8c83f9e7ae007044f6c3e672254abe460df2f2
	IMG_Init(IMG_INIT_PNG | IMG_INIT_JPG);

	window = SDL_CreateWindow("SDL_Rectangle", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED,
	SCREEN_WIDTH, SCREEN_HEIGHT, SDL_WINDOW_RESIZABLE);

<<<<<<< HEAD
	renderer = SDL_CreateRenderer(window, -1, SDL_RENDERER_ACCELERATED | SDL_RENDERER_PRESENTVSYNC);

	surface = IMG_Load("Assets/bg.png");
	bg = SDL_CreateTextureFromSurface(renderer, surface);

	surface = IMG_Load("Assets/ship.png");
	ship = SDL_CreateTextureFromSurface(renderer, surface);

	surface = IMG_Load("Assets/laser3.png");
	projectile_ = SDL_CreateTextureFromSurface(renderer, surface);

	SDL_FreeSurface(surface);

	SDL_Rect rect;
	rect.x = SCREEN_WIDTH / 2;
	rect.y = SCREEN_HEIGHT / 2;
	rect.w = 75;
	rect.h = 75;
	//04_Into_the_Human_Body_Stage_1_
	SDL_Rect projectile;
	projectile.w = 60;
	projectile.h = 45;
	projectile.x = 0;
	projectile.y = 0;


	SDL_Event event;
	bool isRunning = true;
	bool left = false;
	bool right = false;
	bool up = false;
	bool down = false;
	bool space = false;

	//sound = Mix_LoadWAV("Assets/xmultipl-114.wav");
	laser = Mix_LoadWAV("Assets/xmultipl-115.wav");
	music = Mix_LoadMUS("Assets/04_Into_the_Human_Body_Stage_1_.ogg");


	Mix_PlayMusic(music, -1);
	while (isRunning == true)
	{
		SDL_PollEvent(&event);

		switch (event.type) {
		case SDL_QUIT:
			isRunning = false;
			break;

		case SDL_KEYDOWN:
			switch (event.key.keysym.sym) {
			case SDLK_UP:
				up = true;
				break;
			case SDLK_DOWN:
				down = true;
				break;
			case SDLK_RIGHT:
				right = true;
				break;
			case SDLK_LEFT:
				left = true;
				break;
			case SDLK_SPACE:
				space = true;
				break;
			}
			break;


		case SDL_KEYUP:
			switch (event.key.keysym.sym) {
			case SDLK_UP:
				up = false;
				break;
			case SDLK_DOWN:
				down = false;
				break;
			case SDLK_RIGHT:
				right = false;
				break;
			case SDLK_LEFT:
				left = false;
				break;
			case SDLK_SPACE:
				space = false;
				break;
			}
			break;
		}
		if (up && rect.y != 0) rect.y -= 2;
		if (down && rect.y != (SCREEN_HEIGHT - 50)) rect.y += 2;
		if (left  && rect.x != 0) rect.x -= 2;
		if (right && rect.x != (SCREEN_WIDTH - 50)) rect.x += 2;
		if (space) {
			Mix_PlayChannel(-1, laser, 0);
			projectile.x = rect.x + 60;
			projectile.y = rect.y + (rect.h/2) - (projectile.h/2);
		}

		if (projectile.x < SCREEN_WIDTH - 30)
		projectile.x += 10;

		SDL_RenderClear(renderer);

		SDL_RenderCopy(renderer, bg, 0, 0);

		SDL_RenderCopyEx(renderer, projectile_, 0, &projectile, 0, 0, SDL_FLIP_NONE);

		SDL_RenderCopyEx(renderer, ship, 0, &rect, 0, 0, SDL_FLIP_NONE);

		SDL_RenderPresent(renderer);


=======
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
>>>>>>> 7a8c83f9e7ae007044f6c3e672254abe460df2f2
	}

	//Destroy resources
	SDL_DestroyRenderer(renderer);
	SDL_DestroyWindow(window);
<<<<<<< HEAD
	Mix_FreeChunk(laser);
	Mix_FreeMusic(music);
=======
>>>>>>> 7a8c83f9e7ae007044f6c3e672254abe460df2f2
	IMG_Quit();
	SDL_Quit();
	Mix_CloseAudio();

	return 0;
}