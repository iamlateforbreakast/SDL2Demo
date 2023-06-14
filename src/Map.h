// Map.h
#include <SDL.h>
#include <SDL_image.h>

class Map
{
  public:
    Map(SDL_Renderer * renderer);
    ~Map();
    void render(SDL_Renderer * renderer);
    void getSpawn(int & i, int & j);
    void getTexture(int i, int j, SDL_Rect & coord);
    int getDirections(int i, int j);
  private:
    static SDL_Texture * texture;
    static int width;
    static int height;
    static int spawnx;
    static int spawny;
};
