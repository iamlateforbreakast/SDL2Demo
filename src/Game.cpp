#include "Game.h"
#include "Truck.h"

#include <SDL_image.h>

#include <string>

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
  SDL_Delay(10);
}

/*
  @brief Complete all game activities and prepare to close application
  @param none
  @return none
*/
void Game::complete()
{
  SDL_DestroyTexture(texture);
  SDL_DestroyRenderer(renderer);
  SDL_DestroyWindow(window);
  IMG_Quit();
  SDL_Quit();
}

/*
  @brief Initialises SDL window/images ressources
  @param none
  @return none
*/
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
  if( !( IMG_Init( imgFlags ) & imgFlags ) ) 
  {
    printf("Couldn't initialize image: %s\n", SDL_GetError());
    exit(1);
  }

  // std::string path = "../../assets/truck_full.png";
  // SDL_Surface* loadedSurface = IMG_Load( path.c_str() );
  // texture = SDL_CreateTextureFromSurface( renderer, loadedSurface );
  // SDL_FreeSurface( loadedSurface );
  // SDL_SetRenderDrawColor(renderer, 96, 128, 255, 255);
  // SDL_Rect dest = { (screen_width - 128)/2, (screen_height - 64)/2, 128, 64};
  SDL_SetRenderDrawColor(renderer, 96, 128, 255, 255);
  Truck * truck = new Truck(renderer, 10, 10, 0);
  truck->render(renderer);

  //SDL_RenderCopy( renderer, texture, NULL, &dest );
  SDL_RenderPresent(renderer);
}

