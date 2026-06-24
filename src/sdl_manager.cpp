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

void SDLManager::drawBoard()
{
    float rowSize = 600;
    float squareSize = rowSize / 8;
    float squareCoordinateX = 0;
    float rowCoordinateY = 0;

    SDL_Texture *boardTexture = SDL_CreateTexture(renderer, SDL_PIXELFORMAT_RGBA8888, SDL_TEXTUREACCESS_TARGET, rowSize, squareSize);
    SDL_SetRenderTarget(renderer, boardTexture);
    SDL_SetRenderDrawColor(renderer, 0, 0, 0, 0);
    SDL_RenderClear(renderer);

    for (int i = 0; i <= 7; i++)
    {
        if (i % 2 == 0)
        {
            SDL_SetRenderDrawColor(renderer, 33, 65, 50, 255);
        }
        else
        {

            SDL_SetRenderDrawColor(renderer, 223, 220, 221, 255);
        }

        SDL_FRect currentSquare = {squareCoordinateX, 0, squareSize, squareSize};
        SDL_RenderFillRect(renderer, &currentSquare);
        squareCoordinateX += squareSize;
    }

    SDL_SetRenderTarget(renderer, nullptr);
    SDL_SetTextureBlendMode(boardTexture, SDL_BLENDMODE_BLEND);

    SDL_FRect *src = nullptr;

    SDL_FRect dest;
    dest.x = 100;
    dest.y = 0;
    dest.w = rowSize;
    dest.h = squareSize;

    for (int i = 0; i <= 7; i++)
    {
        if (i % 2 == 0)
        {
            SDL_RenderTextureRotated(
                renderer,
                boardTexture,
                src,
                &dest,
                0.0,
                nullptr,
                SDL_FLIP_HORIZONTAL);
        }
        else
        {
            SDL_RenderTexture(renderer, boardTexture, nullptr, &dest);
        }

        dest.y += squareSize;
    }
}

void SDLManager::drawPieces(U64 position)
{
}

void SDLManager::clear() {
    SDL_DestroyRenderer(renderer);
    SDL_DestroyWindow(window);
    SDL_Quit();
}
