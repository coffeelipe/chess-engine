#include "game.hpp"
#include "common.hpp"

int Game::run()
{
    if (!init())
    {
        std::cout << "Failed to initialize game, exiting...\n";
        sdl.clear();
        return 1;
    }

    AppEvent event{};
    int counter = 0;
    while (isRunning)
    {
        if (!sdl.waitEvent(event))
            continue;
        handleEvent(event);
    }

    return 0;
}

bool Game::init()
{
    std::cout << "Chess Engine starting...\n";
    board.print_board();
    if (!sdl.init())
    {
        return false;
    }
    renderer.setRenderer(sdl.getRenderer());
    if (!renderer.loadPieceTextures())
    {
        renderer.destroyTextures();
        return false;
    }
    renderer.drawBoard();

    renderer.renderPresent();
    return true;
}

void Game::handleEvent(const AppEvent event)
{
    switch (event.type)
    {
    case AppEventType::CHESS_QUIT:
        onQuit();
        break;

    default:
        break;
    }
}

void Game::onQuit()
{
    renderer.destroyTextures();
    sdl.clear();
    isRunning = false;
}
