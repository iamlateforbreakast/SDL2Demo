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
      if (grid[j][i]==1)
      {
        SDL_Rect src = { 0, 0, 32, 32 };
        SDL_Rect dest = { i * 32, j * 32, 32, 32 };
        SDL_RenderCopy( renderer, texture, &src, &dest );
      }
    }
}

//void Map::getDirection(int x, int y, int direction)
//{
//
//}