//
// Created by Busiu on 25.07.2018.
//

#ifndef SDLTEST_FUNCTIONS4_H
#define SDLTEST_FUNCTIONS4_H

#include <cstdio>
#include <iostream>
#include <SDL2/SDL.h>

#include "enums.h"

using namespace std;

//Global variables
extern const int SCREEN_HEIGHT;
extern const int SCREEN_WIDTH;
extern bool quit;

extern SDL_Window* window;
extern SDL_Surface* screenSurface;
extern SDL_Surface* currentSurface;
extern SDL_Surface* xOpuszczamySurface;
extern SDL_Surface* keyPressSurfaces[KEY_PRESS_SURFACE_TOTAL];
extern SDL_Event event;

//Functions in alphabetical order
void close();
void freeSurface(SDL_Surface* surface);
void freeWindow(SDL_Window* window);
bool init();
SDL_Surface* loadSurface(string path);
bool loadMedia();
void updateWindow(SDL_Surface* surface);

#endif //SDLTEST_FUNCTIONS4_H
