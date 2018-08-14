//
// Created by Busiu on 15.08.2018.
//

#include "../headers/functions7.h"

//Global variables
const int SCREEN_HEIGHT = 720;
const int SCREEN_WIDTH = 1280;
bool quit = false;

SDL_Window* window;
SDL_Renderer* renderer;
SDL_Event event;

//Main program
int main(int argc, char** argv){
    if(!init()){
        printf("Failed to init SDL & IMG!\n");
    }
    else{
        if(!loadMedia()){
            printf("Failed to load media!\n");
        }
        else{
            //Main loop
            while(!quit){
                //Event loop
                while(SDL_PollEvent(&event) == 0){
                    //User requests to quit
                    if(event.type == SDL_QUIT){
                        quit = true;
                    }
                }

                //Clear screen
                SDL_SetRenderDrawColor(renderer, 0xFF, 0xFF, 0xFF, 0xFF);
                SDL_RenderClear(renderer);

                //Render red filled rectangle
                SDL_Rect rect = {SCREEN_WIDTH / 4, SCREEN_HEIGHT / 4, SCREEN_WIDTH / 2, SCREEN_HEIGHT / 2};
                SDL_SetRenderDrawColor(renderer, 0xFF, 0x00, 0x00, 0xFF);
                SDL_RenderFillRect(renderer, &rect);

                //Render green outlined rectangle
                SDL_Rect outlineRect = {SCREEN_WIDTH / 6, SCREEN_HEIGHT / 6, SCREEN_WIDTH * 2 / 3, SCREEN_HEIGHT * 2 / 3};
                SDL_SetRenderDrawColor(renderer, 0x00, 0xFF, 0x00, 0xFF);
                SDL_RenderDrawRect(renderer, &outlineRect);

                //Render blue line
                SDL_SetRenderDrawColor(renderer, 0x00, 0x00, 0xFF, 0xFF);
                SDL_RenderDrawLine(renderer, 0, SCREEN_HEIGHT / 10, SCREEN_WIDTH * 2 / 3, SCREEN_HEIGHT * 9 / 10);

                //Render vertical line of yellow dots
                SDL_SetRenderDrawColor(renderer, 0xFF, 0xFF, 0x00, 0xFF);
                for(int i = 0; i < SCREEN_HEIGHT; i +=4){
                    SDL_RenderDrawPoint(renderer, SCREEN_WIDTH / 2, i);
                }

                //Update screen
                SDL_RenderPresent(renderer);

            }

            SDL_Delay(500);
        }
    }
}
