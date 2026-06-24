#include "common.hpp"
#include "sdl_fwd.hpp"

class SDLManager
{
public:
    bool init();
    SDL_Window *getWindow();
    SDL_Renderer *getRenderer();

    void drawBoard();
    void drawPieces(U64 position);
    void clear();

private:
    SDL_Window *window;
    SDL_Renderer *renderer;
};
