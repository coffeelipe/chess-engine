#include "game.hpp"

#include <SDL3/SDL.h>
#include <iostream>

void Game::run()
{
    if (!init())
    {
        std::cout << "Failed to initialize game, exiting...";
        onQuit();
    }
    else
    {
        SDL_Event event;
        while (isRunning)
        {
            SDL_WaitEvent(&event);
            handleEvent(event);
        }
    }
}

bool Game::init()
{
    std::cout << "Chess Engine starting...";
    board.print_board();
    if (!sdl.init())
    {
        return false;
    }
    sdl.drawBoard();
    render(sdl.getWindow(), sdl.getRenderer());
    return true;
}

void Game::render(SDL_Window *window, SDL_Renderer *renderer)
{
    SDL_RenderPresent(renderer);
}

void Game::handleEvent(const SDL_Event &event)
{
    switch (event.type)
    {
    case SDL_EVENT_QUIT:
        onQuit();
        break;

    default:
        break;
    }
}

void Game::onQuit()
{
    sdl.clear();
    isRunning = false;
}
