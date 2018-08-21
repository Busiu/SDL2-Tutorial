//
// Created by Busiu on 21.08.2018.
//

#include "../headers/functions.h"

void close()
{
    //Free created textures
    promptTextTexture.free();
    timeTextTexture.free();

    //Destroy window & renderer
    SDL_DestroyRenderer(renderer);
    SDL_DestroyWindow(window);
    window = nullptr;
    renderer = nullptr;

    //Quit SDL subsystems
    IMG_Quit();
    SDL_Quit();
    #ifdef _SDL_TTF_H
    TTF_Quit();
    #endif
}

bool init()
{
    //Initialization flag
    bool success = true;

    //Initialize SDL
    if(SDL_Init(SDL_INIT_VIDEO) < 0)
    {
        printf("Failed to initialize SDL! Error: %s\n", SDL_GetError());
        success = false;
    }
    else
    {
        //Create window
        window = SDL_CreateWindow("SDL Tutorial", SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED,
                                  SCREEN_WIDTH, SCREEN_HEIGHT, SDL_WINDOW_SHOWN);
        if(window == nullptr)
        {
            printf("Failed to create window! Error: %s\n", SDL_GetError());
            success = false;
        }
        else
        {
            //Create renderer for window
            renderer = SDL_CreateRenderer(window, -1, SDL_RENDERER_ACCELERATED);

            //Initialize PNG Loading
            int imgFlags = IMG_INIT_PNG;
            if(!(IMG_Init(imgFlags) & imgFlags))
            {
                printf("Failed to initialize SDL_Image! Error: %s\n", IMG_GetError());
                success = false;
            }
            #ifdef _SDL_TTF_H
            //Initialize SDL_ttf
            if(TTF_Init() == -1)
            {
                printf("Failed to initialize SDL_ttf! Error: %s\n", TTF_GetError());
                success = false;
            }
            #endif
        }
    }

    return success;
}

bool loadMedia()
{
    //Initialize success flag
    bool success = true;

    //Open the font
    font = TTF_OpenFont("../lessons/22/assets/fonts/lazy.ttf", 28);
    if(font == nullptr)
    {
        printf("Failed to load lazy font! Error: %s\n", TTF_GetError());
        success = false;
    }
    else
    {
        //Set text color as black
        SDL_Color textColor = {0, 0, 0, 255};

        //Load prompt texture
         if(!promptTextTexture.loadFromRenderedText("Press ENTER to reset timer.", textColor))
         {
             printf("Failed to render prompt texture!");
             success = false;
         }
    }

    return success;
}
