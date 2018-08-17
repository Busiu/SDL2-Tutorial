//
// Created by Busiu on 16.08.2018.
//

#include "../headers/functions.h"

void close(){
    //Free loaded images
    spriteSheetTexture.free();

    //Destroy window
    SDL_DestroyRenderer(renderer);
    SDL_DestroyWindow(window);
    window = nullptr;
    renderer = nullptr;

    //Deallocate memory
    free(spriteClips);

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

    //Initialize variables
    spriteClips = new SDL_Rect[WALKING_ANIMATION_FRAMES];

    return success;
}

bool loadMedia(){
    //Loading success flag
    bool success = true;

    //Load animation texture
    if(!spriteSheetTexture.loadFromFile("../lessons/14/assets/animations/foo.png")){
        printf("Failed to load animation texture!\n");
        success = false;
    }
    else{
        //Set sprite clips {x, y, w, h}
        spriteClips[0] = {0, 0, 64, 205};
        spriteClips[1] = {64, 0, 64, 205};
        spriteClips[2] = {128, 0, 64, 205};
        spriteClips[3] = {192, 0, 64, 205};
    }

    return success;
}