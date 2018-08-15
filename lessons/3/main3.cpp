//
// Created by Busiu on 23.07.2018.
//

#include <iostream>
#include <SDL2/SDL.h>
#include <cstdio>

using namespace std;

//ZMIENNE GLOBALNE
const int SCREEN_HEIGHT = 480;
const int SCREEN_WIDTH = 640;
bool quit = false;

SDL_Window* window = nullptr;
SDL_Surface* screenSurface = nullptr;
SDL_Surface* xdSurface = nullptr;
SDL_Surface* xOpuszczamySurface = nullptr;
SDL_Event event;

//FUNKCJE GLOBALNE
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

bool loadMedia(){
    //FLAGA POWODZENIA
    bool success = true;

    //LADOWANIE OBRAZKA "xD"
    xdSurface = SDL_LoadBMP("../assets/images/bmp/XD.bmp");
    if(xdSurface == nullptr){
        cout << "Nie mozna pobrac obrazka. Error: " << SDL_GetError() << endl;
        success = false;
    }

    //LADOWANIE OBRAZKA "xOpuszczamy"
    xOpuszczamySurface = SDL_LoadBMP("../assets/images/bmp/xOpuszczamy.bmp");
    if(xOpuszczamySurface == nullptr){
        cout << "Nie mozna pobrac obrazka. Error: " << SDL_GetError() << endl;
        success = false;
    }

    return success;
}

void close(){
    //ZWALNIANIE OBRAZKA
    SDL_FreeSurface(xdSurface);
    xdSurface = nullptr;

    //NISZCZENIE OKNA
    SDL_DestroyWindow(window);
    window = nullptr;

    //OPUSZCZANIE SDL-A
    SDL_Quit();
}

int main(int argc, char** argv){

    if(!init()){
        error("init");
    }
    else{
        if(!loadMedia()){
            error("load media");
        }
        else{
            //APLIKOWANIE OBRAZKA
            SDL_BlitSurface(xdSurface, nullptr, screenSurface, nullptr);
            SDL_UpdateWindowSurface(window);

            //GLOWNA PETLA APLIKACJI
            while(!quit){
                //PETLA EVENT-U
                while(SDL_PollEvent(&event) != 0){
                    //PROSBA O ZAMKNIECIE
                    if(event.type == SDL_QUIT){
                        quit = true;
                    }
                }
            }
        }
    }

    SDL_BlitSurface(xOpuszczamySurface, nullptr, screenSurface, nullptr);
    SDL_UpdateWindowSurface(window);
    SDL_Delay(500);

    close();

    return 0;
}