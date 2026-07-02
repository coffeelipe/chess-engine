#pragma once
#include "common.hpp"
#include "sdl_fwd.hpp"

class Renderer
{
public:
    explicit Renderer(SDL_Renderer *renderer = nullptr);

    void setRenderer(SDL_Renderer *renderer);

    void drawBoard();
    bool loadPieceTextures();
    void renderPresent();
    void destroyTextures();

private:
    SDL_Texture *createRowTexture();
    void renderRowTexture(SDL_Texture *rowTexture, int rowIndex);
    std::map<std::string, SDL_Texture *> pieces{};

    SDL_Renderer *renderer = nullptr;
};
