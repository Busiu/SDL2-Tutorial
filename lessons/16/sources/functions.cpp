//
// Created by Busiu on 20.08.2018.
//

#include "../headers/functions.h"

void close(){
    //Free loaded images
    textTexture.free();

    //Free global font
    TTF_CloseFont(font);
    font = nullptr;

    //Destroy window
    SDL_DestroyRenderer(renderer);
    SDL_DestroyWindow(window);
    window = nullptr;
    renderer = nullptr;

    //Quit SDL subsystems
    IMG_Quit();
    SDL_Quit();
    TTF_Quit();
}

bool init(){
    //Initialization flag
    bool success = true;

    //Initialize SDL
    if(SDL_Init(SDL_INIT_VIDEO) < 0){
        printf("Failed to initialize SDL! Error: %s\n", SDL_GetError());
        success = false;
    }
    else{
        //Create window
        window = SDL_CreateWindow("SDL Tutorial", SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED,
                                  SCREEN_WIDTH, SCREEN_HEIGHT, SDL_WINDOW_SHOWN);
        if(window == nullptr){
            printf("Failed to create window! Error: %s\n", SDL_GetError());
            success = false;
        }
        else{
            //Create renderer for window
            renderer = SDL_CreateRenderer(window, -1, SDL_RENDERER_ACCELERATED);

            //Initialize PNG Loading
            int imgFlags = IMG_INIT_PNG;
            if(!(IMG_Init(imgFlags) & imgFlags)){
                printf("Failed to initialize SDL_Image! Error: %s\n", IMG_GetError());
                success = false;
            }

            //Initialize SDL_ttf
            if(TTF_Init() == -1){
                printf("Failed to initialize SDL_ttf! Error: %s\n", TTF_GetError());
                success = false;
            }
        }
    }

    return success;
}

bool loadMedia(){
    //Loading success flag
    bool success = true;

    //Open the font
    font = TTF_OpenFont("../lessons/16/assets/fonts/lazy.ttf", 28);
    if(font == nullptr){
        printf("Failed to load lazy font! Error: %s\n", TTF_GetError());
        success = false;
    }
    else{
        //Render text
        SDL_Color textColor = {0, 255, 0};
        if(!textTexture.loadFromRenderedText("TTF MORE LIKE WTF", textColor)){
            printf("Failed to load from rendered text texture!\n");
            success = false;
        }
    }

    return success;
}