#include "Game.h"
#include <SDL_image.h>

Game::Game()
{
  renderer = nullptr;
  window = nullptr;
  texture = nullptr;
  isRunning = false;
  screen_width = 640;
  screen_height = 480;
}

Game::~Game()
{
}

void Game::start()
{
  initSDL();
  isRunning = true;
}
  
bool Game::getIsRunning()
{
  return isRunning;
}

void Game::readUserInput()
{
  SDL_Event event;

	SDL_PollEvent(&event);

	switch (event.type)
	{
		case SDL_QUIT:
			isRunning = false;
			break;

	  default:
			break;
	}
}

void Game::wait()
{
}

void Game::complete()
{
  SDL_DestroyWindow(window);
  // SDL_FreeSurface(image_surface);
  SDL_Quit();
}

void Game::initSDL()
{
  int rendererFlags = SDL_RENDERER_ACCELERATED;
  int windowFlags = 0;

  screen_width = 640;
  screen_height = 480;
  
  if (SDL_Init(SDL_INIT_VIDEO) < 0)
  {
    printf("Couldn't initialize SDL: %s\n", SDL_GetError());
    exit(1);
  }
  window = SDL_CreateWindow("SDL2Demo", SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, 
                            screen_width, screen_height, windowFlags);
  if (window==0)
  {
    printf("Couldn't initialize window: %s\n", SDL_GetError());
    exit(1);
  }
  renderer = SDL_CreateRenderer(window, -1, rendererFlags);
  
  if (renderer==0)
  {
    printf("Couldn't initialize renderer: %s\n", SDL_GetError());
    exit(1);
  }

  int imgFlags = IMG_INIT_PNG;
  if( !( IMG_Init( imgFlags ) & imgFlags ) ) {}
  //SDL_Surface* loadedSurface = IMG_Load( path.c_str() );
  //newTexture = SDL_CreateTextureFromSurface( gRenderer, loadedSurface );
  //SDL_FreeSurface( loadedSurface );
  SDL_SetRenderDrawColor(renderer, 96, 128, 255, 255);
  SDL_RenderClear(renderer);
  // window_surface = SDL_GetWindowSurface(window);
  // image_surface = SDL_LoadBMP("image.bmp");
  // SDL_BlitSurface(image_surface, NULL, window_surface, NULL);
  // SDL_UpdateWindowSurface(window);
  SDL_RenderPresent(renderer);
}

