//
// Created by Busiu on 16.08.2018.
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

    //Renders texture at given point
    void render (int x, int y, SDL_Rect* clip = nullptr);

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
