#include "sdl_manager.hpp"
#include <SDL3/SDL.h>

SDL_Window *SDLManager::getWindow() { return window; }
SDL_Renderer *SDLManager::getRenderer() { return renderer; }

bool SDLManager::init()
{
    window = nullptr;
    renderer = nullptr;

    if (!SDL_Init(SDL_INIT_VIDEO | SDL_INIT_EVENTS))
    {
        SDL_Log("SDL could not initialize! E: %s\n", SDL_GetError());
        return false;
    }
    else if (!SDL_CreateWindowAndRenderer("Chess Engine", 800, 600, 0, &window, &renderer))
    {
        SDL_Log("SDL could not create window and renderer! E: %s\n", SDL_GetError());
        SDL_Quit();
        return false;
    }

    SDL_SetRenderDrawColor(renderer, 40, 40, 40, 255);
    SDL_RenderClear(renderer);

    return true;
}

void SDLManager::clear()
{
    if (renderer)
    {
        SDL_DestroyRenderer(renderer);
        renderer = nullptr;
    }

    if (window)
    {
        SDL_DestroyWindow(window);
        window = nullptr;
    }

    renderer = nullptr;
    window = nullptr;
    SDL_Quit();
}

void SDLManager::mapEventType(const SDL_Event& sdlEvent, AppEvent& event)
{
    switch (sdlEvent.type)
    {
    case SDL_EVENT_QUIT:
        event.type = AppEventType::CHESS_QUIT;
        break;

    default:
        event.type = AppEventType::CHESS_NONE;
        break;
    }
}

bool SDLManager::waitEvent(AppEvent& event)
{
    SDL_Event sdlEvent{};
    if (!SDL_WaitEvent(&sdlEvent))
    {
        return false;
    }

    mapEventType(sdlEvent, event);

    return true;
}
