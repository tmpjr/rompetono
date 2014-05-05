#ifndef TEXTUREMANAGER_H
#define TEXTUREMANAGER_H

#include <SDL2/SDL.h>
#include <SDL2_image/SDL_image.h>
#include <iostream>
#include <string>

class TextureManager
{
public:
    TextureManager(SDL_Renderer* gameRenderer);
    ~TextureManager();

    bool loadFromFile(std::string path);
    void free();
    void render(int x, int y, SDL_Rect* clip = NULL, double angle = 0.0, 
        SDL_Point* center = NULL, SDL_RendererFlip flip = SDL_FLIP_NONE);

    int getWidth();
    int getHeight();
private:
    SDL_Texture* mTexture;
    SDL_Renderer* mGameRenderer;

    int mWidth;
    int mHeight;
};

#endif // TEXTUREMANAGER_H
