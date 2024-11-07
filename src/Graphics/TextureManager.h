#ifndef TEXTUREMANAGER_H
#define TEXTUREMANAGER_H

#include <string>
#include <map>
#include "SDL.h"

using namespace std;

class TextureManager
{
    public:
        static TextureManager* GetInstance() // To get instance of the texture
        {
            return s_Instance = (s_Instance != nullptr) ? s_Instance : new TextureManager();
        }

        bool Load(string id, string filename);
        void Drop(string id);
        void Clean();

        void Draw(string id, int x, int y, int width, int height, SDL_RendererFlip flip=SDL_FLIP_NONE);
        void DrawFrame(string id, int x, int y, int width, int height, int row, int frame, SDL_RendererFlip flip=SDL_FLIP_NONE)

    private:
        TextureManager(){}
        map <string, SDL_Texture*> m_TextureMap;
        static TextureManager* s_Instance;
};

#endif // TEXTUREMANAGER_H
