#include "TextureManager.h"
#include <iostream>

SDL_Texture* TextureManager::Texture(const char* filelocation, SDL_Renderer* ren)
{
    SDL_Surface* surface = IMG_Load(filelocation);
    if (!surface)
    {
        std::cout << "Failed to load surface: " << IMG_GetError() << std::endl;
        return nullptr;
    }
    SDL_Texture* tex = SDL_CreateTextureFromSurface(ren, surface);
    SDL_FreeSurface(surface);
    if (!tex)
    {
        std::cout << "Failed to create texture: " << SDL_GetError() << std::endl;
    }
    return tex;
}
