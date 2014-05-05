#ifndef GAME_H
#define GAME_H

#include <SDL2/SDL.h>
#include <SDL2_image/SDL_image.h>
#include <stdio.h>

#include "TextureManager.h"
#include "Paddle.h"

class Game
{
    private:
        bool running = true;

        static constexpr int WIDTH{800};
        static constexpr int HEIGHT{600};
        static constexpr int FPS{60};
        static constexpr float DELAY_TIME = 1000.f / FPS;

        SDL_Window* window = nullptr;
        SDL_Renderer* renderer = nullptr;
        //SDL_Surface* primarySurface = nullptr;
        
        TextureManager txtPaddle = NULL;
        Paddle paddle{WIDTH, HEIGHT}; 

        bool init();
        void run();
        void render(float deltaTime);
        void clean();

    public:
        Game();
        ~Game();

        SDL_Renderer* getRenderer();

        static int getWidth();
        static int getHeight();
};

#endif // GAME_H
