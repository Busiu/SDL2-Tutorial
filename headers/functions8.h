//
// Created by Busiu on 15.08.2018.
//

#ifndef SDLTEST_FUNCTIONS8_H
#define SDLTEST_FUNCTIONS8_H

#include <cstdio>
#include <iostream>
#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>

using namespace std;

//Global variables
extern const int SCREEN_HEIGHT;
extern const int SCREEN_WIDTH;
extern bool quit;

extern SDL_Window* window;
extern SDL_Renderer* renderer;
extern SDL_Event event;

//Functions in alphabetical order
bool init();
bool loadMedia();

#endif //SDLTEST_FUNCTIONS8_H
