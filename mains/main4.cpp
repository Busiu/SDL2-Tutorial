//
// Created by Busiu on 23.07.2018.
//

#include <iostream>
#include <SDL2/SDL.h>
#include <cstdio>
#include "../headers/enums.h"

using namespace std;

//ZMIENNE GLOBALNE
const int SCREEN_HEIGHT = 480;
const int SCREEN_WIDTH = 640;
bool quit = false;

SDL_Window* window = nullptr;
SDL_Surface* screenSurface = nullptr;
SDL_Surface* currentSurface = nullptr;
SDL_Surface* xOpuszczamySurface = nullptr;
SDL_Surface* keyPressSurfaces[KEY_PRESS_SURFACE_TOTAL];
SDL_Event event;

//FUNKCJE GLOBALNE *****************************************************************************************************
void error(const string &what){
    cout << "Failed to " << what << "." << endl;
}

bool init(){
    //FLAGA INICJALIZACYJNA
    bool success = true;

    //INICJALIZACJA SDL-a
    if(SDL_Init(SDL_INIT_VIDEO) < 0){
        cout << "Nie mozna zainicjalizowac video. Error: " << SDL_GetError() << endl;
        success = false;
    }
    else{
        //TWORZENIE OKNA
        window = SDL_CreateWindow("SDL Tutorial", SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED,
                                  SCREEN_WIDTH, SCREEN_HEIGHT, SDL_WINDOW_SHOWN);
        if(window == nullptr){
            cout << "Nie mozna zainicjalizowac okna. Error: " << SDL_GetError() << endl;
        }
        else{
            //LACZENIE SURFACE Z OKNEM
            screenSurface = SDL_GetWindowSurface(window);
        }
    }

    return success;
}

void freeSurfaces(){
    for(int i = 0; i < KEY_PRESS_SURFACE_TOTAL; i++){
        SDL_FreeSurface(keyPressSurfaces[i]);
        keyPressSurfaces[i] = nullptr;
    }
}

void freeWindow(){
    SDL_DestroyWindow(window);
    window = nullptr;
}

SDL_Surface* loadSurface(string path){
    //WCZYTYWANIE OBRAZKA Z PODANEJ SCIEZKI
    SDL_Surface* loadedSurface = SDL_LoadBMP(path.c_str());
    if(loadedSurface == nullptr){
        printf("Nie udalo sie wczytac obrazka. Error: %s\n", SDL_GetError());
    }

    return loadedSurface;
}

bool loadMedia(){
    //FLAGA POWODZENIA
    bool success = true;

    //LOAD DEFAULT SURFACE
    keyPressSurfaces[KEY_PRESS_SURFACE_DEFAULT] = loadSurface("Images/default.bmp");
    if(keyPressSurfaces[KEY_PRESS_SURFACE_DEFAULT] == nullptr){
        printf("Failed to load default image!\n");
        success = false;
    }

    //LOAD UP SURFACE
    keyPressSurfaces[KEY_PRESS_SURFACE_UP] = loadSurface("Images/up.bmp");
    if(keyPressSurfaces[KEY_PRESS_SURFACE_UP] == nullptr){
        printf("Failed to load up image!\n");
        success = false;
    }

    //LOAD DOWN SURFACE
    keyPressSurfaces[KEY_PRESS_SURFACE_DOWN] = loadSurface("Images/down.bmp");
    if(keyPressSurfaces[KEY_PRESS_SURFACE_DOWN] == nullptr){
        printf("Failed to load down image!\n");
        success = false;
    }

    //LOAD LEFT SURFACE
    keyPressSurfaces[KEY_PRESS_SURFACE_LEFT] = loadSurface("Images/left.bmp");
    if(keyPressSurfaces[KEY_PRESS_SURFACE_LEFT] == nullptr){
        printf("Failed to load left image!\n");
        success = false;
    }

    //LOAD RIGHT SURFACE
    keyPressSurfaces[KEY_PRESS_SURFACE_RIGHT] = loadSurface("Images/right.bmp");
    if(keyPressSurfaces[KEY_PRESS_SURFACE_RIGHT] == nullptr){
        printf("Failed to load right image!\n");
        success = false;
    }

    //LOAD EXITING SURFACE
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

void close(){
    //ZWALNIANIE OBRAZKOW
    freeSurfaces();

    //NISZCZENIE OKNA
    freeWindow();

    //OPUSZCZANIE SDL-A
    SDL_Quit();
}

//**********************************************************************************************************************

int main(int argc, char** argv){

    if(!init()){
        error("init");
    }
    else{
        if(!loadMedia()){
            error("load media");
        }
        else{
            //APLIKOWANIE POCZATKOWEGO OBRAZKA
            currentSurface = keyPressSurfaces[KEY_PRESS_SURFACE_DEFAULT];
            updateWindow(currentSurface);

            //GLOWNA PETLA APLIKACJI
            while(!quit){
                //PETLA EVENT-U
                while(SDL_PollEvent(&event) != 0){
                    //PROSBA O ZAMKNIECIE
                    if(event.type == SDL_QUIT){
                        quit = true;
                    }
                    //User presses a key
                    else if(event.type = SDL_KEYDOWN){
                        //Select surfaces based on key press
                        switch(event.key.keysym.sym){
                            case SDLK_UP:
                                currentSurface = keyPressSurfaces[KEY_PRESS_SURFACE_UP];
                                break;

                            case SDLK_DOWN:
                                currentSurface = keyPressSurfaces[KEY_PRESS_SURFACE_DOWN];
                                break;

                            case SDLK_LEFT:
                                currentSurface = keyPressSurfaces[KEY_PRESS_SURFACE_LEFT];
                                break;

                            case SDLK_RIGHT:
                                currentSurface = keyPressSurfaces[KEY_PRESS_SURFACE_RIGHT];
                                break;

                            default:
                                currentSurface = keyPressSurfaces[KEY_PRESS_SURFACE_DEFAULT];
                                break;

                        }
                    }
                }

                updateWindow(currentSurface);
            }
        }
    }

    updateWindow(xOpuszczamySurface);
    SDL_Delay(500);

    close();

    return 0;
}
