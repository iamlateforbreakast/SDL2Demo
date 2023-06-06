#ifndef _TRUCK_
#define _TRUCK_
// Truck.h

#include <SDL.h>

class Truck
{
  public:
    Truck(SDL_Renderer * renderer, int x, int y, int speed);
    ~Truck();
    void render(SDL_Renderer * renderer);
    void move();
    void setDirection(int direction);
  private:
    int x;
    int y;
    int speed;
    int direction;
    int counter;
    int speedCounter;
    static int refCount;
    static SDL_Texture * texture;
};
#endif // _TRUCK_