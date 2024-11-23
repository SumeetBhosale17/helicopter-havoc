#include "Obstacle.h"
#include <cstdlib> // For rand()
#include <ctime>   // For time()
#include "Constants.h"
#include <iostream>

Obstacle::Obstacle(int windowWidth, int windowHeight)
{
    setSrc(0, 0, 52, 320); 
    setDest(windowWidth, rand() % (windowHeight - 320), 52, 320);

    SDL_Rect initialDest = getDest();
    std::cout << "Initial Obstacle Position: (" << initialDest.x << ", " << initialDest.y << ")" << std::endl;
}

void Obstacle::Update(int windowWidth, int windowHeight, float speed)
{
    SDL_Rect dest = getDest();
    dest.x -= static_cast<int>(2 * speed); 

    if (dest.x + dest.w < 0)
    {
        dest.x = windowWidth; 
        dest.y = rand() % (windowHeight - dest.h);
    }

    setDest(dest.x, dest.y, dest.w, dest.h);

    SDL_Rect updatedDest = getDest();
    std::cout << "Updated Obstacle Position: (" << updatedDest.x << ", " << updatedDest.y << ")" << std::endl;
}

void Obstacle::Render(SDL_Renderer* ren)
{
    if (getTexture() == nullptr)
    {
        SDL_Rect dest = getDest();
        SDL_SetRenderDrawColor(ren, 255, 0, 0, 255); 
        SDL_RenderFillRect(ren, &dest);
        return;
    }

    SDL_Rect src = getSrc();
    SDL_Rect dest = getDest();
    SDL_RenderCopy(ren, getTexture(), &src, &dest);
}
