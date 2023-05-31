#include "Game.h"

int main(int argc, char * argv[])
{
  Game game;
  
  game.start();
  
  while (game.isRunning())
  {
    game.readUserInput();
    game.wait();
  }
  
  game.complete();

  return 0;
}
