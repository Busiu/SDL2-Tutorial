//
// Created by Busiu on 16.08.2018.
//

#include "headers/functions.h"

//Global variables
const int SCREEN_HEIGHT = 720;
const int SCREEN_WIDTH = 1280;
bool quit = false;

SDL_Window* window = nullptr;
SDL_Renderer* renderer = nullptr;
SDL_Event event;

SDL_Rect spriteClips[4];
LTexture spriteSheetTexture;

int main(int argc, char** argv){

    if(!init()){
        printf("Failed to init SDL & IMG!\n");
    }
    else{
        if(!loadMedia()){
            printf("Failed to load media!\n");
        }
        else{
            while(!quit) {
                //Handle events in queue
                while (SDL_PollEvent(&event) != 0) {
                    //User requests quit
                    if (event.type == SDL_QUIT) {
                        quit = true;
                    }
                }

                //Clear screen
                SDL_SetRenderDrawColor(renderer, 0xFF, 0xFF, 0xFF, 0xFF);
                SDL_RenderClear(renderer);

                //Render top left sprite
                spriteSheetTexture.render(0, 0, &spriteClips[0]);

                //Render top right sprite
                spriteSheetTexture.render(SCREEN_WIDTH - spriteClips[1].w, 0, &spriteClips[1]);

                //Render top left sprite
                spriteSheetTexture.render(0, SCREEN_HEIGHT - spriteClips[2].h, &spriteClips[2]);

                //Render top left sprite
                spriteSheetTexture.render(SCREEN_WIDTH - spriteClips[3].w, SCREEN_HEIGHT - spriteClips[3].h, &spriteClips[3]);

                //Update screen
                SDL_RenderPresent(renderer);
            }
        }
    }

    close();

    return 0;
}

