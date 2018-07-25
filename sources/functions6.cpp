//
// Created by Busiu on 25.07.2018.
//

#include "../headers/functions6.h"

void close(){
    //Free surfaces
    for(int i = KEY_PRESS_SURFACE_DEFAULT; i < KEY_PRESS_SURFACE_TOTAL; i++){
        freeSurface(keyPressSurfaces[i]);
    }

    //Destroy the window
    freeWindow(window);

    //Abandon the SDL
    SDL_Quit();
}

void freeSurface(SDL_Surface* surface){
    SDL_FreeSurface(surface);
    surface = nullptr;
}

void freeWindow(SDL_Window* window){
    SDL_DestroyWindow(window);
    window = nullptr;
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
            //Initialize PNG loading
            int imgFlags = IMG_INIT_PNG;
            if(!(IMG_Init(imgFlags) & imgFlags)){
                printf("Failed to initialize SDL_Image! Error: %s\n", IMG_GetError());
                success = false;
            }
            else{
                //Get window surface
                screenSurface = SDL_GetWindowSurface(window);
            }
        }
    }

    return success;
}

bool loadMedia(){
    bool success = true;

    //Load default surface
    keyPressSurfaces[KEY_PRESS_SURFACE_DEFAULT] = loadSurface("Images/png/default.png");
    if(keyPressSurfaces[KEY_PRESS_SURFACE_DEFAULT] == nullptr){
        printf("Failed to load default surface!\n");
        success = false;
    }

    //Load up surface
    keyPressSurfaces[KEY_PRESS_SURFACE_UP] = loadSurface("Images/png/up.png");
    if(keyPressSurfaces[KEY_PRESS_SURFACE_UP] == nullptr){
        printf("Failed to load up surface!\n");
        success = false;
    }

    //Load down surface
    keyPressSurfaces[KEY_PRESS_SURFACE_DOWN] = loadSurface("Images/png/down.png");
    if(keyPressSurfaces[KEY_PRESS_SURFACE_DOWN] == nullptr){
        printf("Failed to load down surface!\n");
        success = false;
    }

    //Load left surface
    keyPressSurfaces[KEY_PRESS_SURFACE_LEFT] = loadSurface("Images/png/left.png");
    if(keyPressSurfaces[KEY_PRESS_SURFACE_LEFT] == nullptr){
        printf("Failed to load left surface!\n");
        success = false;
    }

    //Load right surface
    keyPressSurfaces[KEY_PRESS_SURFACE_RIGHT] = loadSurface("Images/png/right.png");
    if(keyPressSurfaces[KEY_PRESS_SURFACE_RIGHT] == nullptr){
        printf("Failed to load right surface!\n");
        success = false;
    }

    //Load exiting surface
    xOpuszczamySurface = loadSurface("Images/png/xOpuszczamy.png");
    if(xOpuszczamySurface == nullptr){
        printf("Failed to load exiting image!\n");
        success = false;
    }

    return success;
}

SDL_Surface* loadSurface(string path){
    //The final optimized image
    SDL_Surface* optimizedSurface = nullptr;

    //Load image at specified path
    SDL_Surface* loadedSurface = IMG_Load(path.c_str());
    if(loadedSurface == nullptr){
        printf("Failed to load image! Error: %s\n", IMG_GetError());
    }
    else{
        //Convert surface to screen format
        optimizedSurface = SDL_ConvertSurface(loadedSurface, screenSurface->format, 0);
        if(optimizedSurface == nullptr){
            printf("Failed to optimize image! Error: %s\n", SDL_GetError());
        }

        //Get rid of old loaded surface
        SDL_FreeSurface(loadedSurface);
    }

    return optimizedSurface;
}

void updateWindow(SDL_Surface* stretchedSurface){
    SDL_Rect stretchedRect;
    stretchedRect.x = 0;
    stretchedRect.y = 0;
    stretchedRect.w = SCREEN_WIDTH;
    stretchedRect.h = SCREEN_HEIGHT;
    SDL_BlitScaled(stretchedSurface, nullptr, screenSurface, &stretchedRect);
    SDL_UpdateWindowSurface(window);
}
