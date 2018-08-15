#include <iostream>
#include "SDL2/SDL.h"
#include <cstdio>

using namespace std;

const int SCREEN_WIDTH = 640;
const int SCREEN_HEIGHT = 480;

int main(int argc, char * args[]){
    SDL_Window* window = nullptr;
    SDL_Surface* surface = nullptr;

    //INICJALIZACJA
    if(SDL_Init(SDL_INIT_VIDEO) < 0){
        cout << "Problem z inicjalizacja! Error:" << SDL_GetError() << endl;
    }
    else{
        //TWORZENIE OKNA
        window = SDL_CreateWindow("SDLTest", SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED,
                SCREEN_WIDTH, SCREEN_HEIGHT, SDL_WINDOW_SHOWN);

        if(window == nullptr){
            cout << "Okno nie moglo zostac utworzone" << endl;
        }
        else{
            surface = SDL_GetWindowSurface(window);
            SDL_FillRect(surface, nullptr, SDL_MapRGB(surface->format, 0xFF, 0xFF, 0xFF));
            SDL_UpdateWindowSurface(window);
            SDL_Delay(10000);
        }
    }

    SDL_DestroyWindow(window);
    SDL_Quit();

    return 0;
}