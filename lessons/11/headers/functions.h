//
// Created by Busiu on 16.08.2018.
//

#ifndef SDLTEST_FUNCTIONS_H
#define SDLTEST_FUNCTIONS_H

#include <cstdio>
#include <iostream>
#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>

#include "LTexture.h"

using namespace std;

//Global variables
extern const int SCREEN_HEIGHT;
extern const int SCREEN_WIDTH;
extern bool quit;

extern SDL_Window* window;
extern SDL_Renderer* renderer;

extern SDL_Rect spriteClips[4];
extern LTexture spriteSheetTexture;

//Functions in alphabetical order
void close();
bool init();
bool loadMedia();

#endif //SDLTEST_FUNCTIONS_H
