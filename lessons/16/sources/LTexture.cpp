//
// Created by Busiu on 20.08.2018.
//

#include "../headers/LTexture.h"

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

bool LTexture::loadFromRenderedText(string textureText, SDL_Color textColor) {
    //Get rid of preexisting texture
    free();

    //Render text surface
    SDL_Surface* textSurface = TTF_RenderText_Solid(font, textureText.c_str(), textColor);
    if(textSurface == nullptr){
        printf("Failed to render text surface! Error: %s\n", SDL_GetError());
    }
    else{
        //Create texture from surface pixels
        texture = SDL_CreateTextureFromSurface(renderer, textSurface);
        if(texture == nullptr){
            printf("Failed to create texture from rendered text! Error: %s\n", SDL_GetError());
        }
        else{
            //Get image dimensions
            width = textSurface->w;
            height = textSurface->h;
        }

        //Get rid of old surface
        SDL_FreeSurface(textSurface);
    }

    //Return success
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

void LTexture::setColor(Uint8 red, Uint8 green, Uint8 blue){
    //Modulate texture
    SDL_SetTextureColorMod(texture, red, green, blue);
}

void LTexture::setBlendMode(SDL_BlendMode blending){
    //Set blending function
    SDL_SetTextureBlendMode(texture, blending);
}

void LTexture::setAlpha(Uint8 alpha){
    //Modulate texture alpha
    SDL_SetTextureAlphaMod(texture, alpha);
}

void LTexture::render(int x, int y, SDL_Rect* clip, double angle, SDL_Point* center, SDL_RendererFlip flip){
    //Set rendering space and render to screen
    SDL_Rect renderQuad = {x, y, width, height};

    //Set clip rendering dimensions
    if(clip != nullptr){
        renderQuad.w = clip->w;
        renderQuad.h = clip->h;
    }

    //Render to screen
    SDL_RenderCopyEx(renderer, texture, clip, &renderQuad, angle, center, flip);
}

int LTexture::getWidth() {
    return width;
}

int LTexture::getHeight(){
    return height;
}