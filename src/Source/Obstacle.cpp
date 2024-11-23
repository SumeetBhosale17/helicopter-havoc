#include "Obstacle.h"
#include <cstdlib> // For rand()
#include <ctime>   // For time()
#include "Constants.h"
#include <iostream>

Obstacle::Obstacle(int windowWidth, int windowHeight)
{
    // Initialize obstacle position and size
    setSrc(0, 0, 52, 320); // Ensure these match your texture's actual dimensions
    setDest(windowWidth, rand() % (windowHeight - 320), 52, 320); // Start at the right edge

    // Debug: Print initial position
    SDL_Rect initialDest = getDest();
    std::cout << "Initial Obstacle Position: (" << initialDest.x << ", " << initialDest.y << ")" << std::endl;
}

void Obstacle::Update(int windowWidth, int windowHeight, float speed) // Ensure this matches the header
{
    // Move the obstacle to the left
    SDL_Rect dest = getDest();
    dest.x -= static_cast<int>(2 * speed); // Adjust speed as needed

    // Reset obstacle position when it goes off-screen
    if (dest.x + dest.w < 0)
    {
        dest.x = windowWidth; // Use passed width
        dest.y = rand() % (windowHeight - dest.h); // Randomize y position within bounds
    }

    setDest(dest.x, dest.y, dest.w, dest.h);

    // Debug: Print updated position
    SDL_Rect updatedDest = getDest();
    std::cout << "Updated Obstacle Position: (" << updatedDest.x << ", " << updatedDest.y << ")" << std::endl;
}

void Obstacle::Render(SDL_Renderer* ren)
{
    if (getTexture() == nullptr)
    {
        // Render a red rectangle as a placeholder
        SDL_Rect dest = getDest();
        SDL_SetRenderDrawColor(ren, 255, 0, 0, 255); // Red color
        SDL_RenderFillRect(ren, &dest);
        return;
    }

    SDL_Rect src = getSrc();
    SDL_Rect dest = getDest();
    SDL_RenderCopy(ren, getTexture(), &src, &dest);
}
