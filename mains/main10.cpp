//
// Created by Busiu on 15.08.2018.
//

#include "../headers/10/functions10.h"

//Global variables
const int SCREEN_HEIGHT = 720;
const int SCREEN_WIDTH = 1280;
bool quit = false;

SDL_Window* window = nullptr;
SDL_Renderer* renderer = nullptr;
SDL_Event event;

LTexture fooTexture;
LTexture backgroundTexture;

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

                //Render background texture
                backgroundTexture.render(0, 0);

                //Render Foo' to the screen
                fooTexture.render(240, 190);

                //Update screen
                SDL_RenderPresent(renderer);
            }
        }
    }

    close();

    return 0;
}
