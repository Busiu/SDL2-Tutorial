//
// Created by Busiu on 15.08.2018.
//

#include "../../headers/10/LTexture.h"

LTexture::LTexture() {
    //Initialize
    texture = nullptr;
    width = 0;
    height = 0;
}

LTexture::~LTexture() {
    //Deallocate
    free();
}

bool LTexture::loadFromFile(string path) {
    //Get rid of preexisting texture
    free();

    //The final texture
    SDL_Texture* newTexture = nullptr;

    //Load image at specified path
    SDL_Surface* loadedSurface = IMG_Load(path.c_str());
    if(loadedSurface == nullptr){
        printf("Failed to load image %s! SDL_image error: %s\n", path.c_str(), IMG_GetError());
    }
    else{
        //Color key image
        SDL_SetColorKey(loadedSurface, SDL_TRUE, SDL_MapRGB(loadedSurface->format, 0x00, 0xFF, 0xFF));

        //Create texture from surface pixels
        newTexture = SDL_CreateTextureFromSurface(renderer, loadedSurface);
        if(newTexture == nullptr){
            printf("Failed to create texture from %s! SDL_image error: %s\n", path.c_str(), SDL_GetError());
        }
        else{
            //Get image dimensions
            width = loadedSurface->w;
            height = loadedSurface->h;
        }

        //Get rid of old loaded surface
        SDL_FreeSurface(loadedSurface);
    }

    //Return success
    texture = newTexture;
    return texture != nullptr;
}

void LTexture::free(){
    //Free texture if it exists
    if(texture != nullptr){
        SDL_DestroyTexture(texture);
        texture = nullptr;
        width = 0;
        height = 0;
    }
}

void LTexture::render(int x, int y){
    //Set rendering space and render to screen
    SDL_Rect renderQuad = {x, y, width, height};
    SDL_RenderCopy(renderer, texture, nullptr, &renderQuad);
}

int LTexture::getWidth() {
    return width;
}

int LTexture::getHeight(){
    return height;
}
