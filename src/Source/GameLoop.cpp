#include "GameLoop.h"
#include <cstdlib>
#include <ctime>
#include "Constants.h" 
#include <SDL_ttf.h>


GameLoop::GameLoop()
    : obstacle(WIDTH, HEIGHT), score(0), speed(2.0f)
{
    srand(static_cast<unsigned int>(time(nullptr)));
    window = NULL;
    renderer = NULL;
    GameState = false;
    p.setSrc(0, 0, 53, 144);
    p.setDest(25, HEIGHT / 2, 53, 144); 
    ground1.setSrc(0, 0, 112, 336);
    ground1.setDest(0, 420, 112, 336);
    ground2.setSrc(0, 0, 112, 336);
    ground2.setDest(336, 420, 112, 336);

    obstacle.setDest(WIDTH, rand() % (HEIGHT - 320), 52, 320);
}

bool GameLoop::getGameState()
{
    return GameState;
}


void GameLoop::Intialize()
{
    SDL_Init(SDL_INIT_EVERYTHING);
    if (TTF_Init() == -1)
    {
        std::cout << "SDL_ttf could not initialize! SDL_ttf Error: " << TTF_GetError() << std::endl;
        GameState = false;
        return;
    }
    int imgFlags = IMG_INIT_PNG;
    if (!(IMG_Init(imgFlags) & imgFlags))
    {
        std::cout << "SDL_image could not initialize! SDL_image Error: " << IMG_GetError() << std::endl;
        GameState = false;
        return;
    }
    window = SDL_CreateWindow("My Game", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, WIDTH, HEIGHT, 0);
    if (window)
    {
        renderer = SDL_CreateRenderer(window, -1, 0);
        if (renderer)
        {
            std::cout << "Renderer created successfully!" << std::endl;
            GameState = true; 
            p.CreateTexture("Assets/Images/heli.png", renderer); 
            p.CreateTexture1("Assets/Images/heli.png", renderer); 
            p.CreateTexture2("Assets/Images/heli.png", renderer); 
            b.CreateTexture("Assets/Images/background-day.png", renderer);
            ground1.CreateTexture("Assets/Images/base.png", renderer);
            ground2.CreateTexture("Assets/Images/base.png", renderer);
            obstacle.CreateTexture("Assets/Images/pipe-green.png", renderer);

            // Load Game Over Image
            gameOverTexture = TextureManager::Texture("Assets/Images/gameover.png", renderer);
            if (gameOverTexture == nullptr)
            {
                std::cout << "Failed to load Game Over texture." << std::endl;
            }

            if (obstacle.getTexture() == nullptr)
            {
                std::cout << "Failed to load Obstacle texture." << std::endl;
            }
            else
            {
                std::cout << "Obstacle texture loaded successfully." << std::endl;
            }
        }
        else
        {
            std::cout << "Failed to create renderer!" << std::endl;
            GameState = false;
        }
    }
    else
    {
        std::cout << "Failed to create window!" << std::endl;
        GameState = false;
    }
    std::cout << "GameState after initialization: " << GameState << std::endl;
}

void GameLoop::Event()
{
    p.GetJumpTime();
    SDL_PollEvent(&event1);
    if (event1.type == SDL_QUIT)
    {
        GameState = false;
    }
    if (event1.type == SDL_KEYDOWN)
    {
        if (event1.key.keysym.sym == SDLK_SPACE)
        {
            if (!p.JumpState())
            {
                p.Jump();
            }
            else
            {
                p.Gravity(speed); 
            }
        }
    }
    else
    {
        p.Gravity(speed);
    }
    std::cout << "GameState after event handling: " << GameState << std::endl;
}

void GameLoop::Update()
{
    ground1.GroundUpdate1();
    ground2.GroundUpdate2();
    obstacle.Update(WIDTH, HEIGHT, speed); 

    SDL_Rect playerRect = p.getDest();
    SDL_Rect obstacleRect = obstacle.getDest();
    if (SDL_HasIntersection(&playerRect, &obstacleRect))
    {
        GameState = false; 
    }

    if (p.getDest().y + p.getDest().h > HEIGHT || p.getDest().y < 0)
    {
        GameState = false;
    }

    if (GameState)
    {
        score++;
        speed += 0.005f; 
    }

    std::cout << "Player Position: (" << p.getDest().x << ", " << p.getDest().y << ")" << std::endl;
    std::cout << "Obstacle Position: (" << obstacle.getDest().x << ", " << obstacle.getDest().y << ")" << std::endl;
    std::cout << "GameState after update: " << GameState << std::endl;
}

void GameLoop::Render()
{
    SDL_RenderClear(renderer);
    b.Render(renderer); 
    ground1.GroundRender(renderer); 
    ground2.GroundRender(renderer);
    obstacle.Render(renderer);
    p.Render(renderer);

    SDL_Color textColor = {255, 255, 255, 255}; 
    TTF_Font* font = TTF_OpenFont("Assets/Fonts/arial.ttf", 28); 
    if (font)
    {
        std::string scoreText = "Score: " + std::to_string(score);
        SDL_Surface* textSurface = TTF_RenderText_Solid(font, scoreText.c_str(), textColor);
        if (textSurface)
        {
            SDL_Texture* textTexture = SDL_CreateTextureFromSurface(renderer, textSurface);
            if (textTexture)
            {
                SDL_Rect textRect = {10, 10, textSurface->w, textSurface->h};
                SDL_RenderCopy(renderer, textTexture, NULL, &textRect);
                SDL_DestroyTexture(textTexture);
            }
            SDL_FreeSurface(textSurface);
        }
        TTF_CloseFont(font);
    }

    if (!GameState)
    {
        if (gameOverTexture)
        {
            SDL_Rect textRect = {WIDTH / 2 - 200, HEIGHT / 2 - 50, 400, 100};
            SDL_RenderCopy(renderer, gameOverTexture, NULL, &textRect);
        }
    }

    SDL_RenderPresent(renderer);
    std::cout << "GameState during render: " << GameState << std::endl;
}

void GameLoop::Clear()
{
    SDL_DestroyTexture(gameOverTexture);
    SDL_DestroyRenderer(renderer);
    SDL_DestroyWindow(window);
    IMG_Quit();
    SDL_Quit();
}
