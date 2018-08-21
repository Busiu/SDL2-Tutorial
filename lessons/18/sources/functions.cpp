//
// Created by Busiu on 21.08.2018.
//

#include "../headers/functions.h"

void close(){
    //Free loaded textures
    defaultTexture.free();
    downTexture.free();
    leftTexture.free();
    rightTexture.free();
    upTexture.free();

    //Destroy window
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
            #ifdef _SDL_TTF_H
            //Initialize SDL_ttf
            if(TTF_Init() == -1){
                printf("Failed to initialize SDL_ttf! Error: %s\n", TTF_GetError());
                success = false;
            }
            #endif
        }
    }

    return success;
}

bool loadMedia(){
    //Initialize success flag
    bool success = true;

    //Load default texture
    if(!defaultTexture.loadFromFile("../lessons/18/assets/textures/default.png")){
        printf("Failed to load default texture!\n");
    }
    //Load down texture
    if(!downTexture.loadFromFile("../lessons/18/assets/textures/down.png")){
        printf("Failed to load down texture!\n");
    }
    //Load left texture
    if(!leftTexture.loadFromFile("../lessons/18/assets/textures/left.png")){
        printf("Failed to load left texture!\n");
    }
    //Load right texture
    if(!rightTexture.loadFromFile("../lessons/18/assets/textures/right.png")){
        printf("Failed to load right texture!\n");
    }
    //Load up texture
    if(!upTexture.loadFromFile("../lessons/18/assets/textures/up.png")){
        printf("Failed to load up texture!\n");
    }

    return success;
}
