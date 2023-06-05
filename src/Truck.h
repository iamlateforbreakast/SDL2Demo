#ifndef _TRUCK_
#define _TRUCK_
// Truck.h

#include <SDL.h>

class Truck
{
  public:
    Truck(SDL_Renderer * renderer, int x, int y, int speed);
    ~Truck();
    SDL_Texture * getTexture();
  private:
    int x;
    int y;
    int speed;
    SDL_Texture * texture;
};
#endif // _TRUCK_