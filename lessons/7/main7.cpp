//
// Created by Busiu on 30.07.2018.
//

#include "../../headers/enums.h"
#include "../headers/7/functions7.h"

//Global variables
const int SCREEN_HEIGHT = 720;
const int SCREEN_WIDTH = 1280;
bool quit = false;

SDL_Window* window;
SDL_Renderer* renderer;
SDL_Texture* defaultTexture;
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
                SDL_RenderClear(renderer);

                //Render texture to screen
                SDL_RenderCopy(renderer, defaultTexture, nullptr, nullptr);

                //Update screen
                SDL_RenderPresent(renderer);
            }

            SDL_Delay(500);
        }
    }
}