#include "TextureManager.h"

TextureManager::TextureManager(SDL_Renderer* gameRenderer)
{
    mGameRenderer = gameRenderer;
    mTexture = NULL;
    mWidth = 0;
    mHeight = 0;
}

TextureManager::~TextureManager()
{
    free();
}

bool TextureManager::loadFromFile(std::string path)
{
    // get rid of preexisting texture
    free();

    // Final texture
    SDL_Texture* newTexture = NULL;

    SDL_Surface* loadedSurface = IMG_Load(path.c_str());
    if (loadedSurface == NULL) {
        throw std::runtime_error("Cannot load texture!");
    }

    newTexture = SDL_CreateTextureFromSurface(mGameRenderer, loadedSurface);
    if (newTexture == NULL) {
        printf( "Unable to create texture from %s! SDL Error: %s\n", path.c_str(), SDL_GetError() );
        return false; 
        //throw std::runtime_error("Unable to create texture from surface!");
    }

    mWidth = loadedSurface->w;
    mHeight = loadedSurface->h;

    SDL_FreeSurface(loadedSurface);

    mTexture = newTexture;
    return mTexture != NULL;
}

void TextureManager::free()
{
    if (mTexture != NULL) {
        SDL_DestroyTexture(mTexture);
        mTexture = NULL;
        mWidth = 0;
        mHeight = 0;
    }
}

void TextureManager::render(int x, int y, SDL_Rect* clip, double angle, SDL_Point* center, SDL_RendererFlip flip)
{
    SDL_Rect renderQuad = { x, y, mWidth, mHeight };

    if (clip != NULL) {
        renderQuad.w = clip->w;
        renderQuad.h = clip->h;
    }

    SDL_RenderCopyEx(mGameRenderer, mTexture, clip, &renderQuad, angle, center, flip);
}

int TextureManager::getWidth()
{
    return mWidth;
}

int TextureManager::getHeight()
{
    return mHeight;
}