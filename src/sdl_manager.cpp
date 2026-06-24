#include "common.hpp"
#include "sdl_manager.hpp"
#include <SDL3/SDL.h>

SDL_Window *SDLManager::getWindow() { return window; }
SDL_Renderer *SDLManager::getRenderer() { return renderer; }

bool SDLManager::init()
{
    if (!SDL_Init(SDL_INIT_VIDEO | SDL_INIT_EVENTS))
    {
        SDL_Log("SDL could not initialize! E: %s\n", SDL_GetError());
        return false;
    }
    else if (!SDL_CreateWindowAndRenderer("Chess Engine", 800, 600, 0, &window, &renderer))
    {
        SDL_Log("SDL could not create window and renderer! E: %s\n", SDL_GetError());
        return false;
    }

    SDL_SetRenderDrawColor(renderer, 40, 40, 40, 255);
    SDL_RenderClear(renderer);

    return true;
}
