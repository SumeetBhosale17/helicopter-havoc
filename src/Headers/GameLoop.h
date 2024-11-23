#pragma once
#include <SDL.h>
#include <SDL_image.h>
#include <iostream>
#include "Player.h"
#include "Background.h"
#include "Obstacle.h"

class GameLoop
{
private:
    Player p;
    Background b;
    Background ground1, ground2;
    Obstacle obstacle;
    SDL_Texture* gameOverTexture; // Add this line
    const int HEIGHT = 600;
    const int WIDTH = 800;
    bool GameState;
    SDL_Window* window;
    SDL_Event event1;
    SDL_Renderer* renderer;
    int score; // Add this line
    float speed; // Add this line
public:
    GameLoop();
    bool getGameState();
    void Update();
    void Intialize();
    void Event();
    void Render();
    void Clear();
};
