//
// Created by Busiu on 30.07.2018.
//

#include "../../headers/7/functions7.h"

void close(){
    //Free loaded image
    SDL_DestroyTexture(defaultTexture);
    defaultTexture = nullptr;

    //Destroy the window
    SDL_DestroyRenderer(renderer);
    renderer = nullptr;
    SDL_DestroyWindow(window);
    window = nullptr;

    //Abandon the SDL & IMG mode
    SDL_Quit();
    IMG_Quit();
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

            //Initialize PNG loading
            int imgFlags = IMG_INIT_PNG;
            if(!(IMG_Init(imgFlags) & imgFlags)){
                printf("Failed to initialize SDL_Image! Error: %s\n", IMG_GetError());
                success = false;
            }
        }
    }

    return success;
}

bool loadMedia(){
    bool success = true;

    //Load PNG texture
    defaultTexture = loadTexture("../assets/textures/png/defaultTexture.png");
    if(defaultTexture == nullptr){
        printf("Failed to load texture image!\n");
        success = false;
    }

    return success;
}

SDL_Texture* loadTexture(string path){
    //The final texture
    SDL_Texture* newTexture = nullptr;

    //Load image at specified path
    SDL_Surface* loadedSurface = IMG_Load(path.c_str());
    if(loadedSurface == nullptr){
        printf("Failed to load image! Error: %s\n", IMG_GetError());
    }
    else{
        //Create texture from surface pixels
        newTexture = SDL_CreateTextureFromSurface(renderer, loadedSurface);
        if(newTexture == nullptr){
            printf("Failed to create new texture! Error: %s\n", SDL_GetError());
        }

        //Get rid of old loaded surface
        SDL_FreeSurface(loadedSurface);
    }

    return newTexture;
}

