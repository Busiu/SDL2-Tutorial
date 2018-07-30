//
// Created by Busiu on 30.07.2018.
//

#ifndef SDLTEST_FUNCTIONS7_H
#define SDLTEST_FUNCTIONS7_H

#include <cstdio>
#include <iostream>
#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>

#include "enums.h"

using namespace std;

//Global variables
extern const int SCREEN_HEIGHT;
extern const int SCREEN_WIDTH;
extern bool quit;

extern SDL_Window* window;
extern SDL_Renderer* renderer;
extern SDL_Texture* defaultTexture;
extern SDL_Event event;

//Functions in alphabetical order
void close();
bool init();
bool loadMedia();
SDL_Surface* loadSurface(string path);
SDL_Texture* loadTexture(string path);

#endif //SDLTEST_FUNCTIONS7_H
