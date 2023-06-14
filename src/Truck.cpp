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
  this->speedCounter = 0;
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

void Truck::setDirection(int direction)
{
  this->direction = direction;
}

void Truck::move()
{
  this->speedCounter = (this->speedCounter + 1) % this->speed;
  if (this->speedCounter!=0) return;
  switch (this->direction)
  {
    case 2:
      if (this->y<480-32) this->y++;
      this->counter = (this->counter + 1) % 10;
      break;
    case 1:
      if (this->x>0) this->x--;
      this->counter = (this->counter + 1) % 10;
      break;
    case 8:
      if (this->y>0) this->y--;
      this->counter = (this->counter + 1) % 10;
      break;
    case 4:
      if (this->x<640-32) this->x++;
      this->counter = (this->counter + 1) % 10;
      break;
    default:
      break;
  }
}

void Truck::render(SDL_Renderer * renderer)
{
  int frame = 0;
  if ((counter == 4) || (counter == 9)) frame = 1;
  SDL_Rect src = { direction * 32, frame * 32, 32, 32 };
  //SDL_Rect dest = { 320, 200, 32, 32 };
  
  SDL_SetRenderDrawColor(renderer, 96, 128, 255, 255);
  SDL_Rect dest = { x, y, 32, 32};
  SDL_RenderCopy( renderer, texture, &src, &dest );
}