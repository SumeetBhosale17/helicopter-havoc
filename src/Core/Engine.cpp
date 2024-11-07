#include "Engine.h"
#include "TextureManager.h"
#include <iostream>
#include <Vector2D.h>
#include <Transform.h>

using namespace std;

Engine* Engine::s_Instance = nullptr; // Initialization of the instance

bool Engine::Init()  // The Function to check if initialization is done
{
    if (SDL_Init(SDL_INIT_VIDEO) != 0 && IMG_Init(IMG_INIT_JPG | IMG_INIT_PNG) != 0)
    {
        SDL_Log("Failed to initialize SDL : %s", SDL_GetError());
        return false;
    }

    //Create a Window
    m_Window = SDL_CreateWindow("Game", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, SCREEN_WIDTH, SCREEN_HEIGHT, 0);
    if (m_Window == nullptr)
    {
        SDL_Log("Failed to create window : %s", SDL_GetError());
        return false;
    }

    //Create a Renderer
    m_Renderer = SDL_CreateRenderer(m_Window, -1, SDL_RENDERER_ACCELERATED | SDL_RENDERER_PRESENTVSYNC);
    if (m_Renderer == nullptr)
    {
        SDL_Log("Failed to create Renderer : %s", SDL_GetError());
        return false;
    }

    //Texture load
    TextureManager::GetInstance()->Load("Tex", "Assets/tex.jpg");

    Transform tf;
    tf.Log();

    return m_IsRunning = true;
}

void Engine::Render()
{
    SDL_SetRenderDrawColor(m_Renderer, 124, 218, 254, 255);
    SDL_RenderClear(m_Renderer); // Clear the Renderer

    TextureManager::GetInstance()->Draw("Tex", 0, 0, 474, 259); //Draw the Texture on the window
    SDL_RenderPresent(m_Renderer);
}

bool Engine::Clean() // To clean the Render
{
    TextureManager::GetInstance()->Clean();
    SDL_DestroyRenderer(m_Renderer);
    SDL_DestroyWindow(m_Window);
    IMG_Quit();
    SDL_Quit();
}

void Engine::Update()
{

}

void Engine::Events()
{
    SDL_Event event;
    SDL_PollEvent(&event);
    switch(event.type)
    {
        case SDL_QUIT :
            Quit();
            break;

    }
}

void Engine::Quit()  // To Quit
{
    m_IsRunning = false;
}
