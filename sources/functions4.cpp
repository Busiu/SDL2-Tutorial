//
// Created by Busiu on 25.07.2018.
//

#include "../headers/functions4.h"

void close(){
    //free surfaces
    for(int i = KEY_PRESS_SURFACE_DEFAULT; i < KEY_PRESS_SURFACE_TOTAL; i++){
        freeSurface(keyPressSurfaces[i]);
    }

    //destroy the window
    freeWindow(window);

    //abandon the SDL
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
    bool success = true;

    //SDL initialization
    if(SDL_Init(SDL_INIT_VIDEO) < 0){
        cout << "Nie mozna zainicjalizowac video. Error: " << SDL_GetError() << endl;
        success = false;
    }
    else{
        //Create the window
        window = SDL_CreateWindow("SDL Tutorial", SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED,
                                  SCREEN_WIDTH, SCREEN_HEIGHT, SDL_WINDOW_SHOWN);
        if(window == nullptr){
            cout << "Nie mozna zainicjalizowac okna. Error: " << SDL_GetError() << endl;
        }
        else{
            //Combine surface with window
            screenSurface = SDL_GetWindowSurface(window);
        }
    }

    return success;
}

SDL_Surface* loadSurface(string path){
    //Loading the picture from the path
    SDL_Surface* loadedSurface = SDL_LoadBMP(path.c_str());
    if(loadedSurface == nullptr){
        printf("Nie udalo sie wczytac obrazka. Error: %s\n", SDL_GetError());
    }

    return loadedSurface;
}

bool loadMedia(){
    bool success = true;

    //Load default surface
    keyPressSurfaces[KEY_PRESS_SURFACE_DEFAULT] = loadSurface("Images/default.bmp");
    if(keyPressSurfaces[KEY_PRESS_SURFACE_DEFAULT] == nullptr){
        printf("Failed to load default image!\n");
        success = false;
    }

    //Load up surface
    keyPressSurfaces[KEY_PRESS_SURFACE_UP] = loadSurface("Images/up.bmp");
    if(keyPressSurfaces[KEY_PRESS_SURFACE_UP] == nullptr){
        printf("Failed to load up image!\n");
        success = false;
    }

    //Load down surface
    keyPressSurfaces[KEY_PRESS_SURFACE_DOWN] = loadSurface("Images/down.bmp");
    if(keyPressSurfaces[KEY_PRESS_SURFACE_DOWN] == nullptr){
        printf("Failed to load down image!\n");
        success = false;
    }

    //Load left surface
    keyPressSurfaces[KEY_PRESS_SURFACE_LEFT] = loadSurface("Images/left.bmp");
    if(keyPressSurfaces[KEY_PRESS_SURFACE_LEFT] == nullptr){
        printf("Failed to load left image!\n");
        success = false;
    }

    //Load right surface
    keyPressSurfaces[KEY_PRESS_SURFACE_RIGHT] = loadSurface("Images/right.bmp");
    if(keyPressSurfaces[KEY_PRESS_SURFACE_RIGHT] == nullptr){
        printf("Failed to load right image!\n");
        success = false;
    }

    //Load exiting surface
    xOpuszczamySurface = loadSurface("Images/xOpuszczamy.bmp");
    if(xOpuszczamySurface == nullptr){
        printf("Failed to load exiting image!\n");
        success = false;
    }

    return success;
}

void updateWindow(SDL_Surface* surface){
    SDL_BlitSurface(surface, nullptr, screenSurface, nullptr);
    SDL_UpdateWindowSurface(window);
}
