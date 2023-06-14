#include "Map.h"
#include <SDL.h>
#include <SDL_image.h>
#include <string>

const int grid[15][20] = { 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 
                          0, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 0, 
                          0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 
                          0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 
                          0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0,
                          0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0,
                          0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0,
                          0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0,
                          0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0,
                          0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0,
                          0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0,
                          0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0,
                          0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0,
                          0, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 0,
                          0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 };

SDL_Texture * Map::texture = 0;
int Map::width = 20;
int Map::height=15;
int Map::spawnx = 1;
int Map::spawny = 1;

Map::Map(SDL_Renderer * renderer)
{
  if (!texture)
  {
    std::string path = "../../assets/road.png";
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

Map::~Map()
{
  if (texture) SDL_DestroyTexture(texture);
}

void Map::render(SDL_Renderer * renderer)
{

  for (int i=0; i<width; i++)
    for (int j=0; j<height; j++)
    {
      SDL_Rect src;
      getTexture(i,j,src);
      SDL_Rect dest = { i * 32, j * 32, 32, 32 };
      SDL_RenderCopy( renderer, texture, &src, &dest );
    }
}

void Map::getSpawn(int & i, int & j)
{
  i = Map::spawnx;
  j = Map::spawny;  
}

int Map::getDirections(int i, int j)
{
  int c = 0;
  
  if (i>0) c = c + grid[j][i-1] * 8;
  if (i<width-1) c = c + grid[j][i+1] * 2;
  if (j>0) c = c + grid[j-1][i];
  if (j<height) c = c + grid[j+1][i] * 4;

  return c;
}

void Map::getTexture(int i, int j, SDL_Rect & coord)
{
  int c = getDirections(i,j);

  coord = {0, 64, 32, 32};
  if (grid[j][i])
  {
    if (c==10) coord = {32, 0, 32, 32};
    if (c==5) coord = {0, 0, 32, 32};
    if (c==6) coord = {96, 32, 32, 32};
    if (c==3) coord = {0, 32, 32, 32};
    if (c==12) coord = {64, 32, 32, 32};
    if (c==9) coord = {32, 32, 32, 32};
  }
}

//int Map::getDirection(int x, int y, int direction)
//{
//  int result =0;

//  return 0;
//}