#include "sdl_manager.hpp"
#include "sdl_fwd.hpp"
#include "board.hpp"
#include "renderer.hpp"

class Game
{
public:
    int run();

private:
    bool init();
    void handleEvent(AppEvent event);

    // Event handlers:
    void onQuit();

    SDLManager sdl;
    Renderer renderer;
    Board board;
    bool isRunning = true;
};
