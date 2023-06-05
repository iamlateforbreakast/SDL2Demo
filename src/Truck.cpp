#include "Truck.h"

#include <string>
#include <SDL_image.h>

Truck::Truck(SDL_Renderer * renderer, int x, int y, int speed)
{
  this->x = x;
  this->y = y;
  this->speed = speed;
  if (!texture)
  {
    std::string path = "../../assets/star.png";
    SDL_Surface* loadedSurface = IMG_Load( path.c_str() );
    texture = SDL_CreateTextureFromSurface( renderer, loadedSurface );
    SDL_FreeSurface( loadedSurface );
  }
}

Truck::~Truck()
{

}

SDL_Texture * getTexture()
{
  return 0;
}