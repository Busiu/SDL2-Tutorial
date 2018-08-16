//
// Created by Busiu on 16.08.2018.
//

#include "../headers/functions.h"

void close(){
    //Free loaded images
    billyTexture.free();
    vanTexture.free();

    //Destroy window
    SDL_DestroyRenderer(renderer);
    SDL_DestroyWindow(window);
    window = nullptr;
    renderer = nullptr;

    //Quit SDL subsystems
    IMG_Quit();
    SDL_Quit();
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
    //Loading success flag
    bool success = true;

    //Load Van's texture
    if(!vanTexture.loadFromFile("../lessons/13/assets/textures/van.png")){
        printf("Failed to load Van's texture!\n");
        success = false;
    }
    else{
        //Set standard alpha blending
        vanTexture.setBlendMode(SDL_BLENDMODE_BLEND);
    }

    //Load background (Billy's) texture
    if(!billyTexture.loadFromFile("../lessons/13/assets/textures/billy.png")){
        printf("Failed to load background (Billy's) texture!\n");
        success = false;
    }

    return success;
}