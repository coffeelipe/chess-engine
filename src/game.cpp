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
