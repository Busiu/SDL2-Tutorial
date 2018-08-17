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

const int WALKING_ANIMATION_FRAMES = 4;
const int FRAME_DURATION = 20;
SDL_Rect* spriteClips;
LTexture spriteSheetTexture;
int frame = 0;

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

                //Render current frame
                SDL_Rect* currentClip = &spriteClips[frame / FRAME_DURATION];
                spriteSheetTexture.render((SCREEN_WIDTH - currentClip->w) / 2, (SCREEN_HEIGHT - currentClip->h) / 2, currentClip);

                //Update screen
                SDL_RenderPresent(renderer);

                //Go to next frame
                frame++;

                //Cycle animation
                if(frame / FRAME_DURATION >= WALKING_ANIMATION_FRAMES){
                    frame = 0;
                }
            }
        }
    }

    close();

    return 0;
}