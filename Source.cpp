#include "SDL/include/SDL.h"
#include "SDL_Image/include/SDL_image.h"
#include "SDL_Mixer/include/SDL_mixer.h"

#pragma comment(lib,"SDL/libx86/SDL2.lib")
#pragma comment(lib,"SDL/libx86/SDL2main.lib")
#pragma comment(lib, "SDL_Image/libx86/SDL2_image.lib")
#pragma comment(lib, "SDL_Mixer/libx86/SDL2_mixer.lib")

const int SCREEN_WIDTH = 640;
const int SCREEN_HEIGHT = 360;


int main(int argc, char* argv[])
{

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
	IMG_Init(IMG_INIT_PNG | IMG_INIT_JPG);

	window = SDL_CreateWindow("SDL_Rectangle", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED,
	SCREEN_WIDTH, SCREEN_HEIGHT, SDL_WINDOW_RESIZABLE);

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


	}

	//Destroy resources
	SDL_DestroyRenderer(renderer);
	SDL_DestroyWindow(window);
	Mix_FreeChunk(laser);
	Mix_FreeMusic(music);
	IMG_Quit();
	SDL_Quit();
	Mix_CloseAudio();

	return 0;
}