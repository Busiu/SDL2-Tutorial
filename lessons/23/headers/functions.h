//
// Created by Busiu on 26.08.2018.
//

#ifndef SDLTEST_FUNCTIONS_H
#define SDLTEST_FUNCTIONS_H

#include <stdio.h>
#include <string>
#include <sstream>
#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>
#include <SDL2/SDL_ttf.h>

#include "LTexture.h"
#include "LTimer.h"

using namespace std;

//Global variables
extern const int SCREEN_HEIGHT;
extern const int SCREEN_WIDTH;
extern bool quit;

extern SDL_Window* window;
extern SDL_Renderer* renderer;

extern LTexture startPromptTexture;
extern LTexture pausePromptTexture;
extern LTexture timeTextTexture;
extern TTF_Font* font;

//Functions in alphabetical order
void close();
bool init();
bool loadMedia();

#endif //SDLTEST_FUNCTIONS_H
