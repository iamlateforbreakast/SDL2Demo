#include "Game.h"

int main(int argc, char * argv[])
{
  Game game;
  
  game.start();
  
  while (game.isRunning())
  {
    game.readUserInputs();
    game.wait();
  }
  
  game.complete();

  return 0;
}
