//
// Created by Busiu on 20.08.2018.
//

#ifndef SDLTEST_LBUTTON_H
#define SDLTEST_LBUTTON_H

#include <cstdio>
#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>

#include "buttonInfo.h"
#include "LTexture.h"

extern SDL_Rect* spriteClips;
extern LTexture buttonSpriteSheetTexture;

class LButton {
public:
    //Initialize internal variables
    LButton();

    //Sets top left position
    void setPosition(int x, int y);

    //Handles mouse event
    void handleEvent(SDL_Event* e);

    //Shows button sprite
    void render();

private:
    //Top left position
    SDL_Point position;

    //Currently used global sprite
    LButtonSprite currentSprite;
};

#endif //SDLTEST_LBUTTON_H