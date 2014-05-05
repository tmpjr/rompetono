#include "Paddle.h"

Paddle::Paddle(int gameWidth, int gameHeight)
{
    positionX = (gameWidth - WIDTH) / 2;
    positionY = gameHeight - (HEIGHT * 2);
    velocityX = 0;
    velocityY = 0;
}

void Paddle::handleEvent(SDL_Event &e)
{
    if (e.type == SDL_KEYDOWN && e.key.repeat == 0) {
        // Adjust the velocity
        switch (e.key.keysym.sym) {
            case SDLK_LEFT:
                velocityX -= VELOCITY;
                break;
            case SDLK_RIGHT:
                velocityX += VELOCITY;
                break;
        }
    } else if (e.type == SDL_KEYUP && e.key.repeat == 0) {
        switch (e.key.keysym.sym) {
            case SDLK_LEFT:
                velocityX += VELOCITY;
                break;
            case SDLK_RIGHT:
                velocityX -= VELOCITY;
                break;
        }
    }
}

void Paddle::move(float deltaTime)
{
    positionX += velocityX * deltaTime;
}

void Paddle::render(TextureManager& textureManager)
{
    textureManager.render(positionX, positionY);
}
