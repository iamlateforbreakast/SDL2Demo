#include "Game.h"

Game::Game()
{
}

Game::~Game()
{
}

void Game::start()
{
}
  
bool Game::getIsRunning()
{
  return isRunning;
}

void Game::readUserInput()
{
  SDL_Event event;

	SDL_PollEvent(&event);
	
  isRunning = true;

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
  SDL_SetRenderDrawColor(renderer, 96, 128, 255, 255);
  SDL_RenderClear(renderer);
  SDL_RenderPresent(renderer);
}

