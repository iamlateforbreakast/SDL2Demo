// Game.h
#ifndef _GAME_
#define _GAME_

#include <SDL.h>

#include "Truck.h"

class Game
{
  public:
    Game();
    ~Game();
    void start();
    bool getIsRunning();
    void readUserInput();
    void wait();
    void complete();
  private:
    SDL_Renderer * renderer;
    SDL_Window * window;
    SDL_Texture * texture;
    int screen_width;
    int screen_height;
    bool isRunning;
    Truck * truck;
    void initSDL();
};

#endif // _GAME_
