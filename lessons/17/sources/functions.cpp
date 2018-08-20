//
// Created by Busiu on 20.08.2018.
//

#include "../headers/functions.h"

void close(){
    //Free loaded images
    buttonSpriteSheetTexture.free();

    //Free buttons
    free(buttons);

    //Free SDL_Rect objects
    free(spriteClips);

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

            //Initialize PNG Loading
            int imgFlags = IMG_INIT_PNG;
            if(!(IMG_Init(imgFlags) & imgFlags)){
                printf("Failed to initialize SDL_Image! Error: %s\n", IMG_GetError());
                success = false;
            }
        }
    }

    //Initialize buttons
    buttons = new LButton[TOTAL_BUTTONS];
    for(int i = 0; i < TOTAL_BUTTONS; i++){
        buttons[i].setPosition((i % 2) * BUTTON_WIDTH, (i / 2) * BUTTON_HEIGHT);
    }

    //Initialize SDL_Rect objects
    spriteClips = new SDL_Rect[BUTTON_SPRITE_TOTAL];
    spriteClips[BUTTON_SPRITE_MOUSE_OUT] = {0, BUTTON_HEIGHT * BUTTON_SPRITE_MOUSE_OUT, BUTTON_WIDTH, BUTTON_HEIGHT};
    spriteClips[BUTTON_SPRITE_MOUSE_OVER_MOTION] = {0, BUTTON_HEIGHT * BUTTON_SPRITE_MOUSE_OVER_MOTION, BUTTON_WIDTH, BUTTON_HEIGHT};
    spriteClips[BUTTON_SPRITE_MOUSE_DOWN] = {0, BUTTON_HEIGHT * BUTTON_SPRITE_MOUSE_DOWN, BUTTON_WIDTH, BUTTON_HEIGHT};
    spriteClips[BUTTON_SPRITE_MOUSE_UP] = {0, BUTTON_HEIGHT * BUTTON_SPRITE_MOUSE_UP, BUTTON_WIDTH, BUTTON_HEIGHT};

    return success;
}

bool loadMedia(){
    //Loading success flag
    bool success = true;

    //Load textures
    if(!buttonSpriteSheetTexture.loadFromFile("../lessons/17/assets/textures/button.png")){
        printf("Failed to load button textures!\n");
        success = false;
    }

    return success;
}