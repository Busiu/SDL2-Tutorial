//
// Created by Busiu on 20.08.2018.
//

#include "../headers/LButton.h"

LButton::LButton()
{
    position.x = 0;
    position.y = 0;

    currentSprite = BUTTON_SPRITE_MOUSE_OUT;
}

void LButton::setPosition(int x, int y)
{
    position.x = x;
    position.y = y;
}

void LButton::handleEvent(SDL_Event *e)
{
    //If mouse event happened
    if(e->type == SDL_MOUSEMOTION || e->type == SDL_MOUSEBUTTONUP || e->type == SDL_MOUSEBUTTONDOWN)
    {
        //Get mouse position
        int x, y;
        SDL_GetMouseState(&x, &y);

        //Check if mouse is in button
        bool inside = true;

        //Mouse is left of the button
        if(x < position.x)
        {
            inside = false;
        }
        //Mouse is right of the button
        if(x > position.x + BUTTON_WIDTH)
        {
            inside = false;
        }
        //Mouse above the button
        if(y < position.y)
        {
            inside = false;
        }
        //Mouse below the button
        if(y > position.y + BUTTON_HEIGHT)
        {
            inside = false;
        }

        //Mouse is outside the button
        if(!inside)
        {
            currentSprite = BUTTON_SPRITE_MOUSE_OUT;
        }
        //Mouse is inside the button
        else
        {
            //Set mouse over sprite
            switch(e->type)
            {
                case SDL_MOUSEMOTION:
                currentSprite = BUTTON_SPRITE_MOUSE_OVER_MOTION;
                break;

                case SDL_MOUSEBUTTONUP:
                currentSprite = BUTTON_SPRITE_MOUSE_UP;
                break;

                case SDL_MOUSEBUTTONDOWN:
                currentSprite = BUTTON_SPRITE_MOUSE_DOWN;
                break;
            }
        }
    }
}

void LButton::render()
{
    //Show current button sprite
    buttonSpriteSheetTexture.render(position.x, position.y, &spriteClips[currentSprite]);
}