//
// Created by Busiu on 15.08.2018.
//

#include "../headers/functions10.h"

void close(){
    //Free loaded images
    fooTexture.free();
    backgroundTexture.free();

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

    //Load foo' texture
    if(!fooTexture.loadFromFile("../assets/textures/png/foo.png")){
        printf("Failed to load stickman texture image!\n");
        success = false;
    }

    //Load background texture
    if(!backgroundTexture.loadFromFile("../assets/textures/png/background.png")){
        printf("Failed to load background texture image!\n");
        success = false;
    }

    return success;
}
