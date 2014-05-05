#ifndef PADDLE_H
#define PADDLE_H

#include <SDL2/SDL.h>
#include "TextureManager.h"

class Paddle
{
    public:
        static constexpr int WIDTH{104};
        static constexpr int HEIGHT{24};
        static constexpr int VELOCITY{220};

        Paddle(int gameWidth, int gameHeight);

        void handleEvent(SDL_Event &e);
        void move(float deltaTime);
        void render(TextureManager& TextureManager);

    private:
        float positionX, positionY;
        float velocityX, velocityY;

};

#endif // PADDLE_H
