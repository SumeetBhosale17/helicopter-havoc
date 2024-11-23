// src/Headers/Obstacle.h
#pragma once
#include "Object.h"

class Obstacle : public Object
{
public:
    Obstacle(int windowWidth, int windowHeight);
    void Update(int windowWidth, int windowHeight, float speed);
    void Render(SDL_Renderer* ren);
};
