#pragma once

#include "sdl_fwd.hpp"

class Renderer
{
public:
    explicit Renderer(SDL_Renderer *renderer = nullptr);

    void setRenderer(SDL_Renderer *renderer);
    void drawBoard();
    void renderPresent();

    private:
    SDL_Texture *createRowTexture();
    void renderRowTexture(SDL_Texture *rowTexture, int rowIndex);

    SDL_Renderer *renderer = nullptr;
};
