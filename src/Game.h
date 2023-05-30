// Game.h

#include <SDL2.h>

class Game
{
  public:
    Game();
    ~Game();
    void start();
    bool isRunning();
    void readUserInput();
    void complete();
  private:
    SDL_Renderer * renderer;
    SDL_Window * window;
    void initSDL();
};
