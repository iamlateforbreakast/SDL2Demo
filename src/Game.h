// Game.h
#ifndef _GAME_
#define _GAME_

#include <SDL.h>

class Game
{
  public:
    Game();
    ~Game();
    void start();
    bool isRunning();
    void readUserInput();
    void wait();
    void complete();
  private:
    SDL_Renderer * renderer;
    SDL_Window * window;
    void initSDL();
};

#endif // _GAME_
