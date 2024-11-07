#ifndef ENGINE_H
#define ENGINE_H

#include "SDL.h"
#include "SDL_image.h"

#define SCREEN_WIDTH 960
#define SCREEN_HEIGHT 640

class Engine
{
    public:
        static Engine* GetInstance()  // Returns the instance of the Engine
        {
            return s_Instance = (s_Instance != nullptr) ? s_Instance : new Engine();
        }

        bool Init();
        void Render();
        bool Clean();
        void Update();
        void Events();
        void Quit();

        inline bool IsRunning() {return m_IsRunning;} // to check whether the engine is running
        inline SDL_Renderer* GetRenderer() {return m_Renderer;} // returns renderer

    protected:

    private:
        Engine(){}
        static Engine* s_Instance;
        bool m_IsRunning;

        SDL_Window* m_Window;
        SDL_Renderer* m_Renderer;
};

#endif // ENGINE_H
