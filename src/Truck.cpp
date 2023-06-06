#include "Truck.h"

#include <string>
#include <SDL_image.h>

int Truck::refCount = 0;
SDL_Texture * Truck::texture = 0;

Truck::Truck(SDL_Renderer * renderer, int x, int y, int speed)
{
  this->x = x;
  this->y = y;
  this->speed = speed;
  this->counter = 0;
  this->direction = 0;
  this->refCount++;
  if (!texture)
  {
    std::string path = "../../assets/truck_full.png";
    SDL_Surface* loadedSurface = IMG_Load( path.c_str() );
    if (loadedSurface==0)
    {
      printf("Couldn't load image %s\n", SDL_GetError());
      exit(1);
    }
    texture = SDL_CreateTextureFromSurface( renderer, loadedSurface );
    SDL_FreeSurface( loadedSurface );
  }
}

Truck::~Truck()
{
  if (this->refCount>1)
  {
    refCount--;
  }
  else if (this->refCount==1)
  {
    SDL_DestroyTexture(texture);
  }
}

void Truck::render(SDL_Renderer * renderer)
{
  SDL_Rect src = { direction * 32, counter * 32, 32, 32 };
  //SDL_Rect dest = { 320, 200, 32, 32 };
  
  SDL_SetRenderDrawColor(renderer, 96, 128, 255, 255);
  SDL_Rect dest = { (640 - 128)/2, (480 - 64)/2, 32, 32};
  SDL_RenderCopy( renderer, texture, &src, &dest );
}