//
// Created by Busiu on 17.08.2018.
//

#ifndef SDLTEST_LTEXTURE_H
#define SDLTEST_LTEXTURE_H

#include <cstdio>
#include <iostream>
#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>

using namespace std;

//Actual renderer
extern SDL_Renderer* renderer;

class LTexture {
public:
    //Initializes variables
    LTexture();

    //Deallocates memory
    ~LTexture();

    //Load image at specified path
    bool loadFromFile(string path);

    //Deallocates texture
    void free();

    //Set color modulation
    void setColor(Uint8 red, Uint8 green, Uint8 blue);

    //Set blending
    void setBlendMode(SDL_BlendMode blending);

    //Set alpha modulation
    void setAlpha(Uint8 alpha);

    //Renders texture at given point
    void render (int x, int y, SDL_Rect* clip = nullptr, double angle = 0.0,
                 SDL_Point* center = nullptr, SDL_RendererFlip flip = SDL_FLIP_NONE);

    //Gets image dimensions
    int getWidth();
    int getHeight();

private:
    //The actual hardware texture
    SDL_Texture* texture;

    //Image dimensions
    int width;
    int height;
};

#endif //SDLTEST_LTEXTURE_H