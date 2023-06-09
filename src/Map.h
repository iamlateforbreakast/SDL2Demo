// Map.h
#include <SDL.h>
#include <SDL_image.h>

class Map
{
  public:
    Map(SDL_Renderer * renderer);
    ~Map();
    void render(SDL_Renderer * renderer);
  private:
    static SDL_Texture * texture;
    static int width;
    static int height;
};
