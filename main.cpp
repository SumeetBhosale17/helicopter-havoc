#include "GameLoop.h"
#include <ctime>

int main(int argc, char** argv)
{
    srand(static_cast<unsigned int>(time(nullptr)));
    GameLoop* g = new GameLoop();

    g->Intialize();
    while (g->getGameState())
    {
        g->Event();
        g->Update();
        g->Render();
        SDL_Delay(16); // Delay to cap at ~60 FPS
    }
    g->Clear();
    delete g;
    return 0;
}
