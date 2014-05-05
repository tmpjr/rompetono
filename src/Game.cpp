#include "Game.h"

Game::Game()
{
   run();
}

Game::~Game()
{
}

bool Game::init()
{
    if (SDL_Init(SDL_INIT_VIDEO) < 0) {
        printf("Could not init SDL: %s", SDL_GetError());
        return false;
    }

    window = SDL_CreateWindow("Rompetono", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED,
        WIDTH, HEIGHT, SDL_WINDOW_SHOWN);
    if (window == nullptr) {
        printf("Could not create SDL Window: %s", SDL_GetError());
        return false;
    }

    //primarySurface = SDL_GetWindowSurface(window);

    renderer = SDL_CreateRenderer(window, -1, SDL_RENDERER_ACCELERATED | SDL_RENDERER_TARGETTEXTURE);
    if (renderer == nullptr) {
        printf("Could not create SDL Renderer: %s", SDL_GetError());
        return false;
    } 

    SDL_SetRenderDrawColor(renderer, 55, 55, 55, 255);

    if (!(IMG_Init(IMG_INIT_PNG) && IMG_INIT_PNG)) {
        printf("Could not initialize SDL_Image: %s", IMG_GetError());
    }

    // Load textures
    txtPaddle = { renderer }; 
    txtPaddle.loadFromFile("content/img/paddleRed.png");

    return true;
}

void Game::run()
{
    init();

    SDL_Event e;

    Uint32 lastTime, currentTime, frameTime;
    float deltaTime;
    currentTime = SDL_GetTicks();

    while (running) {
        lastTime = currentTime;
        currentTime = SDL_GetTicks();
        deltaTime = (currentTime - lastTime) / 1000.0f;

        while (SDL_PollEvent(&e) != 0) {
            if (e.type == SDL_QUIT) {
                running = false;
            }
            
            paddle.handleEvent(e);
        }

        render(deltaTime);

        frameTime = SDL_GetTicks() - currentTime;
        if (frameTime < DELAY_TIME) {
            SDL_Delay((int)(DELAY_TIME - frameTime));
        }
    }
    
    clean();
}

void Game::render(float deltaTime)
{
    SDL_RenderClear(renderer);

    // Move the paddle
    paddle.move(deltaTime);    

    // Render the paddle
    paddle.render(txtPaddle);

    SDL_RenderPresent(renderer);
}

void Game::clean()
{
    if (renderer) {
        SDL_DestroyRenderer(renderer);
        renderer = nullptr;
    }

    if (window) {
        SDL_DestroyWindow(window);
        window = nullptr;
    }

    IMG_Quit();
    SDL_Quit();
}

SDL_Renderer* Game::getRenderer()
{
    return renderer;
}

int Game::getWidth()
{
    return WIDTH;
}

int Game::getHeight()
{
    return HEIGHT;
}
