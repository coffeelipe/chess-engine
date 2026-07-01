#include "sdl_manager.hpp"
#include "sdl_fwd.hpp"
#include "board.hpp"

class Game
{
public:
    int run();

private:
    bool init();
    void handleEvent(const SDL_Event &event);
    void onQuit();
    void render(SDL_Window *window, SDL_Renderer *renderer);

    bool isRunning = true;
    SDLManager sdl;
    Board board;
};
