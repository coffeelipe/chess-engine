#include "renderer.hpp"
#include <SDL3/SDL.h>
#include <SDL3_image/SDL_image.h>

Renderer::Renderer(SDL_Renderer *renderer) : renderer(renderer) {}

void Renderer::setRenderer(SDL_Renderer *renderer)
{
    this->renderer = renderer;
}

SDL_Texture *Renderer::createRowTexture()
{
    const int rowSize = 600; // Default window size is 800x600, so the row size is set to 600 to fit within the window width with some padding on the sides.
    const int squareSize = rowSize / 8;

    SDL_Texture *rowTexture = SDL_CreateTexture(renderer, SDL_PIXELFORMAT_RGBA8888, SDL_TEXTUREACCESS_TARGET, rowSize, squareSize);
    if (!rowTexture)
    {
        return nullptr;
    }

    SDL_SetRenderTarget(renderer, rowTexture);
    SDL_SetRenderDrawColor(renderer, 0, 0, 0, 0);
    SDL_RenderClear(renderer);

    for (int file = 0; file < 8; ++file)
    {
        if (file % 2 == 0)
        {
            SDL_SetRenderDrawColor(renderer, 223, 220, 221, 255);
        }
        else
        {
            SDL_SetRenderDrawColor(renderer, 33, 65, 50, 255);
        }

        SDL_FRect currentSquare = {
            static_cast<float>(file * squareSize),
            0.0f,
            static_cast<float>(squareSize),
            static_cast<float>(squareSize)};
        SDL_RenderFillRect(renderer, &currentSquare);
    }

    SDL_SetRenderTarget(renderer, nullptr);
    SDL_SetTextureBlendMode(rowTexture, SDL_BLENDMODE_BLEND);

    return rowTexture;
}

void Renderer::renderRowTexture(SDL_Texture *rowTexture, int rowIndex)
{
    const int rowSize = 600;
    const int squareSize = rowSize / 8;

    SDL_FRect dest{
        100.0f,
        static_cast<float>(rowIndex * squareSize),
        static_cast<float>(rowSize),
        static_cast<float>(squareSize)};

    if (rowIndex % 2 == 0)
    {
        SDL_RenderTexture(renderer, rowTexture, nullptr, &dest);
        return;
    }

    SDL_RenderTextureRotated(renderer, rowTexture, nullptr, &dest, 0.0, nullptr, SDL_FLIP_HORIZONTAL);
}

void Renderer::drawBoard()
{
    if (!renderer)
    {
        return;
    }

    SDL_Texture *rowTexture = createRowTexture();
    if (!rowTexture)
    {
        return;
    }

    for (int rank = 8; rank > 0; --rank)
    {
        renderRowTexture(rowTexture, rank - 1);
    }

    SDL_DestroyTexture(rowTexture);
}

bool Renderer::loadPieceTextures()
{
    // TODO: Use a loop to load textures for all pieces instead of hardcoding each one.
    // TODO: Configure the path to the assets folder dynamically instead of hardcoding it.
    
    std::array<std::string, 6> suffixes = {"pawn", "rook", "knight", "bishop", "queen", "king"};

    for (int i = 0; i < 12; i++)
    {
        std::string prefix = (i < 6) ? "w" : "b";
        std::string suffix = (i < 6) ? suffixes[i] : suffixes[i - 6];
        std::string key = std::format("{}_{}", prefix, suffix);
        std::string fileName = std::format("{}-{}", (prefix == "w" ? "white" : "black"), suffix);
        std::string path = "../assets/pieces/" + fileName + ".png";
        SDL_Texture *currentTexture = IMG_LoadTexture(renderer, path.c_str());

        if (!currentTexture)
        {
            SDL_Log("Failed to load %s: %s", fileName.c_str(), SDL_GetError());
            return false;
        }

        pieces.insert({key, currentTexture});
    }
    return true;
}

void Renderer::renderPresent()
{
    if (renderer)
    {
        SDL_RenderPresent(renderer);
    }
}
